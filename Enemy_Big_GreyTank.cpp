#include "Application.h"
#include "Enemy_GreyTank_Base.h"
#include "ModuleCollision.h"
#include "Enemy_Big_GreyTank.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"


Big_GreyTank::Big_GreyTank(int x, int y, int path_type) : Enemy(x, y)
{
	//Change

	Prepare.PushBack({ 1073,20,76,49 });

	Open.PushBack({ 1073,20,76,49 });
	Open.PushBack({ 1163,17,76,49 });
	Open.PushBack({ 1252,19,76,49 });
	Open.PushBack({ 1354,18,76,49 });
	Open.PushBack({ 1470,19,76,49 });
	Open.PushBack({ 1068,126,76,49 });
	Open.PushBack({ 1171,122,76,49 });
	Open.PushBack({ 1291,122,76,49 });
	Open.PushBack({ 1419,123,76,49 });
	Open.PushBack({ 1126,201,76,49 });



	Open.speed = 0.1f;

	Moving.PushBack({ 886,17,76,49 });
	Moving.PushBack({ 970,18,76,49 });
	Moving.PushBack({ 888,72,76,49 });
	Moving.PushBack({ 968,126,76,49 });
	Moving.PushBack({ 886,124,76,49 });
	Moving.PushBack({ 886,177,76,49 });
	Moving.PushBack({ 969,178,76,49 });
	Moving.PushBack({ 887,230,76,49 });

	Shoot.PushBack({ 887,230,76,49 });


	animation = &Open;
	hittable = true;


	collider = App->collision->AddCollider({ 0, 0, 76, 49 }, COLLIDER_TYPE::COLLIDER_ENEMY_TANK, (Module*)App->enemies);
	collider->life_units = 50;

	original_pos.x = x;
	original_pos.y = y;

	//Change path
	path.PushBack({ -1.0833f, 0 }, 100, &Prepare);

	path.PushBack({ 0, 0 }, 50, &Open);

	path.PushBack({ 0,-1.0833f }, 45, &Moving);

	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);


	path.PushBack({ 0,-1.0833f }, 45, &Moving);

	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);

	path.PushBack({ 0,-1.0833f }, 45, &Moving);

	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);


	path.PushBack({ 0,-1.0833f }, 45, &Moving);

	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);

	path.PushBack({ 0,-1.0833f }, 45, &Moving);

	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);

	path.PushBack({ 0,-1.0833f }, 45, &Moving);

	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);

	path.PushBack({ 0,-1.0833f }, 45, &Moving);

	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);


	path.PushBack({ 0,-1.0833f }, 45, &Moving);

	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);

	path.PushBack({ 0, 1.0833f }, 45, &Moving);

	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);

	path.PushBack({ 0, 1.0833f }, 45, &Moving);

	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 1, &Shoot);

	path.PushBack({ 0, 1.0833f }, 1, &Moving);

	path.loop = false;

}


void Big_GreyTank::Move()
{

	if (animation == &Shoot) {
		shot_type++;
		relative_position = position;
		//Decide player to shoot;

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

		switch (target)
		{
		case 0:
			break;
		case 1:

			switch (shot_type) {
			case 1:
				relative_position.x = position.x + 31;
				relative_position.y = position.y + 12;

				break;
			case 2:
				relative_position.x = position.x + 39;
				relative_position.y = position.y + 12;

				break;
			case 3:
				relative_position.x = position.x + 45;
				relative_position.y = position.y + 12;

				break;
			case 4:

				relative_position.x = position.x + 45;
				relative_position.y = position.y + 24;

				break;
			case 5:
				relative_position.x = position.x + 39;
				relative_position.y = position.y + 31;

				break;
			case 6:
				relative_position.x = position.x + 31;
				relative_position.y = position.y + 31;

				break;
			case 7:
				relative_position.x = position.x + 25;
				relative_position.y = position.y + 24;

				break;
			case 8:
				relative_position.x = position.x + 25;
				relative_position.y = position.y + 17;
				shot_type = 0;
				break;

			default:
				break;
			}


			speed_x_mult = (App->player->position.x - relative_position.x);
			speed_y_mult = (App->player->position.y - relative_position.y);

			a_mult = sqrt((pow(speed_x_mult, 2) + pow(speed_y_mult, 2)));

			common_mult = (proj_speed / a_mult);

			App->particles->enemy_shot.speed.x = (common_mult * speed_x_mult);

			App->particles->enemy_shot.speed.y = (common_mult * speed_y_mult);

			if (App->particles->enemy_shot.speed.x != 0 && App->particles->enemy_shot.speed.y != 0)
				App->particles->AddParticle(App->particles->enemy_shot, relative_position.x + 11, relative_position.y + 10, COLLIDER_ENEMY_SHOT, 0);

			break;

		case 2:

			switch (shot_type) {
			case 1:
				relative_position.x = position.x + 31;
				relative_position.y = position.y + 12;

				break;
			case 2:
				relative_position.x = position.x + 39;
				relative_position.y = position.y + 12;


				break;
			case 3:
				relative_position.x = position.x + 45;
				relative_position.y = position.y + 12;

				break;
			case 4:

				relative_position.x = position.x + 45;
				relative_position.y = position.y + 24;

				break;
			case 5:
				relative_position.x = position.x + 39;
				relative_position.y = position.y + 31;

				break;
			case 6:
				relative_position.x = position.x + 31;
				relative_position.y = position.y + 31;

				break;
			case 7:
				relative_position.x = position.x + 25;
				relative_position.y = position.y + 24;

				break;
			case 8:
				relative_position.x = position.x + 25;
				relative_position.y = position.y + 17;

				break;

			default:
				break;
			}




			speed_x_mult = (App->player->position.x - relative_position.x);
			speed_y_mult = (App->player->position.y - relative_position.y);

			a_mult = sqrt((pow(speed_x_mult, 2) + pow(speed_y_mult, 2)));

			common_mult = (proj_speed / a_mult);

			App->particles->enemy_shot.speed.x = (common_mult * speed_x_mult);

			App->particles->enemy_shot.speed.y = (common_mult * speed_y_mult);

			if (App->particles->enemy_shot.speed.x != 0 && App->particles->enemy_shot.speed.y != 0)
				App->particles->AddParticle(App->particles->enemy_shot, relative_position.x + 11, relative_position.y + 10, COLLIDER_ENEMY_SHOT, 0);

			break;


		default:
			break;
		}


	}
	original_pos.y += 0.2f;
	position = original_pos + path.GetCurrentPosition(&animation);

}

