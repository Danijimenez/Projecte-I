#include "Globals.h"
#include "Application.h"
#include "ModuleLevel1.h"
#include "ModuleLevel2.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include"ModulePlayer.h"
#include"ModulePlayer2.h"
#include "ModuleWelcome.h"
#include "ModuleAudio.h"
#include "ModuleEnemySpaceship.h"
#include "ModuleEnemies.h"
#include "ModuleCollision.h"
#include "ModuleEnemies_Ground.h"
#include "ModuleLevel1(assets).h"
#include "ModuleHallOfAces.h"

// Reference at https://youtu.be/6OlenbCC4WI?t=382

ModuleLevel1::ModuleLevel1()
{
	ground = {0, 0, 352, 3705};

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

	App->level_1_assets->Enable();

	App->stop_music = true;
	App->render->camera.x = -176;
	App->render->camera.y = 160;

	App->collision->debug = false;

	if (App->welcome->player1) {
		App->player->Enable();
	}
	if (App->welcome->player2) {
		App->player2->Enable();
	}

	App->player->speed = 1;

	top_pos = App->render->camera.y-10;
	bottom_pos = App->render->camera.y + App->render->camera.h;

	top = App->collision->AddCollider({ 0, top_pos , 352 ,10 }, COLLIDER_WALL_UP);
	bottom = App->collision->AddCollider({ 0, bottom_pos , 352 ,10 }, COLLIDER_WALL_DOWN);


	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY, 0, -100);
	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY, 181, -300);
	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY, 162, -100);

	App->enemies_ground->AddEnemy(ENEMY_TYPES::BASICENEMY, 67, -1535);	//XP Box

//	App->enemies_ground->AddEnemy(ENEMY_TYPES::TURRET, 48, -337);

	App->enemies_ground->AddEnemy(ENEMY_TYPES::TURRET, 67, -1535);	//XP Box
	App->enemies_ground->AddEnemy(ENEMY_TYPES::TURRET, 131, -1563);	//XP Box

	App->enemies_ground->AddEnemy(ENEMY_TYPES::TURRET, 230, -1611);	//XP Box
	App->enemies_ground->AddEnemy(ENEMY_TYPES::TURRET, 294, -1643);	//XP Box

//	App->enemies_ground->AddEnemy(ENEMY_TYPES::TURRET, 38, -578);	//Missile Box

//	App->enemies->AddEnemy(ENEMY_TYPES::POWERUP, 150, 100);


//	App->enemies->AddEnemy(ENEMY_TYPES::POWERUP_SHIP, 75, 0);


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
	float speed = 0.5;
	// Draw everything --------------------------------------	

	top_pos -= speed;
	bottom_pos -= speed;

	top->SetPos(0, top_pos);
	bottom->SetPos(0, bottom_pos);

	App->render->Blit(graphics, 0, -3449, &ground);

	if (!App->player->living && !App->player2->living)	{
//		App->fade->FadeToBlack(this, App->HallOfAces, 2.0f);
	}

	//Scroll

	App->render->camera.y += speed*SCREEN_SIZE;

	if (App->input->keyboard[SDL_SCANCODE_SPACE]) {
		App->fade->FadeToBlack(this, App->level_2, 2.0f);
	}

	if (App->input->keyboard[SDL_SCANCODE_F1]) {
		App->fade->FadeToBlack(this, App->welcome, 2.0f);
	}


	if (App->input->keyboard[SDL_SCANCODE_1]) {
		App->render->camera.y +=0;
		App->render->camera.y += 0;
	}


	return UPDATE_CONTINUE;
} 