#include "Globals.h"
#include "Application.h"
#include "ModuleInput.h"
#include "SDL/include/SDL.h"

ModuleInput::ModuleInput() : Module()
{
	for (uint i = 0; i < MAX_KEYS; ++i)
		keyboard[i] = KEY_IDLE;
}

// Destructor
ModuleInput::~ModuleInput()
{
}

// Called before render is available
bool ModuleInput::Init()
{
	LOG("Init SDL input event system");
	bool ret = true;
	SDL_Init(0);

	if (SDL_InitSubSystem(SDL_INIT_EVENTS) < 0)
	{
		LOG("SDL_EVENTS could not initialize! SDL_Error: %s\n", SDL_GetError());
		ret = false;
	}

	int i;

	SDL_Init(SDL_INIT_GAMECONTROLLER);

	for (i = 0; i < SDL_NumJoysticks(); ++i) {
		if (SDL_IsGameController(i)) {
			char *mapping;
			SDL_Log("Index \'%i\' is a compatible controller, named \'%s\'", i, SDL_GameControllerNameForIndex(i));
			controller = SDL_GameControllerOpen(i);
			mapping = SDL_GameControllerMapping(controller);
			SDL_Log("Controller %i is mapped as \"%s\".", i, mapping);
			SDL_free(mapping);
		}
		else {
			SDL_Log("Index \'%i\' is not a compatible controller.", i);

		}
	}



	return ret;
}

// Called every draw update
update_status ModuleInput::PreUpdate()
{
	SDL_PumpEvents();

	const Uint8* keys = SDL_GetKeyboardState(NULL);

	for (int i = 0; i < MAX_KEYS; ++i)
	{
		if (keys[i] == 1)
		{
			if (keyboard[i] == KEY_IDLE)
				keyboard[i] = KEY_DOWN;
			else
				keyboard[i] = KEY_REPEAT;
		}
		else
		{
			if (keyboard[i] == KEY_REPEAT || keyboard[i] == KEY_DOWN)
				keyboard[i] = KEY_UP;
			else
				keyboard[i] = KEY_IDLE;
		}
	}

	int ctrkeys = SDL_GameControllerEventState(NULL);

	for (int i = 0; i < 15; ++i)
	{
		if (SDL_GameControllerGetButton(controller, button[i]))
		{
			if (contrkey[i] == KEY_IDLE)
				contrkey[i] = KEY_DOWN;
			else
				contrkey[i] = KEY_REPEAT;
		}
		else
		{
			if (contrkey[i] == KEY_REPEAT || contrkey[i] == KEY_DOWN)
				contrkey[i] = KEY_UP;
			else
				contrkey[i] = KEY_IDLE;
		}
	}

	if (contrkey[SDL_CONTROLLER_BUTTON_START] || keyboard[SDL_SCANCODE_ESCAPE])
		return update_status::UPDATE_STOP;


	return update_status::UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleInput::CleanUp()
{
	LOG("Quitting SDL input event subsystem");
	SDL_QuitSubSystem(SDL_INIT_EVENTS);
	return true;
}


int test_haptic(SDL_Joystick * joystick) {
	SDL_Haptic *haptic;
	SDL_HapticEffect effect;
	int effect_id;

	// Open the device
	haptic = SDL_HapticOpenFromJoystick(joystick);
	if (haptic == NULL) return -1; // Most likely joystick isn't haptic

								   // See if it can do sine waves
	if ((SDL_HapticQuery(haptic) & SDL_HAPTIC_SINE) == 0) {
		SDL_HapticClose(haptic); // No sine effect
		return -1;
	}

	// Create the effect
	SDL_memset(&effect, 0, sizeof(SDL_HapticEffect)); // 0 is safe default
	effect.type = SDL_HAPTIC_SINE;
	effect.periodic.direction.type = SDL_HAPTIC_POLAR; // Polar coordinates
	effect.periodic.direction.dir[0] = 18000; // Force comes from south
	effect.periodic.period = 1000; // 1000 ms
	effect.periodic.magnitude = 20000; // 20000/32767 strength
	effect.periodic.length = 5000; // 5 seconds long
	effect.periodic.attack_length = 1000; // Takes 1 second to get max strength
	effect.periodic.fade_length = 1000; // Takes 1 second to fade away

										// Upload the effect
	effect_id = SDL_HapticNewEffect(haptic, &effect);

	// Test the effect
	SDL_HapticRunEffect(haptic, effect_id, 1);
	SDL_Delay(5000); // Wait for the effect to finish

					 // We destroy the effect, although closing the device also does this
	SDL_HapticDestroyEffect(haptic, effect_id);

	// Close the device
	SDL_HapticClose(haptic);

	return 0; // Success
}