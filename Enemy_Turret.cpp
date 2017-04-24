#include "Application.h"
#include "Enemy_Turret.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include <math.h>
#include "ModuleInput.h"
#include "ModuleParticles.h"

Turret::Turret(int x, int y) : Enemy(x, y)
{

	//Animation

	turret_anim[0].PushBack({ 480,146,26,25 });
	turret_anim[1].PushBack({ 562,43,22,21 });
	turret_anim[2].PushBack({ 562,75,22,21 });
	turret_anim[3].PushBack({ 521,7,22,21 });
	turret_anim[4].PushBack({ 480,113,22,21 });
	turret_anim[5].PushBack({ 521,45,22,21 });
	turret_anim[6].PushBack({ 562,144,22,21 });
	turret_anim[7].PushBack({ 561,6,22,21 });
	turret_anim[8].PushBack({ 479,178,22,21 });
	turret_anim[9].PushBack({ 479,78,22,21 });
	turret_anim[10].PushBack({ 562,110,22,21 });
	turret_anim[11].PushBack({ 479,7,22,21 });
	turret_anim[12].PushBack({ 521,110,22,21 });
	turret_anim[13].PushBack({ 521,76,22,21 });
	turret_anim[14].PushBack({ 520,146,22,21 });
	turret_anim[15].PushBack({ 480,45,22,21 });


	collider = App->collision->AddCollider({ 0, 0, 22, 21 }, COLLIDER_TYPE::COLLIDER_ENEMMY_TURRET, (Module*)App->enemies_ground);
	collider->life_units = 4;

	original_pos.x = x;
	original_pos.y = y;

	//path
//	path.PushBack({ 0.0, 0.0 }, 240);
}

//22 28

void Turret::Move()
{

	// Turret rotation
	if (App->player->position.y > position.y) {

		float angle = atan2(App->player->position.y - position.y, App->player->position.x - position.x);
		angle *= 180 / 3.14;

		uint k = 15;
		for (uint i = 0; i < 16; i++) {
			k--;
			if (angle >= ((i*22.5) + 11.25) && angle <= (((i + 1)*22.5) + 11.25)) {
				
				animation = &turret_anim[k];
			
				break;
			}
		}
	}

	else {

		float angle = atan2(position.y - App->player->position.y, position.x - App->player->position.x);
		angle *= 180 / 3.14;

		uint k = 7;
		for (uint i = 0; i < 16; i++) {
		
			if (angle >= ((i*22.5) + 11.25) && angle <= (((i + 1)*22.5) + 11.25)) {

				animation = &turret_anim[k];

				break;
				
			}
			k--;
		}
	}

	// Enemy shoot
	if (App->input->keyboard[SDL_SCANCODE_RCTRL] == KEY_STATE::KEY_DOWN) 
	{
		float proj_speed=4.0f;
		float speed_x_mult, speed_y_mult, common_mult, a_mult;

		speed_x_mult = (App->player->position.x - position.x);
		speed_y_mult = (App->player->position.y - position.y);

		a_mult = sqrt((pow(speed_x_mult, 2) + pow(speed_y_mult, 2)));

		common_mult = (proj_speed / a_mult);

		App->particles->enemy_shot.speed.x = ( common_mult * speed_x_mult );

		App->particles->enemy_shot.speed.y = (common_mult * speed_y_mult);

		if (App->particles->enemy_shot.speed.x != 0 && App->particles->enemy_shot.speed.y != 0)
		App->particles->AddParticle(App->particles->enemy_shot, position.x+11, position.y+10, COLLIDER_ENEMY_SHOT, 0);
		
	}
	position = original_pos + path.GetCurrentPosition();

}
