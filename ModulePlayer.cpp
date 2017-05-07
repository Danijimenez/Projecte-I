#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"
#include "ModuleCollision.h"
#include "ModuleFonts.h"
#include "ModuleLevel1.h"
#include "ModuleFadeToBlack.h"
#include "ModuleHallOfAces.h"

#include "SDL/include/SDL.h"

#include<stdio.h>


ModulePlayer::ModulePlayer()
{

	graphics = NULL;
	current_animation = NULL;

	position.x = 0;
	position.y = 250;

	// idle animation 
	idle.PushBack({ 19, 17, 22, 29 });
	idle.PushBack({ 48, 17, 22, 29 });
	idle.speed = 0.1f;
	idle.loop = true;

	// right
	right[0].PushBack({ 20, 91, 22, 29 });
	right[0].PushBack({ 49, 92, 22, 29 });
	right[0].loop = false;
	right[0].speed = 0.1f;

	right[1].PushBack({ 73, 92, 22, 29 });
	right[1].PushBack({ 97, 92, 22, 29 });
	right[1].loop = true;
	right[1].speed = 0.1f;

	// left
	left[0].PushBack({ 19, 56, 22, 29 });
	left[0].PushBack({ 48, 56, 22, 29 });
	left[0].loop = false;
	left[0].speed = 0.1f;

	left[1].PushBack({ 72, 56, 22, 29 });
	left[1].PushBack({ 96, 56, 22, 29 });
	left[1].loop = true;
	left[1].speed = 0.1f;

}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	bool ret = true;

		LOG("Loading player textures");
		
		position.x = 150;
		position.y = 176;
		destroyed = false;

		graphics = App->textures->Load("assets/textures/player1.png");
		App->collision->Enable();
		font_score = App->fonts->Load("assets/fonts/RedCharacters.png", " !|#$%&'()*+,-./0123456789:;�<>?@abcdefghijklmnopqrstuvwxyz!?_��", 4);
		App->fonts->Load("assets/fonts/GreenCharacters.png", " !|#$%&'()*+,-./0123456789:;�<>?@abcdefghijklmnopqrstuvwxyz!?_��", 4);
		App->fonts->Load("assets/fonts/YellowCharacters.png", " !|#$%&'()*+,-./0123456789:;�<>?@abcdefghijklmnopqrstuvwxyz!?_��", 4);
		shoot_type = STANDARD;
		player = App->collision->AddCollider({ position.x - 3, position.y, 25, 29 }, COLLIDER_PLAYER, this); //
		speed = 0;
		started = true;
		move_speed = 1;
		lifes = 2;
		living = true;
		App->audio->Enable();
		player_points = 0;

	return ret;
}


bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(graphics);
	App->collision->EraseCollider(player);
	App->fonts->UnLoad(font_score);


	return true;
}

// Update: draw background
update_status ModulePlayer::Update()
{


	if ((App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT || SDL_GameControllerGetButton(App->input->controller, SDL_CONTROLLER_BUTTON_DPAD_UP)) && move_up)
	{
		position.y -= move_speed;
	}

	if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT && move_down)
	{
		position.y += 2* move_speed;
		
	}

	if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_UP) {
		right_anim = 0;
	}

	if (App->input->keyboard[SDL_SCANCODE_Q] == KEY_STATE::KEY_REPEAT)
	{
		App->render->camera.x -= 2 * speed;
		position.y += 2 * move_speed;
	}


	if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
	{

		
			if (position.x < 330) {
				position.x += 2*move_speed;
				if (App->render->camera.x > -128) {
				App->render->camera.x -= speed;
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

	if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_UP) {
		right_anim = 0;
	}

	if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
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

	if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE
		&& App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE) {
		current_animation = &idle;

	}
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN || App->input->contrkey[SDL_CONTROLLER_BUTTON_A] == KEY_STATE::KEY_DOWN)
	{ 
		
		switch (shoot_type)
		{
		case STANDARD:
			App->particles->AddParticle(App->particles->standard_shot, position.x+8, position.y, COLLIDER_PLAYER_SHOT, 0);
			App->particles->AddParticle(App->particles->standard_shot_flash, position.x, position.y - 5, COLLIDER_NONE, 0);
			break;
		case LASER:		

			App->particles->AddParticle(App->particles->laser_flash, position.x , position.y-3, COLLIDER_NONE, 0);
			App->particles->AddParticle(App->particles->laser, position.x+10 , position.y, COLLIDER_PLAYER_SHOT, 0);
			App->particles->AddParticle(App->particles->laser, position.x+10, position.y+15, COLLIDER_PLAYER_SHOT, 0);

			break;
		case LASER_LVL2:


			break;
		case VULCAN:
			App->particles->AddParticle(App->particles->standard_shot, position.x + 4, position.y, COLLIDER_PLAYER_SHOT, 0);	
			App->particles->AddParticle(App->particles->standard_shot, position.x + 16, position.y, COLLIDER_PLAYER_SHOT, 0);
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


	position.y -= speed;



	player->SetPos(position.x-3, position.y);
	

	// Draw everything --------------------------------------
	App->render->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()));

	// Draw UI (score) --------------------------------------

	App->fonts->BlitText(34, 0, font_score, "1 up  hi-score  2 up");

	switch (lifes) {
	case 0:
		App->fonts->BlitText(0, 17, font_score,  "�");
		break;
	case 1:
		App->fonts->BlitText(0 , 17, font_score, "��");
		break;
	case 2:
		App->fonts->BlitText(0, 17, font_score, "���");
		break;

	}

	
	

	sprintf_s(score_text, 10, "%7d", player_points);
	sprintf_s(hiscore_text, 10, "%7d", App->level_1->hi_score);

	App->fonts->BlitText(10, 9, 2, score_text); // player score
	App->fonts->BlitText(78, 9, 2, hiscore_text); // hi score

	int move_speed = 1;

	if (!living) {
		lifes--;
		position.x = 176;
		position.y = -App->render->camera.y/SCREEN_SIZE+200;
		if (lifes < 0) {
			player->to_delete = true;
			this->Disable();
			App->fade->FadeToBlack(App->level_1, App->HallOfAces, 2.0f);
		}
		living = true;
	}

	if (App->input->keyboard[SDL_SCANCODE_F3] == KEY_STATE::KEY_DOWN) {
		hittable = !hittable;
	}

	return UPDATE_CONTINUE;
}


void ModulePlayer::OnCollision(Collider* c1, Collider* c2) {

	if (hittable) {
		switch (c2->type)
		{
		case COLLIDER_ENEMMY_TURRET:
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