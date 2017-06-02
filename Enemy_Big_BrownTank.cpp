#include "Application.h"
#include "Enemy_GreyTank_Base.h"
#include "ModuleCollision.h"
#include "Enemy_Big_BrownTank.h"


Big_BrownTank::Big_BrownTank(int x, int y, int path_type) : Enemy(x, y)
{
	//Change
	BigBrown_Tank.PushBack({ 534,281,15,13 });
	BigBrown_Tank.PushBack({ 554,281,15,13 });
	BigBrown_Tank.PushBack({ 574,281,15,13 });
	BigBrown_Tank.loop = true;
	BigBrown_Tank.speed = 0.1f;

	animation = &BigBrown_Tank;
	hittable = true;


	collider = App->collision->AddCollider({ 0, 0, 15, 13 }, COLLIDER_TYPE::COLLIDER_POWER_UP, (Module*)App->enemies);
	collider->life_units = 8;

	original_pos.x = x;
	original_pos.y = y;

		

}

void Big_BrownTank::Move()
{

	

}

