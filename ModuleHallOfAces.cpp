#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleHallOfAces.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleWelcome.h"
#include "ModulePlayer.h"
#include "ModuleAudio.h"
#include "ModuleEnemies.h"
#include "ModuleEnemies_Ground.h"
#include "ModuleLevel1.h"
#include "ModuleParticles.h"
#include "ModuleCollision.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleHallOfAces::ModuleHallOfAces()
{
	HallOfAces = { 0, 0, 224, 256 };
}

ModuleHallOfAces::~ModuleHallOfAces()
{}

// Load assets
bool ModuleHallOfAces::Start()
{
	LOG("Loading Hall of Aces scene");

	graphics = App->textures->Load("assets/textures/hall_of_aces.png");

	App->stop_music = true;
	App->audio->Play("assets/music/hall_of_aces.ogg");
	App->render->camera.x = 0;
	App->render->camera.y = 0;

	return true;
}

// UnLoad assets
bool ModuleHallOfAces::CleanUp()
{
	LOG("Unloading Hall of Aces scene");

	App->textures->Unload(graphics);

	return true;
}

// Update: draw background
update_status ModuleHallOfAces::Update()
{


	// Draw everything --------------------------------------
	App->render->Blit(graphics, 0, 0, &HallOfAces);


	if (App->input->keyboard[SDL_SCANCODE_SPACE] || App->input->contrkey[SDL_CONTROLLER_BUTTON_A] == KEY_STATE::KEY_DOWN) {
		App->fade->FadeToBlack(this, App->welcome, 2.0f);

	}
	return UPDATE_CONTINUE;
}
