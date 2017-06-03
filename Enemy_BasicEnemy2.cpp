#include "Application.h"
#include "Enemy_BasicEnemy2.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleInput.h"

BasicEnemy2::BasicEnemy2(int x, int y) : Enemy(x, y)
{

	//Change
	anim[0].PushBack({ 7,498,30,30 });
	anim[0].PushBack({ 53,498,30,30 });
	anim[0].PushBack({ 102,498,30,30 });
	anim[0].PushBack({ 149,498,30,30 });
	anim[0].loop = true;

	anim[1].PushBack({ 8,537,30,30 });
	anim[1].PushBack({ 57,537,30,30 }); 
	anim[1].PushBack({ 103,537,30,30 });
	anim[1].PushBack({ 152,537,30,30 });
	anim[1].loop = true;

	anim[2].PushBack({ 8,577,30,30 });
	anim[2].PushBack({ 57,577,30,30 });
	anim[2].PushBack({ 103,577,30,30 });
	anim[2].PushBack({ 153,577,30,30 });
	anim[2].loop = true;

	anim[3].PushBack({ 214,460,30,30 });
	anim[3].PushBack({ 262,460,30,30 }); 
	anim[3].PushBack({ 309,460,30,30 });
	anim[3].PushBack({ 357,460,30,30 });
	anim[3].loop = true;

	anim[4].PushBack({ 216,502,30,30 });
	anim[4].PushBack({ 265,502,30,30 });
	anim[4].PushBack({ 311,502,30,30 });
	anim[4].PushBack({ 360,502,30,30 });
	anim[4].loop = true;

	anim[5].PushBack({ 220,541,30,30 });
	anim[5].PushBack({ 269,541,30,30 });
	anim[5].PushBack({ 315,541,30,30 });
	anim[5].PushBack({ 365,541,30,30 });
	anim[5].loop = true;

	anim[6].PushBack({ 219,578,30,30 });
	anim[6].PushBack({ 271,578,30,30 });
	anim[6].PushBack({ 314,578,30,30 });
	anim[6].PushBack({ 367,578,30,30 });
	anim[6].loop = true;

	anim[7].PushBack({ 142,276,30,30 });
	anim[7].PushBack({ 96,276,30,30 });
	anim[7].PushBack({ 51,276,30,30 });
	anim[7].PushBack({ 9,276,30,30 });
	anim[7].loop = true;

	anim[8].PushBack({ 147,317,30,30 });
	anim[8].PushBack({ 97,317,30,30 });
	anim[8].PushBack({ 54,317,30,30 });
	anim[8].PushBack({ 11,317,30,30 });
	anim[8].loop = true;

	anim[9].PushBack({ 10,362,30,30 });
	anim[9].PushBack({ 55,362,30,30 });
	anim[9].PushBack({ 99,362,30,30 });
	anim[9].PushBack({ 148,362,30,30 });
	anim[9].loop = true;

	anim[10].PushBack({ 10,405,30,30 });
	anim[10].PushBack({ 56,405,30,30 });
	anim[10].PushBack({ 102,405,30,30 });
	anim[10].PushBack({ 149,405,30,30 });
	anim[10].loop = true;

	anim[11].PushBack({ 207,276,30,30 });
	anim[11].PushBack({ 254,276,30,30 });
	anim[11].PushBack({ 303,276,30,30 });
	anim[11].PushBack({ 350,276,30,30 });
	anim[11].loop = true;

	anim[12].PushBack({ 209,314,30,30 });
	anim[12].PushBack({ 254,314,30,30 });
	anim[12].PushBack({ 302,314,30,30 });
	anim[12].PushBack({ 350,314,30,30 });
	anim[12].loop = true;

	anim[13].PushBack({ 209,355,30,30 });
	anim[13].PushBack({ 258,355,30,30 });
	anim[13].PushBack({ 304,355,30,30 });
	anim[13].PushBack({ 351,355,30,30 });
	anim[13].loop = true;

	anim[14].PushBack({ 213,402,30,30 });
	anim[14].PushBack({ 258,402,30,30 });
	anim[14].PushBack({ 302,402,30,30 });
	anim[14].PushBack({ 349,402,30,30 });
	anim[14].loop = true;

	anim[15].PushBack({ 7,459,30,30 });
	anim[15].PushBack({ 53,459,30,30 });
	anim[15].PushBack({ 102,459,30,30 });
	anim[15].PushBack({ 148,459,30,30 });
	anim[15].loop = true;

	animation = &anim[15];

	collider = App->collision->AddCollider({ 0, 0, 32, 30 }, COLLIDER_TYPE::COLLIDER_ENEMY_BASIC, (Module*)App->enemies);
	collider->life_units = 1;

	original_pos.x = x;
	original_pos.y = y;

	path.PushBack({ 0.46428f, 0 }, 312);
	

	path.loop = false;
}

void BasicEnemy2::Move()
{

	// Aim

	if (aim) {
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

	// Move

	if (App->player->movep) {

		if (path.finished) {
			aim = true;
			if (!direction) {


				speed_x_mult = (App->player->position.x - position.x);
				speed_y_mult = (App->player->position.y - position.y);

				a_mult = sqrt((pow(speed_x_mult, 2) + pow(speed_y_mult, 2)));

				common_mult = (proj_speed / a_mult);
				direction = true;
			}
			
			position.x += (common_mult * speed_x_mult);

			position.y += (common_mult * speed_y_mult);
		}

		else {
//			original_pos.y -= 1;
			position = original_pos + path.GetCurrentPosition();
		}



	}
}
