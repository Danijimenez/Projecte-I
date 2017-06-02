#include "Application.h"
#include "Enemy_BigBoat.h"
#include "ModuleCollision.h"
#include "ModuleInput.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"
#include "ModulePlayer2.h"



BigBoat::BigBoat(int x, int y) : Enemy(x, y)
{

	//Animation
	sail.PushBack({ 468,13,29,47 });
	sail.PushBack({ 533,13,29,47 });
	sail.PushBack({ 595,13,29,47 });
	sail.PushBack({ 657,13,29,47 });
	sail.PushBack({ 722,13,29,47 });
	sail.PushBack({ 785,13,29,47 });
	sail.PushBack({ 467,89,29,47 });
	sail.PushBack({ 533,89,29,47 });
	sail.PushBack({ 596,89,29,47 });
	shot.PushBack({ 657,89,29,47 });

	sail.speed = 0.2f;




	animation = &sail;

	collider = App->collision->AddCollider({ 0, 0, 72, 52 }, COLLIDER_TYPE::COLLIDER_ENEMY_GREENSHIP, (Module*)App->enemies);
	collider->life_units = 20;

	original_pos.x = x;
	original_pos.y = y;


	//path

	path.PushBack({ 0.0f, 0.756f }, 50, &sail);
	path.PushBack({ 0, 0 }, 1, &shot);
	path.PushBack({ 0, 0 }, 1, &shot);
	path.PushBack({ 0, 0 }, 1, &shot);
	path.PushBack({ 0, 0 }, 1, &shot);
	path.PushBack({ 0, 0 }, 1, &shot);
	path.PushBack({ 0, 0 }, 1, &shot);
	path.PushBack({ 0.0f, 0.756f }, 50, &sail);
	path.PushBack({ 0, 0 }, 1, &shot);
	path.PushBack({ 0, 0 }, 1, &shot);
	path.PushBack({ 0, 0 }, 1, &shot);
	path.PushBack({ 0, 0 }, 1, &shot);
	path.PushBack({ 0, 0 }, 1, &shot);
	path.PushBack({ 0, 0 }, 1, &shot);
	path.PushBack({ 0.0f, 0.756f }, 50, &sail);
	path.PushBack({ 0, 0 }, 1, &shot);
	path.PushBack({ 0, 0 }, 1, &shot);
	path.PushBack({ 0, 0 }, 1, &shot);
	path.PushBack({ 0, 0 }, 1, &shot);
	path.PushBack({ 0, 0 }, 1, &shot);
	path.PushBack({ 0, 0 }, 1, &shot);

	path.loop = false;
}

void BigBoat::Move()
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
		if (animation == &shot && player2_y >= 0)
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
