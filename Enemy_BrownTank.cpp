#include "Application.h"
#include "Enemy_BrownTank.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleInput.h"

BasicEnemy::BasicEnemy(int x, int y) : Enemy(x, y)
{
	anim[0].PushBack({ 27,511,32,30 });
	anim[1].PushBack({ 234,514,32,30 });
	anim[2].PushBack({ 24,548,32,30 });
	anim[3].PushBack({ 141,272,32,30 });
	anim[4].PushBack({ 64,589,32,30 });
	anim[5].PushBack({ 234,586,32,30 });
	anim[6].PushBack({ 67,624,32,30 });
	anim[7].PushBack({ 60,373,32,30 });
	anim[8].PushBack({ 55,343,32,30 });
	anim[9].PushBack({ 142,311,32,30 });
	anim[10].PushBack({ 81,309,32,30 });
	anim[11].PushBack({ 20,272,32,30 });
	anim[12].PushBack({ 26,408,32,30 });
	anim[13].PushBack({ 28,443,32,30 });
	anim[14].PushBack({ 66,475,32,30 });
	anim[15].PushBack({ 132,373,32,30 });


	collider = App->collision->AddCollider({ 0, 0, 32, 30 }, COLLIDER_TYPE::COLLIDER_ENEMY_BASIC, (Module*)App->enemies);
	collider->life_units = 1;

	original_pos.x = x;
	original_pos.y = y;

	path.PushBack({ -0.21f, +2.08f }, 90);
	path.PushBack({ 0.0f, 0.0f }, 40);
	path.PushBack({ -0.05f, -1.392f }, 135);
	path.loop = false;
}

void BasicEnemy::Move()
{
	fPoint current_pos = path.GetCurrentPosition();
	if (App->player->movep) {
		original_pos.y -= 1;
		position = original_pos + current_pos;
	}



	if (App->player->living && !App->player2->living) {
		if (App->player->position.y > position.y) {

			float angle = atan2(App->player->position.y - position.y, App->player->position.x - position.x);
			angle *= 180 / 3.14;

			uint k = 15;
			for (uint i = 0; i < 16; i++) {
				k--;
				if (angle >= ((i*22.5) + 11.25) && angle <= (((i + 1)*22.5) + 11.25)) {

					animation = &anim[k];

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

					animation = &anim[k];

					break;

				}
				k--;
			}
		}
	}

	//Player 2 only

	else if (App->player2->living && !App->player->living) {
		if (App->player2->position.y > position.y) {

			float angle = atan2(App->player2->position.y - position.y, App->player2->position.x - position.x);
			angle *= 180 / 3.14;

			uint k = 15;
			for (uint i = 0; i < 16; i++) {
				k--;
				if (angle >= ((i*22.5) + 11.25) && angle <= (((i + 1)*22.5) + 11.25)) {

					animation = &anim[k];

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

					animation = &anim[k];

					break;

				}
				k--;
			}
		}
	}

	// Both players

	else {
		//Decide player to shoot

		int player1_x = (App->player->position.x - position.x);
		int player1_y = (App->player->position.y - position.y);

		int player2_x = (App->player2->position.x - position.x);
		int player2_y = (App->player2->position.y - position.y);

		//Player 1
		if (pow(player1_x, 2) + pow(player1_y, 2) <= pow(player2_x, 2) + pow(player2_y, 2)) {

			if (App->player->position.y > position.y) {

				float angle = atan2(App->player->position.y - position.y, App->player->position.x - position.x);
				angle *= 180 / 3.14;

				uint k = 15;
				for (uint i = 0; i < 16; i++) {
					k--;
					if (angle >= ((i*22.5) + 11.25) && angle <= (((i + 1)*22.5) + 11.25)) {

						animation = &anim[k];

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

						animation = &anim[k];

						break;

					}
					k--;
				}
			}


		}
		// player 2

		else {

			if (App->player2->position.y > position.y) {

				float angle = atan2(App->player2->position.y - position.y, App->player2->position.x - position.x);
				angle *= 180 / 3.14;

				uint k = 15;
				for (uint i = 0; i < 16; i++) {
					k--;
					if (angle >= ((i*22.5) + 11.25) && angle <= (((i + 1)*22.5) + 11.25)) {

						animation = &anim[k];

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

						animation = &anim[k];

						break;

					}
					k--;
				}
			}
		}
	}


}
