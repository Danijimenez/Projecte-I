#include "Globals.h"
#include "Application.h"
#include "ModuleLevel1.h"
#include "ModuleLevel2.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include"ModulePlayer.h"
#include "ModuleWelcome.h"
#include "ModuleAudio.h"
#include "ModuleHallOfAces.h"
#include "ModuleEnemySpaceship.h"

// Reference at https://youtu.be/6OlenbCC4WI?t=382

ModuleLevel2::ModuleLevel2()
{

	ground = { 0, 0, 352, 4755 };

}

ModuleLevel2::~ModuleLevel2()
{}

// Load assets
bool ModuleLevel2::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("assets/textures/TileMap-LvL2.png");
	App->audio->Play("assets/music/2-7.ogg");
	App->stop_music = true;
	App->render->camera.x = -20;
	App->render->camera.y = 450;


//	App->player->Enable();

	return ret;
}

// Load assets
bool ModuleLevel2::CleanUp()
{
//	App->player->Disable();

	App->textures->Unload(graphics);

	App->audio->Stop();
	

	LOG("Unloading Level 2");

	return true;
}

// Update: draw background
update_status ModuleLevel2::Update()
{
	if (App->input->keyboard[SDL_SCANCODE_F2] == KEY_STATE::KEY_DOWN) {
		App->player->Enable();
	}
	if (App->input->keyboard[SDL_SCANCODE_F3] == KEY_STATE::KEY_DOWN) {
		App->spaceship->Enable();
	}

	App->render->Blit(graphics, 0, -4500, &ground);


	if (App->input->keyboard[SDL_SCANCODE_SPACE]) {
		App->fade->FadeToBlack(this, App->HallOfAces, 2.0f);

	}

	return UPDATE_CONTINUE;
}