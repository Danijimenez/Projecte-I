#include "Application.h"
#include "Enemy_GreyTank_Base.h"
#include "ModuleCollision.h"
#include "Enemy_Big_GreyTank.h"


Big_GreyTank::Big_GreyTank(int x, int y, int path_type) : Enemy(x, y)
{
	//Change
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

/*	
	Open.PushBack({ 1419,123,76,49 });
	Open.PushBack({ 1291,122,76,49 });
	Open.PushBack({ 1171,122,76,49 });
	Open.PushBack({ 1068,126,76,49 });
	Open.PushBack({ 1470,19,76,49 });
	Open.PushBack({ 1354,18,76,49 });
	Open.PushBack({ 1252,19,76,49 });
	Open.PushBack({ 1163,17,76,49 });
*/

	Open.speed = 0.1f;
	
	Moving.PushBack({ 886,17,76,49 });
	Moving.PushBack({ 970,18,76,49 });
	Moving.PushBack({ 888,72,76,49 });
	Moving.PushBack({ 968,126,76,49 });
	Moving.PushBack({ 886,124,76,49 });
	Moving.PushBack({ 886,177,76,49 });
	Moving.PushBack({ 969,178,76,49 });
	Moving.PushBack({ 887,230,76,49 });



	animation = &Open;
	hittable = true;


	collider = App->collision->AddCollider({ 0, 0, 76, 49 }, COLLIDER_TYPE::COLLIDER_ENEMY_TANK, (Module*)App->enemies);
	collider->life_units = 8;

	original_pos.x = x;
	original_pos.y = y;

	//Change path




}

void Big_GreyTank::Move()
{

	position = original_pos + path.GetCurrentPosition(&animation);

}

