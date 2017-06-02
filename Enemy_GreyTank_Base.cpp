#include "Application.h"
#include "Enemy_PowerUpShip.h"
#include "ModuleCollision.h"
#include "ModuleInput.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleParticles.h"


PowerUpShip::PowerUpShip(int x, int y) : Enemy(x, y)
{

	//Animation
	fly.PushBack({ 11,2,56,58 });
	fly.PushBack({ 76,2,56,58 });
	fly.PushBack({ 144,2,56,58 });
	fly.PushBack({ 211,2,56,58 });
	fly.PushBack({ 272,2,56,58 });
	fly.PushBack({ 339,2,56,58 });
	fly.PushBack({ 403,2,56,58 });
	fly.PushBack({ 12,63,56,58 });
	fly.PushBack({ 79,63,56,58 });
	fly.speed = 0.2f;

	shoot.PushBack({ 12,125,56,58 });
	shoot.PushBack({ 79,125,56,58 });
	shoot.PushBack({ 143,125,56,58 });
	shoot.PushBack({ 208,125,56,58 });
	shoot.PushBack({ 273,125,56,58 });
	shoot.PushBack({ 339,125,56,58 });
	shoot.speed = 0.2f;

	leave.PushBack({ 12,189,56,58 });
	leave.PushBack({ 79,189,56,58 });
	leave.PushBack({ 142,189,56,58 });
	leave.PushBack({ 208,189,56,58 });
	shoot.speed = 0.01f;


	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 56, 58 }, COLLIDER_TYPE::COLLIDER_ENEMY_POWERUPSHIP, (Module*)App->enemies);
	collider->life_units = 5;

	original_pos.x = x;
	original_pos.y = y;


	//path

	path.PushBack({ 0, +0.2638f }, 72, &fly);
	path.PushBack({ 0, -0.5f }, 37, &fly);
	path.PushBack({ -0.34065f, 0.28162f }, 91, &fly);
	path.PushBack({ 0,0 }, 1, &shoot);
	path.PushBack({ +0.34065f, 0.28162f }, 182, &fly);
	path.PushBack({ -0.34065f, 0.28162f }, 182, &fly);
	path.PushBack({ 0,0 }, 1, &shoot);
	path.PushBack({ +0.34065f, 0.28162f }, 182, &fly);
	path.PushBack({ -0.34065f, 0.28162f }, 91, &fly);
	path.PushBack({ 0, 1 }, 72, &fly);
	path.loop = false;
}

void PowerUpShip::Move()
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
		if (animation == &shoot)
		{
			float proj_speed = 4.0f;
			float speed_x_mult, speed_y_mult, common_mult, a_mult;

			speed_x_mult = (App->player->position.x - position.x);
			speed_y_mult = (App->player->position.y - position.y);

			a_mult = sqrt((pow(speed_x_mult, 2) + pow(speed_y_mult, 2)));

			common_mult = (proj_speed / a_mult);

			App->particles->enemy_shot.speed.x = (common_mult * speed_x_mult);

			App->particles->enemy_shot.speed.y = (common_mult * speed_y_mult);

			if (App->particles->enemy_shot.speed.x != 0 && App->particles->enemy_shot.speed.y != 0) {

				App->particles->AddParticle(App->particles->enemy_shot, position.x + 11, position.y + 10, COLLIDER_ENEMY_SHOT, 0);


				App->particles->enemy_shot.speed.x -= 1;
				App->particles->enemy_shot.speed.y -= 1;

				App->particles->AddParticle(App->particles->enemy_shot, position.x + 11, position.y + 10, COLLIDER_ENEMY_SHOT, 0);

				App->particles->enemy_shot.speed.x += 1;
				App->particles->enemy_shot.speed.y += 1;

				App->particles->AddParticle(App->particles->enemy_shot, position.x + 11, position.y + 10, COLLIDER_ENEMY_SHOT, 0);


			}
		}
		break;
	case 2:
		if (animation == &shoot)
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


			App->particles->enemy_shot.speed.x -= 1;
			App->particles->enemy_shot.speed.y -= 1;

			App->particles->AddParticle(App->particles->enemy_shot, position.x + 11, position.y + 10, COLLIDER_ENEMY_SHOT, 0);

			App->particles->enemy_shot.speed.x += 1;
			App->particles->enemy_shot.speed.y += 1;

			App->particles->AddParticle(App->particles->enemy_shot, position.x + 11, position.y + 10, COLLIDER_ENEMY_SHOT, 0);


		}
		break;

	}
	


	position = original_pos + path.GetCurrentPosition(&animation);

}
