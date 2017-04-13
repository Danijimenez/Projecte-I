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
#include "ModuleEnemySpaceship.h"
#include "ModuleEnemies.h"

// Reference at https://youtu.be/6OlenbCC4WI?t=382

ModuleLevel1::ModuleLevel1()
{
	ground = {0, 0, 402, 3994};

}

ModuleLevel1::~ModuleLevel1()
{}

// Load assets
bool ModuleLevel1::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("assets/textures/TileMap-LvL1.png");
	App->audio->Play("assets/music/1-4.ogg");
	App->stop_music = true;
	App->render->camera.x = -64;
	App->render->camera.y = 0;

	App->player->Enable();


	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY, 150, -20);
	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY, 320, -30);
	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY, 300, -10);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET, 150, -10);

	return ret;
}

// Load assets
bool ModuleLevel1::CleanUp()
{
	App->player->Disable();
//	App->spaceship->Disable();

	App->textures->Unload(graphics);

	App->audio->Stop();


	LOG("Unloading Level 1");

	return true;
}

// Update: draw background
update_status ModuleLevel1::Update()
{
	int speed = 1;
	// Draw everything --------------------------------------	
	if (App->input->keyboard[SDL_SCANCODE_F2] == KEY_STATE::KEY_DOWN) {
		App->player->Enable();
	}


	App->render->Blit(graphics, 0, -3500, &ground);

	//Scroll

	App->render->camera.y += speed;

	if (App->input->keyboard[SDL_SCANCODE_SPACE]) {
		App->fade->FadeToBlack(this, App->level_2, 2.0f);
	}

	return UPDATE_CONTINUE;
} 