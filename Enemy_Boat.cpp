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
	sail[i].PushBack({ 696,768,38,34 });
	sail[i].PushBack({ 642,768,38,34 });
	sail[i].loop = true;
	sail[i++].speed = 0.2f;
	//1
	sail[i].PushBack({ 696,817,38,34 });
	sail[i].PushBack({ 642,817,38,34 });
	sail[i].loop = true;
	sail[i++].speed = 0.2f;
	//2
	sail[i].PushBack({ 802,621,38,34 });
	sail[i].PushBack({ 754,621,38,34 });
	sail[i].loop = true;
	sail[i++].speed = 0.2f;
	//3
	sail[i].PushBack({ 696,722,38,34 });
	sail[i].PushBack({ 642,722,38,34 });
	sail[i].loop = true;
	sail[i++].speed = 0.2f;
	//4
	sail[i].PushBack({ 696,673,38,34 });
	sail[i].PushBack({ 642,673,38,34 });
	sail[i].loop = true;
	sail[i++].speed = 0.2f;
	//5
	sail[i].PushBack({ 696,621,38,34 });
	sail[i].PushBack({ 642,621,38,34 });
	sail[i].loop = true;
	sail[i++].speed = 0.2f;
	//6
	sail[i].PushBack({ 578,817,38,34 });
	sail[i].PushBack({ 526, 817,38,34 });
	sail[i].loop = true;
	sail[i++].speed = 0.2f;
	//7
	sail[i].PushBack({ 578,768,38,34 });
	sail[i].PushBack({ 526,768,38,34 });
	sail[i].loop = true;
	sail[i++].speed = 0.2f;
	//8
	sail[i].PushBack({ 578,722,38,34 });
	sail[i].PushBack({ 526,722,38,34 });
	sail[i].loop = true;
	sail[i++].speed = 0.2f;
	//9
	sail[i].PushBack({ 578,674,38,34 });
	sail[i].PushBack({ 526,674,38,34 });
	sail[i].loop = true;
	sail[i++].speed = 0.2f;
	//10
	sail[i].PushBack({ 578,621,38,34 });
	sail[i].PushBack({ 526,621,38,34 });
	sail[i].loop = true;
	sail[i++].speed = 0.2f;
	//11
	sail[i].PushBack({ 465,621,38,34 });
	sail[i].PushBack({ 410,621,38,34 });
	sail[i].loop = true;
	sail[i++].speed = 0.2f;
	//12
	sail[i].PushBack({ 465,674,38,34 });
	sail[i].PushBack({ 410,674,38,34 });
	sail[i].loop = true;
	sail[i++].speed = 0.2f;
	//13
	sail[i].PushBack({ 465,722,38,34 });
	sail[i].PushBack({ 410,722,38,34 });
	sail[i].loop = true;
	sail[i++].speed = 0.2f;
	//14
	sail[i].PushBack({ 465,768,38,34 });
	sail[i].PushBack({ 410,768,38,34 });
	sail[i].loop = true;
	sail[i++].speed = 0.2f;
	//15
	sail[i].PushBack({ 465,817,38,34 });
	sail[i].PushBack({ 410,817,38,34 });
	sail[i].loop = true;
	sail[i++].speed = 0.2f;



	shot.PushBack({ 366,310,72,52 });


	animation = &sail[0];

	collider = App->collision->AddCollider({ 0, 0, 72, 52 }, COLLIDER_TYPE::COLLIDER_ENEMY_GREENSHIP, (Module*)App->enemies);
	collider->life_units = 20;

	original_pos.x = x;
	original_pos.y = y;


	//path

	path.PushBack({ 0.0f, 0.756f }, 50);


	path.loop = false;
}

void Boat::Move()
{


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



	position = original_pos + path.GetCurrentPosition(&animation);

}
