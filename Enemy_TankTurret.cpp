#include "Application.h"
#include "Enemy_TankTurret.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include <math.h>
#include "ModuleInput.h"
#include "ModuleParticles.h"

Tank_Turret::Tank_Turret(int x, int y) : Enemy(x, y)
{


	int i = 0;
	//Animation

	//0
	turret_anim[i].PushBack({ 85,959,34,34 });
	turret_anim[i].PushBack({ 126,959,34,34 });
	turret_anim[i].loop = true;
	turret_anim[i++].speed = 0.2f;
	//1
	turret_anim[i].PushBack({ 126,998,34,34 });
	turret_anim[i].PushBack({ 85,998,38,34 });
	turret_anim[i].loop = true;
	turret_anim[i++].speed = 0.2f;
	//2
	turret_anim[i].PushBack({ 170,925,34,34 });
	turret_anim[i].PushBack({ 205,925,34,34 });
	turret_anim[i].loop = true;
	turret_anim[i++].speed = 0.2f;
	//3
	turret_anim[i].PushBack({ 88,1047,34,34 });
	turret_anim[i].PushBack({ 129,1047,34,34 });
	turret_anim[i].loop = true;
	turret_anim[i++].speed = 0.2f;
	//4
	turret_anim[i].PushBack({ 173, 960,34,34 });
	turret_anim[i].PushBack({ 206,960,34,34 });
	turret_anim[i].loop = true;
	turret_anim[i++].speed = 0.2f;
	//5 
	turret_anim[i].PushBack({ 176,1000,34,34 });
	turret_anim[i].PushBack({ 212,1000,34,34 });
	turret_anim[i].loop = true;
	turret_anim[i++].speed = 0.2f;
	//6
	turret_anim[i].PushBack({ 175,1042,34,34 });
	turret_anim[i].PushBack({ 217, 1042,34,34 });
	turret_anim[i].loop = true;
	turret_anim[i++].speed = 0.2f;
	//7
	turret_anim[i].PushBack({ 256,922,34,34 });
	turret_anim[i].PushBack({ 305,922,34,34 });
	turret_anim[i].loop = true;
	turret_anim[i++].speed = 0.2f;
	//8 
	turret_anim[i].PushBack({ 258,952,34,34 });
	turret_anim[i].PushBack({ 307,952,34,34 });
	turret_anim[i].loop = true;
	turret_anim[i++].speed = 0.2f;
	//9
	turret_anim[i].PushBack({ 259,994,34,34 });
	turret_anim[i].PushBack({ 309,994,34,34 });
	turret_anim[i].loop = true;
	turret_anim[i++].speed = 0.2f;
	//10
	turret_anim[i].PushBack({ 259,1042,34,34 });
	turret_anim[i].PushBack({ 308,1042,34,34 });
	turret_anim[i].loop = true;
	turret_anim[i++].speed = 0.2f;
	//11
	turret_anim[i].PushBack({ 14,922,34,34 });
	turret_anim[i].PushBack({ 46,922,34,34 });
	turret_anim[i].loop = true;
	turret_anim[i++].speed = 0.2f;
	//12
	turret_anim[i].PushBack({ 15,958,34,34 });
	turret_anim[i].PushBack({ 46,957,34,34 });
	turret_anim[i].loop = true;
	turret_anim[i++].speed = 0.2f;
	//13
	turret_anim[i].PushBack({ 17,999,34,34 });
	turret_anim[i].PushBack({ 49,999,34,34 });
	turret_anim[i].loop = true;
	turret_anim[i++].speed = 0.2f;
	//14
	turret_anim[i].PushBack({ 13,1044,34,34 });
	turret_anim[i].PushBack({ 54,1044,34, 34 });
	turret_anim[i].loop = true;
	turret_anim[i++].speed = 0.2f;
	//15
	turret_anim[i].PushBack({ 86,924,34,34 });
	turret_anim[i].PushBack({ 128,924,34,34 });
	turret_anim[i].loop = true;
	turret_anim[i++].speed = 0.2f;


	original_pos.x = x;
	original_pos.y = y;



}


void Tank_Turret::Move()
{

	// Turret rotation

	//Decide player to shoot

	int player1_x = (App->player->position.x - position.x);
	int player1_y = (App->player->position.y - position.y);

	int player2_x = (App->player2->position.x - position.x);
	int player2_y = (App->player2->position.y - position.y);

	int target = 0;

	if (App->player->living && !App->player2->living) {
		target = 1;
	}
	if (App->player2->living && !App->player->living) {
		target = 2;
	}
	if (pow(player1_x, 2) + pow(player1_y, 2) <= pow(player2_x, 2) + pow(player2_y, 2)) {
		target = 1;
	}

	else {
		target = 2;
	}

	switch (target) {
	case 0:
		break;
	case 1:
		//Player 1
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
		if (shoot>180)
		{
			float proj_speed = 4.0f;
			float speed_x_mult, speed_y_mult, common_mult, a_mult;

			speed_x_mult = (App->player->position.x - position.x);
			speed_y_mult = (App->player->position.y - position.y);

			a_mult = sqrt((pow(speed_x_mult, 2) + pow(speed_y_mult, 2)));

			common_mult = (proj_speed / a_mult);

			App->particles->enemy_shot.speed.x = (common_mult * speed_x_mult);

			App->particles->enemy_shot.speed.y = (common_mult * speed_y_mult);

			if (App->particles->enemy_shot.speed.x != 0 && App->particles->enemy_shot.speed.y != 0)
				App->particles->AddParticle(App->particles->enemy_shot, position.x + 11, position.y + 10, COLLIDER_ENEMY_SHOT, 0);
			shoot = 0;

		}
		break;

	case 2:
		//Player 2

		if (App->player2->position.y > position.y) {

			float angle = atan2(App->player2->position.y - position.y, App->player2->position.x - position.x);
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

			float angle = atan2(position.y - App->player2->position.y, position.x - App->player2->position.x);
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
		if (shoot>180)
		{
			float proj_speed = 4.0f;
			float speed_x_mult, speed_y_mult, common_mult, a_mult;

			speed_x_mult = (App->player2->position.x - position.x);
			speed_y_mult = (App->player2->position.y - position.y);

			a_mult = sqrt((pow(speed_x_mult, 2) + pow(speed_y_mult, 2)));

			common_mult = (proj_speed / a_mult);

			App->particles->enemy_shot.speed.x = (common_mult * speed_x_mult);

			App->particles->enemy_shot.speed.y = (common_mult * speed_y_mult);

			if (App->particles->enemy_shot.speed.x != 0 && App->particles->enemy_shot.speed.y != 0)
				App->particles->AddParticle(App->particles->enemy_shot, position.x + 11, position.y + 10, COLLIDER_ENEMY_SHOT, 0);
			shoot = 0;

		}
		break;
	}


	shoot++;

}
