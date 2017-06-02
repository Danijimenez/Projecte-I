#include "Application.h"
#include "Enemy_Grey_TankTurret.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include <math.h>
#include "ModuleInput.h"
#include "ModuleParticles.h"

Tank_Turret::Tank_Turret(int x, int y) : Enemy(x, y)
{

	//Animation

	///
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
	///


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
