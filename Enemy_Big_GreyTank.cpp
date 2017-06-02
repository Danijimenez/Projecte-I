#include "Application.h"
#include "Enemy_GreyTank_Base.h"
#include "ModuleCollision.h"
#include "Enemy_Big_GreyTank.h"


Big_GreyTank::Big_GreyTank(int x, int y, int path_type) : Enemy(x, y)
{
	//Change
	Big_Grey_Tank.PushBack({ 534,281,15,13 });
	Big_Grey_Tank.PushBack({ 554,281,15,13 });
	Big_Grey_Tank.PushBack({ 574,281,15,13 });
	Big_Grey_Tank.loop = true;
	Big_Grey_Tank.speed = 0.1f;

	animation = &Big_Grey_Tank;
	hittable = true;


	collider = App->collision->AddCollider({ 0, 0, 15, 13 }, COLLIDER_TYPE::COLLIDER_POWER_UP, (Module*)App->enemies);
	collider->life_units = 8;

	original_pos.x = x;
	original_pos.y = y;

	//Change path

		path.PushBack({ +0.48f, -0.48f }, 64);
		path.PushBack({ -0.48f, -0.48f }, 64);
		path.PushBack({ -0.48f, +0.48f }, 64);
		path.PushBack({ +0.48f, +0.48f }, 64);

}

void Big_GreyTank::Move()
{

	position = original_pos + path.GetCurrentPosition(&animation);

}

