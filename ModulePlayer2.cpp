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
#include "ModuleFadeToBlack.h"
#include "ModuleHallOfAces.h"

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

}

ModulePlayer2::~ModulePlayer2()
{}

// Load assets
bool ModulePlayer2::Start()
{
	bool ret = true;

		LOG("Loading player textures");

		position.x = 200;
		position.y = 176;

		graphics = App->textures->Load("assets/textures/player2.png");

		font_score = App->fonts->Load("assets/fonts/RedCharacters.png", " !|#$%&'()*+,-./0123456789:;¿<>?@abcdefghijklmnopqrstuvwxyz!?_·¬", 4);
		App->fonts->Load("assets/fonts/GreenCharacters.png", " !|#$%&'()*+,-./0123456789:;¿<>?@abcdefghijklmnopqrstuvwxyz!?_·¬", 4);
		App->fonts->Load("assets/fonts/YellowCharacters.png", " !|#$%&'()*+,-./0123456789:;¿<>?@abcdefghijklmnopqrstuvwxyz!?_·¬", 4);
		shoot_type = STANDARD;
		player2 = App->collision->AddCollider({ position.x + 12, position.y, 22, 29 }, COLLIDER_PLAYER_2, this); //
		speed = 1;
		move_speed = 1;
		lifes = 2;
		living = true;

		bombs = 3;

	
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

	if ((App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT 
		|| SDL_GameControllerGetAxis(App->input->controller_2, SDL_CONTROLLER_AXIS_LEFTY) < -5000)
		&& move_up)
	{
		position.y -= move_speed;
	}

	if ((App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT 
		|| SDL_GameControllerGetAxis(App->input->controller_2, SDL_CONTROLLER_AXIS_LEFTY) > 5000) 
		&& move_down)
	{
		position.y += 2 * move_speed;
	}

	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_UP
		|| SDL_GameControllerGetAxis(App->input->controller_2, SDL_CONTROLLER_AXIS_LEFTX) > 5000) {
		right_anim = 0;
	}

	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT
		|| SDL_GameControllerGetAxis(App->input->controller_2, SDL_CONTROLLER_AXIS_LEFTX) > 5000)
	{

		if (position.x < 330) {
			position.x += 2*move_speed;
			if (App->render->camera.x > -128) {
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

	if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_UP
		|| SDL_GameControllerGetAxis(App->input->controller_2, SDL_CONTROLLER_AXIS_LEFTX) > -5000) {
		left_anim = 0;
	}
	if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT
		|| SDL_GameControllerGetAxis(App->input->controller_2, SDL_CONTROLLER_AXIS_LEFTX) < -5000)
	{

		if (position.x > 0) {
			position.x -= 2*move_speed;
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

	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_IDLE
		&& App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_IDLE
		&& SDL_GameControllerGetAxis(App->input->controller_2, SDL_CONTROLLER_AXIS_LEFTX) < 5000
		&& SDL_GameControllerGetAxis(App->input->controller_2, SDL_CONTROLLER_AXIS_LEFTX) > -5000) 
	{
		current_animation = &idle;

	}




	if (App->input->keyboard[SDL_SCANCODE_RCTRL] == KEY_STATE::KEY_DOWN
		|| App->input->contrkey2[SDL_CONTROLLER_BUTTON_A] == KEY_STATE::KEY_DOWN)
	{
		uint i = 16;
		switch (shoot_type)
		{
		case STANDARD:
			App->particles->AddParticle(App->particles->standard_shot, position.x, position.y+11, COLLIDER_PLAYER_2_SHOT, 0);
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

	if ((App->input->keyboard[SDL_SCANCODE_Q] == KEY_STATE::KEY_DOWN || App->input->contrkey2[SDL_CONTROLLER_BUTTON_X] == KEY_STATE::KEY_DOWN) && bombs >= 0)
	{
		App->particles->AddParticle(App->particles->bomb, position.x - 70, position.y - 130, COLLIDER_BOMB, 0);
		bombs--;
	}



	move_up = true;
	move_down = true;

	if (App->player->movep) {
		position.y -= App->player->speed;
	}

	player2->SetPos(position.x, position.y);


	// Draw everything --------------------------------------
	App->render->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()));

	// Draw UI (score) --------------------------------------

	App->fonts->BlitText(34, 0, font_score, "1 up  hi-score  2 up");

	switch (lifes) {
	case 0:
		App->fonts->BlitText(200, 17, font_score, "¬");
		break;
	case 1:
		App->fonts->BlitText(200, 17, font_score, "¬¬");
		break;
	case 2:
		App->fonts->BlitText(200, 17, font_score, "¬¬¬");
		break;

	}

	if (!living) {
		lifes--;
		position.x = 176;
		position.y = -App->render->camera.y / SCREEN_SIZE + 200;
		if (lifes < 0) {
			player2->to_delete = true;
			this->Disable();
			App->fade->FadeToBlack(App->level_1, App->HallOfAces, 2.0f);
		}
		living = true;
	}

	if (App->input->keyboard[SDL_SCANCODE_F3] == KEY_STATE::KEY_DOWN) {
		hittable = !hittable;
	}

	sprintf_s(score_text, 10, "%7d", player_points);
	sprintf_s(hiscore_text, 10, "%7d", App->level_1->hi_score);

	App->fonts->BlitText(150, 9, 2, score_text); // player score
	App->fonts->BlitText(78, 9, 2, hiscore_text); // hi score

	if (App->input->keyboard[SDL_SCANCODE_F4] == KEY_STATE::KEY_DOWN) {
		hittable = !hittable;
	}

	return UPDATE_CONTINUE;
}


void ModulePlayer2::OnCollision(Collider* c1, Collider* c2) {

	if (hittable) {
		switch (c2->type)
		{
		case COLLIDER_ENEMY_TURRET:
			break;
		case COLLIDER_ENEMY_BASIC:
			App->particles->AddParticle(App->particles->player_explosion, position.x, position.y, COLLIDER_NONE, 0);
			living = false;
			break;
		case COLLIDER_ENEMY_GREENSHIP:

			App->particles->AddParticle(App->particles->player_explosion, position.x, position.y, COLLIDER_NONE, 0);
			living = false;
			break;
		case COLLIDER_ENEMY_POWERUPSHIP:

			App->particles->AddParticle(App->particles->player_explosion, position.x, position.y, COLLIDER_NONE, 0);
			living = false;
			break;
		case COLLIDER_ENEMY_SHOT:

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
	else {
		switch (c2->type)
		{
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


}