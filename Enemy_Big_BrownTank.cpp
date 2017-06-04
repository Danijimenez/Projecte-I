#include "Application.h"
#include "Enemy_GreyTank_Base.h"
#include "ModuleCollision.h"
#include "Enemy_Big_BrownTank.h"


Big_BrownTank::Big_BrownTank(int x, int y, int path_type) : Enemy(x, y)
{
	//Change
	BigBrown_Tank.PushBack({ 427,1110,48,47 });
	BigBrown_Tank.PushBack({ 497,1111,48,47 });
	BigBrown_Tank.PushBack({ 566,1111,48,47 });
	BigBrown_Tank.loop = true;
	BigBrown_Tank.speed = 0.1f;

	animation = &BigBrown_Tank;
	hittable = true;


	collider = App->collision->AddCollider({ 0, 0, 48, 47 }, COLLIDER_TYPE::COLLIDER_ENEMY_TANK, (Module*)App->enemies);
	collider->life_units = 30;

	original_pos.x = x;
	original_pos.y = y;

		

}

void Big_BrownTank::Move()
{

	

}

