#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"
#include "ModuleCollision.h"
#include "ModuleEnemySpaceship.h"


ModulePlayer::ModulePlayer()
{

	graphics = NULL;
	current_animation = NULL;

	position.x = 100;
	position.y = 220;

	// idle animation 
	idle.PushBack({63, 3, 22, 28});

	// right
	right.PushBack({ 99, 2, 19, 29 });
	right.PushBack({ 130, 3, 22, 28 });

	right.loop = false;
	right.speed = 0.1f;

	// left
	left.PushBack({ 29, 2, 19, 29 });
	left.PushBack({ 1, 2, 14, 29 });
	left.loop = false;
	left.speed = 0.1;

}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	position.x = 260;
	position.y = 260;

	graphics = App->textures->Load("assets/textures/player1.png"); 

	player = App->collision->AddCollider({ position.x-3, position.y, 25, 29 }, COLLIDER_PLAYER, this);
	return ret;
}


bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(graphics);
	App->collision->EraseCollider(player);

	return true;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	
	int speed = 1;

	if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT)
	{
		position.y -= speed;
	}

	if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
	{
		if (App->render->camera.y - position.y < 20) {
			position.y += speed;
		}
	}


	if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
	{
		if (position.x <= 220) {
			position.x += speed;
		}
		else if (position.x < 380) {
			position.x += speed;
			if (App->render->camera.x > -130) {
				App->render->camera.x -= speed;
			}
		
		}
		if (current_animation != &right)
		{
			right.Reset();
			current_animation = &right;
			shoot_pos = 7;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
	{
		if (position.x >= 220) {
			position.x -= speed;
		}
		else if (position.x > 0) {
			position.x -= speed;
			if (App->render->camera.x < 0) {
				App->render->camera.x += speed;
			}
		}
		if (current_animation != &left)
		{
			left.Reset();
			current_animation = &left;
			shoot_pos = 4;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE
		&& App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE) {
		current_animation = &idle;
		shoot_pos = 8;
	}
	if (App->input->keyboard[SDL_SCANCODE_LCTRL] == KEY_STATE::KEY_DOWN)
	{
		App->particles->AddParticle(App->particles->shoot, position.x + shoot_pos, position.y, COLLIDER_PLAYER_SHOT,0);
		Mix_PlayChannel(-1, App->audio->fx_shoot, 0);
	}

	position.y += 1;

	player->SetPos(position.x-3, position.y);


	// Draw everything --------------------------------------
	App->render->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()));
	
	return UPDATE_CONTINUE;
}


void ModulePlayer::OnCollision(Collider* c1, Collider* c2) {

	if (c1 == player) {

		App->player->Disable();

		App->collision->EraseCollider(player);

		//		App->scene_space->scroll_speed = 0;

	}
}