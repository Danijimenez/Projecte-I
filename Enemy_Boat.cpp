#include "Application.h"
#include "Enemy_Boat.h"
#include "ModuleCollision.h"
#include "ModuleInput.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"
#include "ModulePlayer2.h"



Boat::Boat(int x, int y) : Enemy(x, y)
{
	int i = 0;
	//Animation
	
	//0
	sail[0].PushBack({ 696,768,38,34 });
	sail[0].PushBack({ 642,768,38,34 });
	sail[0].loop = true;
	sail[0].speed = 0.2f;
	//1
	sail[1].PushBack({ 696,817,38,34 });
	sail[1].PushBack({ 642,817,38,34 });
	sail[1].loop = true;
	sail[1].speed = 0.2f;
	//2
	sail[2].PushBack({ 802,621,38,34 });
	sail[2].PushBack({ 754,621,38,34 });
	sail[2].loop = true;
	sail[2].speed = 0.2f;
	//3
	sail[3].PushBack({ 696,722,38,34 });
	sail[3].PushBack({ 642,722,38,34 });
	sail[3].loop = true;
	sail[3].speed = 0.2f;
	//4
	sail[4].PushBack({ 696,673,38,34 });
	sail[4].PushBack({ 642,673,38,34 });
	sail[4].loop = true;
	sail[4].speed = 0.2f;
	//5
	sail[5].PushBack({ 696,621,38,34 });
	sail[5].PushBack({ 642,621,38,34 });
	sail[5].loop = true;
	sail[5].speed = 0.2f;
	//6
	sail[6].PushBack({ 578,817,38,34 });
	sail[6].PushBack({ 526, 817,38,34 });
	sail[6].loop = true;
	sail[6].speed = 0.2f;
	//7
	sail[7].PushBack({ 578,768,38,34 });
	sail[7].PushBack({ 526,768,38,34 });
	sail[7].loop = true;
	sail[7].speed = 0.2f;
	//8
	sail[8].PushBack({ 578,722,38,34 });
	sail[8].PushBack({ 526,722,38,34 });
	sail[8].loop = true;
	sail[8].speed = 0.2f;
	//9
	sail[9].PushBack({ 578,674,38,34 });
	sail[9].PushBack({ 526,674,38,34 });
	sail[9].loop = true;
	sail[9].speed = 0.2f;
	//10
	sail[10].PushBack({ 578,621,38,34 });
	sail[10].PushBack({ 526,621,38,34 });
	sail[10].loop = true;
	sail[10].speed = 0.2f;
	//11
	sail[11].PushBack({ 465,621,38,34 });
	sail[11].PushBack({ 410,621,38,34 });
	sail[11].loop = true;
	sail[11].speed = 0.2f;
	//12
	sail[12].PushBack({ 465,674,38,34 });
	sail[12].PushBack({ 410,674,38,34 });
	sail[12].loop = true;
	sail[12].speed = 0.2f;
	//13
	sail[13].PushBack({ 465,722,38,34 });
	sail[13].PushBack({ 410,722,38,34 });
	sail[13].loop = true;
	sail[13].speed = 0.2f;
	//14
	sail[14].PushBack({ 465,768,38,34 });
	sail[14].PushBack({ 410,768,38,34 });
	sail[14].loop = true;
	sail[14].speed = 0.2f;
	//15
	sail[15].PushBack({ 465,817,38,34 });
	sail[15].PushBack({ 410,817,38,34 });
	sail[15].loop = true;
	sail[15].speed = 0.2f;



	shot.PushBack({ 366,310,72,52 });


	animation = &sail[2];

	collider = App->collision->AddCollider({ 0, 0, 38, 34 }, COLLIDER_TYPE::COLLIDER_ENEMY_TANK, (Module*)App->enemies);
	collider->life_units = 15;

	original_pos.x = x;
	original_pos.y = y;


	//path

	path.PushBack({ 0.0f, 1.0833f }, 50);
	
	path.loop = true;
}

void Boat::Move()
{
	//if (App->player->living && !App->player2->living) {
		if (App->player->position.y > position.y) {

			float angle = atan2(App->player->position.y - position.y, App->player->position.x - position.x);
			angle *= 180 / 3.14;

			uint k = 15;
			for (uint i = 0; i < 16; i++) {
				k--;
				if (angle >= ((i*22.5) + 11.25) && angle <= (((i + 1)*22.5) + 11.25)) {

					animation = &sail[k];

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

					animation = &sail[k];

					break;

				}
				k--;
			}
		}
//	}

	//Player 2 only

	/*else if (App->player2->living && !App->player->living) {
		if (App->player2->position.y > position.y) {

			float angle = atan2(App->player2->position.y - position.y, App->player2->position.x - position.x);
			angle *= 180 / 3.14;

			uint k = 15;
			for (uint i = 0; i < 16; i++) {
				k--;
				if (angle >= ((i*22.5) + 11.25) && angle <= (((i + 1)*22.5) + 11.25)) {

					animation = &sail[k];

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

					animation = &sail[k];

					break;

				}
				k--;
			}
		}
	}
	*/

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

		if (animation == &shot)
		{
			float proj_speed = 2.0f;
			float speed_x_mult, speed_y_mult, common_mult, a_mult;

			speed_x_mult = (App->player->position.x - position.x - 11);
			speed_y_mult = (App->player->position.y - position.y + 20);

			a_mult = sqrt((pow(speed_x_mult, 2) + pow(speed_y_mult, 2)));

			common_mult = (proj_speed / a_mult);

			App->particles->enemy_shot.speed.x = (common_mult * speed_x_mult);

			App->particles->enemy_shot.speed.y = (common_mult * speed_y_mult);

			if (App->particles->enemy_shot.speed.x != 0 && App->particles->enemy_shot.speed.y != 0) {
				App->particles->AddParticle(App->particles->enemy_shot, position.x + 11, position.y + 30, COLLIDER_ENEMY_SHOT, 0);
			}

		}

		break;
	case 2:
		if (animation == &shot && player2_y >=0)
		{
			float proj_speed = 2.0f;
			float speed_x_mult, speed_y_mult, common_mult, a_mult;

			speed_x_mult = (App->player2->position.x - position.x);
			speed_y_mult = (App->player2->position.y - position.y);

			a_mult = sqrt((pow(speed_x_mult, 2) + pow(speed_y_mult, 2)));

			common_mult = (proj_speed / a_mult);

			App->particles->laser2.speed.x = -(common_mult * speed_x_mult);

			App->particles->laser2.speed.y = -(common_mult * speed_y_mult);

			if (App->particles->laser2.speed.x != 0 && App->particles->laser2.speed.y != 0)
				App->particles->AddParticle(App->particles->enemy_shot, position.x + 11, position.y + 10, COLLIDER_ENEMY_SHOT, 0);
		}
		break;
	}



	position = original_pos + path.GetCurrentPosition();

}
