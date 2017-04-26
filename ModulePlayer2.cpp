#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"
#include "ModuleCollision.h"
#include "ModuleFonts.h"
#include "ModuleLevel1.h"

#include<stdio.h>


ModulePlayer2::ModulePlayer2()
{

	graphics = NULL;
	current_animation = NULL;

	position.x = 0;
	position.y = 250;

	// idle animation 
	idle.PushBack({ 12, 8, 22, 29 });
	idle.PushBack({ 40, 8, 22, 29 });
	idle.speed = 0.1f;
	idle.loop = true;

	// right
	right[0].PushBack({ 12, 75, 22, 29 });
	right[0].PushBack({ 39, 75, 22, 29 });
	right[0].loop = false;
	right[0].speed = 0.1f;

	right[1].PushBack({ 65, 75, 22, 29 });
	right[1].PushBack({ 86, 75, 22, 29 });
	right[1].loop = true;
	right[1].speed = 0.1f;

	// left
	left[0].PushBack({ 14, 42, 22, 29 });
	left[0].PushBack({ 40, 41, 22, 29 });
	left[0].loop = false;
	left[0].speed = 0.1f;

	left[1].PushBack({ 65, 41, 22, 29 });
	left[1].PushBack({ 86, 41, 22, 29 });
	left[1].loop = true;
	left[1].speed = 0.1f;

	shoot_type = STANDARD;
}

ModulePlayer2::~ModulePlayer2()
{}

// Load assets
bool ModulePlayer2::Start()
{
	bool ret = true;
	if (!started) {
		LOG("Loading player textures");

		position.x = 260;
		position.y = 260;

		graphics = App->textures->Load("assets/textures/player2.png");

		font_score = App->fonts->Load("assets/fonts/RedCharacters.png", " !|#$%&'()*+,-./0123456789:;¿<>?@abcdefghijklmnopqrstuvwxyz!?_·¬", 4);
		App->fonts->Load("assets/fonts/GreenCharacters.png", " !|#$%&'()*+,-./0123456789:;¿<>?@abcdefghijklmnopqrstuvwxyz!?_·¬", 4);
		App->fonts->Load("assets/fonts/YellowCharacters.png", " !|#$%&'()*+,-./0123456789:;¿<>?@abcdefghijklmnopqrstuvwxyz!?_·¬", 4);

		player2 = App->collision->AddCollider({ position.x + 12, position.y, 22, 29 }, COLLIDER_PLAYER, this); //
		speed = 0;
		started = true;
		move_speed = 1;
		lifes = 3;
		living = true;
	}
	return ret;
}


bool ModulePlayer2::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(graphics);
	App->collision->EraseCollider(player2);
	App->fonts->UnLoad(font_score);

	return true;
}

// Update: draw background
update_status ModulePlayer2::Update()
{

	int speed = 1;

	if (App->input->keyboard[SDL_SCANCODE_I] == KEY_STATE::KEY_REPEAT && move_up)
	{
		position.y -= move_speed;
	}

	if (App->input->keyboard[SDL_SCANCODE_K] == KEY_STATE::KEY_REPEAT && move_down)
	{
		position.y += 2 * move_speed;
	}

	if (App->input->keyboard[SDL_SCANCODE_L] == KEY_STATE::KEY_UP) {
		right_anim = 0;
	}

	if (App->input->keyboard[SDL_SCANCODE_L] == KEY_STATE::KEY_REPEAT)
	{

		if (position.x < 385) {
			position.x += move_speed;
			if (App->render->camera.x > -360) {
				App->render->camera.x -= move_speed;
			}

		}
		if (current_animation != &right[right_anim])
		{
			right[right_anim].Reset();
			current_animation = &right[right_anim];

		}
		if (right[right_anim].isFinished() == true) {
			right_anim = 1;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_J] == KEY_STATE::KEY_UP) {
		left_anim = 0;
	}
	if (App->input->keyboard[SDL_SCANCODE_J] == KEY_STATE::KEY_REPEAT)
	{

		if (position.x > 0) {
			position.x -= move_speed;
			if (App->render->camera.x < 0) {
				App->render->camera.x += move_speed;
			}
		}
		if (current_animation != &left[left_anim])
		{
			left[left_anim].Reset();
			current_animation = &left[left_anim];

		}
		if (left[left_anim].isFinished() == true) {
			left_anim = 1;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_J] == KEY_STATE::KEY_IDLE
		&& App->input->keyboard[SDL_SCANCODE_L] == KEY_STATE::KEY_IDLE) {
		//	idle.Reset();
		current_animation = &idle;

	}
	if (App->input->keyboard[SDL_SCANCODE_RCTRL] == KEY_STATE::KEY_DOWN)
	{
		uint i = 16;
		switch (shoot_type)
		{
		case STANDARD:
			App->particles->AddParticle(App->particles->shoot, position.x, position.y, COLLIDER_PLAYER_2_SHOT, 0);
			break;
		case LASER:

			App->particles->AddParticle(App->particles->laser_flash, position.x, position.y, COLLIDER_NONE, 0);
			App->particles->AddParticle(App->particles->laser, position.x + 10, position.y, COLLIDER_PLAYER_2_SHOT, 16);
			App->particles->AddParticle(App->particles->laser_flash, position.x, position.y, COLLIDER_NONE, 16);
			App->particles->AddParticle(App->particles->laser, position.x + 10, position.y, COLLIDER_PLAYER_2_SHOT, 32);

			break;
		case LASER_LVL2:

			App->particles->AddParticle(App->particles->laser_flash, position.x, position.y, COLLIDER_NONE, 0);
			App->particles->AddParticle(App->particles->laser, position.x + 10, position.y, COLLIDER_PLAYER_2_SHOT, 16);
			App->particles->AddParticle(App->particles->laser_flash, position.x, position.y, COLLIDER_NONE, 16);
			App->particles->AddParticle(App->particles->laser, position.x + 10, position.y, COLLIDER_PLAYER_2_SHOT, 32);

			App->particles->AddParticle(App->particles->laser_flash, position.x, position.y, COLLIDER_NONE, 32);
			App->particles->AddParticle(App->particles->laser, position.x + 10, position.y, COLLIDER_PLAYER_2_SHOT, 48);
			App->particles->AddParticle(App->particles->laser_flash, position.x, position.y, COLLIDER_NONE, 48);
			App->particles->AddParticle(App->particles->laser, position.x + 10, position.y, COLLIDER_PLAYER_2_SHOT, 64);
			break;
		case VULCAN:

			break;
		case VULCAN_LVL2:

			break;
		default:
			break;
		}
		Mix_PlayChannel(-1, App->audio->fx_shoot, 0);
	}

	move_up = true;
	move_down = true;


	position.y -= 1;

	player2->SetPos(position.x, position.y);


	// Draw everything --------------------------------------
	App->render->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()));

	// Draw UI (score) --------------------------------------

	App->fonts->BlitText(34, 0, font_score, "1 up  hi-score  2 up");

	switch (lifes) {
	case 1:
		App->fonts->BlitText(200, 17, font_score, "¬");
		break;
	case 2:
		App->fonts->BlitText(200, 17, font_score, "¬¬");
		break;
	case 3:
		App->fonts->BlitText(200, 17, font_score, "¬¬¬");
		break;

	}


	sprintf_s(score_text, 10, "%7d", player_points);
	sprintf_s(hiscore_text, 10, "%7d", 50000);

	App->fonts->BlitText(150, 9, 2, score_text); // player score
	App->fonts->BlitText(78, 9, 2, hiscore_text); // hi score

	return UPDATE_CONTINUE;
}


void ModulePlayer2::OnCollision(Collider* c1, Collider* c2) {

	switch (c2->type)
	{
	case COLLIDER_ENEMMY_TURRET:
		break;
	case COLLIDER_ENEMY_BASIC:
		player2->to_delete = true;
		App->particles->AddParticle(App->particles->player_explosion, position.x, position.y, COLLIDER_NONE, 0);
		living = false;
		break;
	case COLLIDER_ENEMY_GREENSHIP:
		player2->to_delete = true;
		App->particles->AddParticle(App->particles->player_explosion, position.x, position.y, COLLIDER_NONE, 0);
		living = false;
		break;
	case COLLIDER_ENEMY_POWERUPSHIP:
		player2->to_delete = true;
		App->particles->AddParticle(App->particles->player_explosion, position.x, position.y, COLLIDER_NONE, 0);
		living = false;
		break;
	case COLLIDER_ENEMY_SHOT:
		player2->to_delete = true;
		App->particles->AddParticle(App->particles->player_explosion, position.x, position.y, COLLIDER_NONE, 0);
		living = false;
		break;
	case COLLIDER_WALL_UP:
		move_up = false;
		break;
	case COLLIDER_WALL_DOWN:
		move_down = false;
		break;
	default:
		break;
	}

}