#include "Globals.h"
#include "Application.h"
#include "ModuleDebug.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleEnemies.h"
#include "ModuleEnemies_Ground.h"
#include "ModuleFadeToBlack.h"
#include "ModuleWelcome.h"
#include "ModuleCollision.h"
#include "ModuleHallOfAces.h"
#include "ModuleAudio.h"


// Reference at https://youtu.be/6OlenbCC4WI?t=382

ModuleDebug::ModuleDebug()
{
	ground = { 0, 0, 352, 3705 };

}

ModuleDebug::~ModuleDebug()
{}

// Load assets
bool ModuleDebug::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("assets/textures/TileMap-LvL1.png");
	App->enemies->Enable();
	App->enemies_ground->Enable();
	App->audio->Init();
	App->player->speed = 0;
	App->collision->debug = true;
	return ret;
}

// Load assets
bool ModuleDebug::CleanUp()
{


	App->player->Disable();
	App->player2->Disable();

	App->textures->Unload(graphics);

	App->enemies->CleanUp();
	App->enemies_ground->CleanUp();

	LOG("Unloading Debug level");

	App->player->speed = 1;


	return true;
}

// Update: draw background
update_status ModuleDebug::Update()
{
	// Players

	if (App->input->keyboard[SDL_SCANCODE_1] == KEY_STATE::KEY_DOWN) {
		App->player->Enable();
	}
	if (App->input->keyboard[SDL_SCANCODE_2] == KEY_STATE::KEY_DOWN) {
		App->player2->Enable();
	}
	// Enemies

	if (App->input->keyboard[SDL_SCANCODE_3] == KEY_STATE::KEY_DOWN) {
		App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY, App->player->position.x, App->player->position.y-200);
	}
	if (App->input->keyboard[SDL_SCANCODE_4] == KEY_STATE::KEY_DOWN) {
		App->enemies->AddEnemy(ENEMY_TYPES::GREENSHIP, App->player->position.x+50, App->player->position.y - 100);
	}
	if (App->input->keyboard[SDL_SCANCODE_5] == KEY_STATE::KEY_DOWN) {
		App->enemies_ground->AddEnemy(ENEMY_TYPES::TURRET, App->player->position.x, App->player->position.y - 100);
	}
	if (App->input->keyboard[SDL_SCANCODE_6] == KEY_STATE::KEY_DOWN) {
		App->enemies->AddEnemy(ENEMY_TYPES::POWERUP_SHIP, App->player->position.x, App->player->position.y - 100);
	}
	if (App->input->keyboard[SDL_SCANCODE_7] == KEY_STATE::KEY_DOWN) {
		App->enemies->AddEnemy(ENEMY_TYPES::POWERUP, App->player->position.x, App->player->position.y - 100);
	}
	 // PowerUp

	if (App->input->keyboard[SDL_SCANCODE_O] == KEY_STATE::KEY_DOWN) {
		if (App->player->shoot_type != SHOOT_TYPE::LASER)
		App->player->shoot_type = SHOOT_TYPE::LASER;
		else
			App->player->shoot_type = SHOOT_TYPE::STANDARD;
	}
	if (App->input->keyboard[SDL_SCANCODE_P] == KEY_STATE::KEY_DOWN) {
		if (App->player->shoot_type != SHOOT_TYPE::VULCAN)
			App->player->shoot_type = SHOOT_TYPE::VULCAN;
		else
			App->player->shoot_type = SHOOT_TYPE::STANDARD;

	}
	// Win/Lose

	if (App->input->keyboard[SDL_SCANCODE_F6] == KEY_STATE::KEY_DOWN) {
		App->fade->FadeToBlack(this, App->welcome, 2.0f);
	}


	if (App->input->keyboard[SDL_SCANCODE_F1]) {
		App->fade->FadeToBlack(this, App->welcome, 2.0f);
	}

	App->render->Blit(graphics, 0, -3449, &ground);

	return UPDATE_CONTINUE;
}