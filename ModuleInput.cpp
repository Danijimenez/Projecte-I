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
			if (i == 0) {
				controller_1 = SDL_GameControllerOpen(i);
				mapping = SDL_GameControllerMapping(controller_1);
				SDL_Log("Controller %i is mapped as \"%s\".", i, mapping);
				SDL_free(mapping);
			}
			if (i == 1) {
				controller_2 = SDL_GameControllerOpen(i);
				mapping = SDL_GameControllerMapping(controller_2);
				SDL_Log("Controller %i is mapped as \"%s\".", i, mapping);
				SDL_free(mapping);
			}

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
			if (SDL_GameControllerGetButton(controller_1, button[i]))
			{
				if (contrkey1[i] == KEY_IDLE)
					contrkey1[i] = KEY_DOWN;
				else
					contrkey1[i] = KEY_REPEAT;
			}
			else
			{
				if (contrkey1[i] == KEY_REPEAT || contrkey1[i] == KEY_DOWN)
					contrkey1[i] = KEY_UP;
				else
					contrkey1[i] = KEY_IDLE;
			}
		}

		for (int i = 0; i < 15; ++i)
		{
			if (SDL_GameControllerGetButton(controller_2, button[i]))
			{
				if (contrkey2[i] == KEY_IDLE)
					contrkey2[i] = KEY_DOWN;
				else
					contrkey2[i] = KEY_REPEAT;
			}
			else
			{
				if (contrkey2[i] == KEY_REPEAT || contrkey1[i] == KEY_DOWN)
					contrkey2[i] = KEY_UP;
				else
					contrkey2[i] = KEY_IDLE;
			}
		}
	
	if (contrkey1[SDL_CONTROLLER_BUTTON_START] || keyboard[SDL_SCANCODE_ESCAPE])
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

