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

	charge.PushBack({ 416,972,32,29 });
	charge.PushBack({ 460,972,32,29 });	
	charge.PushBack({ 500,972,32,29 });

	leave.PushBack({ 540,972,32,39 });
	leave.PushBack({ 580,972,32,39 });
	leave.loop = true;

	collider = App->collision->AddCollider({ 0, 0, 32, 30 }, COLLIDER_TYPE::COLLIDER_ENEMY_BASIC, (Module*)App->enemies);
	collider->life_units = 1;


}

void Bee::Move()
{

	if (!direction) {


		speed_x_mult = (App->player->position.x - position.x);
		speed_y_mult = (App->player->position.y - position.y);

		a_mult = sqrt((pow(speed_x_mult, 2) + pow(speed_y_mult, 2)));

		common_mult = (proj_speed / a_mult);
		direction = true;
	}

	position.x += (common_mult * speed_x_mult);

	position.y += (common_mult * speed_y_mult);

	if (App->player->movep)
		position.y -= 1;
}