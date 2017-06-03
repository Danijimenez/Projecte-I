#include "Application.h"
#include "Enemy_GreyTank_Base.h"
#include "ModuleCollision.h"
#include "Enemy_Boss.h"


Boss::Boss(int x, int y) : Enemy(x, y)
{




	hittable = true;


	collider = App->collision->AddCollider({ 0, 0, 76, 49 }, COLLIDER_TYPE::COLLIDER_ENEMY_TANK, (Module*)App->enemies);
	collider->life_units = 8;

	original_pos.x = x;
	original_pos.y = y;

	//Change path




}

void Boss::Move()
{

	position = original_pos + path.GetCurrentPosition(&animation);

}

