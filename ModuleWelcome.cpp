#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleWelcome.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleLevel1.h"
#include "ModuleLevel2.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleAudio.h"
#include "ModuleDebug.h"
#include "ModuleWelcomeAssets.h"
#include "ModuleEnemies.h"
#include "ModuleEnemies_Ground.h"


// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleWelcome::ModuleWelcome()
{
	welcome = { 0, 0, 224, 256 };
}

ModuleWelcome::~ModuleWelcome()
{}

// Load assets
bool ModuleWelcome::Start()
{
	LOG("Loading welcome scene");
	App->stop_music = false;
	App->welcomeassets->Enable();
	graphics = App->textures->Load("assets/textures/welcome.png");
	App->render->camera.x = -25;
	App->render->camera.y = 0;

	player1 = false;
	player2 = false;

	return true;
}

// UnLoad assets
bool ModuleWelcome::CleanUp()
{
	LOG("Unloading ken scene");

	App->textures->Unload(graphics);
	App->welcomeassets->Disable();


	return true;
}

// Update: draw background
update_status ModuleWelcome::Update()
{


	// Draw everything --------------------------------------

	App->render->Blit(graphics, 0, 0, &welcome, false);


	if (App->input->keyboard[SDL_SCANCODE_1] || App->input->contrkey[SDL_CONTROLLER_BUTTON_A] == KEY_STATE::KEY_DOWN) {
		App->fade->FadeToBlack(this, App->level_2, 2.0f);
//		App->level_1->Disable();
		player1 = true;
	}
	if (App->input->keyboard[SDL_SCANCODE_2]) {
		App->fade->FadeToBlack(this, App->level_2, 2.0f);
//		App->level_1->Disable();
		player2 = true;
	}
	if (App->input->keyboard[SDL_SCANCODE_3]) {
		App->fade->FadeToBlack(this, App->level_2, 2.0f);
//		App->level_1->Disable();
		player1 = true;
		player2 = true;
	}

	if (App->input->keyboard[SDL_SCANCODE_F5]) {
		App->fade->FadeToBlack(this, App->debug, 2.0f);
	}

	if (App->render->camera.y > 3400) {
		App->render->camera.y = 0;
	}


	return UPDATE_CONTINUE;
}