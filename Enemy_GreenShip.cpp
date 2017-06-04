#include "Application.h"
#include "Enemy_GreenShip.h"
#include "ModuleCollision.h"
#include "ModuleInput.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"
#include "ModulePlayer2.h"



GreenShip::GreenShip(int x, int y) : Enemy(x, y)
{

	//Animation
	fly.PushBack({ 401,318,72,53 });
	fly.PushBack({ 478,318,72,53 });
	fly.speed = 0.2f;

	leave.PushBack({ 403,381,72,53 });
	leave.PushBack({ 481,381,72,53 });
	leave.PushBack({ 559,381,72,53 });
	leave.PushBack({ 638,381,72,53 });
	leave.PushBack({ 718,381,72,53 });
	leave.speed = 0.2f;

	back.PushBack({ 404,452,72,53 });
	back.PushBack({ 481,452,72,53 });
	back.PushBack({ 558,452,72,53 });
	back.PushBack({ 638,452,72,53 });
	back.speed = 0.2f;

	shot.PushBack({ 478,318,72,53 });


	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 72, 52 }, COLLIDER_TYPE::COLLIDER_ENEMY_GREENSHIP, (Module*)App->enemies);
	collider->life_units = 20;

	original_pos.x = x;
	original_pos.y = y;


	//path

	path.PushBack({ 0.0f, 0.756f }, 50, &fly);
	path.PushBack({ 0, 0 }, 1, &shot);
	path.PushBack({ 0, 0 }, 1, &shot);
	path.PushBack({ 0, 0 }, 1, &shot);
	path.PushBack({ 0, 0 }, 1, &shot);
	path.PushBack({ 0, 0 }, 1, &shot);
	path.PushBack({ 0, 0 }, 1, &shot);
	path.PushBack({ 0.0f, 0.756f }, 50, &fly);
	path.PushBack({ 0, 0 }, 1, &shot);
	path.PushBack({ 0, 0 }, 1, &shot);
	path.PushBack({ 0, 0 }, 1, &shot);
	path.PushBack({ 0, 0 }, 1, &shot);
	path.PushBack({ 0, 0 }, 1, &shot);
	path.PushBack({ 0, 0 }, 1, &shot);
	path.PushBack({ 0.0f, 0.756f }, 50, &fly);
	path.PushBack({ 0, 0 }, 1, &shot);
	path.PushBack({ 0, 0 }, 1, &shot);
	path.PushBack({ 0, 0 }, 1, &shot);
	path.PushBack({ 0, 0 }, 1, &shot);
	path.PushBack({ 0, 0 }, 1, &shot);
	path.PushBack({ 0, 0 }, 1, &shot);
	path.PushBack({ -1.07f, 1.214f }, 100, &leave);
	path.PushBack({ 0.0f, -0.75f }, 500, &back);

	path.loop = false;
}

void GreenShip::Move()
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




			speed_x_mult = (App->player->position.x - position.x - 60);
			speed_y_mult = (App->player->position.y - position.y + 20);

			a_mult = sqrt((pow(speed_x_mult, 2) + pow(speed_y_mult, 2)));

			common_mult = (proj_speed / a_mult);

			App->particles->enemy_shot.speed.x = (common_mult * speed_x_mult);

			App->particles->enemy_shot.speed.y = (common_mult * speed_y_mult);

			if (App->particles->enemy_shot.speed.x != 0 && App->particles->enemy_shot.speed.y != 0) {

				App->particles->AddParticle(App->particles->enemy_shot, position.x + 60, position.y + 30, COLLIDER_ENEMY_SHOT, 0);
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
				App->particles->AddParticle(App->particles->laser2, position.x + 11, position.y + 10, COLLIDER_ENEMY_SHOT, 0);
		}
		break;
	}



	position = original_pos + path.GetCurrentPosition(&animation);

}
