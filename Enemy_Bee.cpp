#include "Application.h"
#include "Enemy_Bee.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleInput.h"

Bee::Bee(int x, int y) : Enemy(x, y)
{

	//Change

	spawn.PushBack({ 413,925,32,39 });
	spawn.PushBack({ 447,924,32,39 });
	spawn.PushBack({ 483,925,32,39 });
	spawn.PushBack({ 523,927,32,39 });
	spawn.speed = 0.5f;


	charge.PushBack({ 416,972,32,29 });
	charge.PushBack({ 460,972,32,29 });	
	charge.PushBack({ 500,972,32,29 });

	leave.PushBack({ 540,972,32,39 });
	leave.PushBack({ 580,972,32,39 });
	leave.loop = true;

	collider = App->collision->AddCollider({ 0, 0, 32, 39 }, COLLIDER_TYPE::COLLIDER_ENEMY_BASIC, (Module*)App->enemies);
	collider->life_units = 1;

	path.PushBack({ 0.5f,-0.5f }, 20, &spawn);
	path.PushBack({ -0.2f, 0.2f}, 15, &charge);
	path.PushBack({ 0,0 }, 1, &leave);
	path.loop = false;

	original_pos = position;
}

void Bee::Move()
{

	if (path.finished && !direction) {


		speed_x_mult = (App->player->position.x - position.x);
		speed_y_mult = (App->player->position.y - position.y);

		a_mult = sqrt((pow(speed_x_mult, 2) + pow(speed_y_mult, 2)));

		common_mult = (proj_speed / a_mult);
		direction = true;
	}

	original_pos.x += (common_mult * speed_x_mult);

	original_pos.y += (common_mult * speed_y_mult);

	if (App->player->movep)
		original_pos.y -= 1;

	position = original_pos + path.GetCurrentPosition(&animation);

}