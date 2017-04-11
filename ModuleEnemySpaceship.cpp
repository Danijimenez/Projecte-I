#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleEnemySpaceship.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"

ModuleEnemySpaceship::ModuleEnemySpaceship()
{

	graphics = NULL;

	position.x = 200;
	position.y = 20;

	// idle animation 
	idle.PushBack({ 184, 120, 96, 77 });
	
}

ModuleEnemySpaceship::~ModuleEnemySpaceship()
{}


bool ModuleEnemySpaceship::Start()
{
	LOG("Loading spaceship textures");
	bool ret = true;
		graphics = App->textures->Load("assets/textures/spaceship.png");

	spaceship = App->collision->AddCollider({ position.x, position.y, 96, 77 }, COLLIDER_ENEMY, this);
	return ret;
}

update_status ModuleEnemySpaceship::Update()
{

	current_animation = &idle;

	if (App->input->keyboard[SDL_SCANCODE_RCTRL] == KEY_STATE::KEY_DOWN)
	{
		App->particles->AddParticle(App->particles->spaceship_shot, position.x+48, position.y+60, COLLIDER_ENEMY_SHOT, 0);
		Mix_PlayChannel(-1, App->audio->fx_shoot, 0);
	}


	spaceship->SetPos(position.x, position.y);


	// Draw everything --------------------------------------
	App->render->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()));

	return UPDATE_CONTINUE;
}

bool ModuleEnemySpaceship::CleanUp()
{
	LOG("Unloading spaceship");

	App->textures->Unload(graphics);
	App->collision->EraseCollider(spaceship);

	return true;
}


void ModuleEnemySpaceship::OnCollision(Collider* c1, Collider* c2) {

	if (c1 == spaceship) {
		if (c2 != App->player->player) {
			App->spaceship->Disable();
			spaceship->SetPos(0, 500);
		}
	}
}
