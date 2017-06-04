#include "Application.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "Enemy_Train.h"
#include "ModuleEnemies_Ground.h"


Train::Train(int x, int y) : Enemy(x, y)
{
	//Change
	train.PushBack({ 30,795,34,34 });
	train.PushBack({ 80,792,34,34 });
	train.PushBack({ 133,798,34,34 });
	train.PushBack({ 40,833,34,34 });
	train.PushBack({ 89,832,34,34 });
	train.PushBack({ 134,835,34,34 });
	train.PushBack({ 39,870,34,34 });
	train.PushBack({ 91,871,34,34 });

	hittable = true;


	collider = App->collision->AddCollider({ 0, 0, 34, 34 }, COLLIDER_TYPE::COLLIDER_ENEMY_WAGON, (Module*)App->enemies);
	collider->life_units = 8;

	original_pos.x = x;
	original_pos.y = y;



	path.PushBack({ -1.0833f , 0 }, 270, &train);
	path.loop = true;


}

void Train::Move()
{
	
	position = original_pos + path.GetCurrentPosition();

}