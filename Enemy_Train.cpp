#include "Application.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "Enemy_Train.h"
#include "ModuleEnemies_Ground.h"


Train::Train(int x, int y) : Enemy(x, y)
{
	//Change
	train.PushBack({ 404,515,75,23 });
	train.PushBack({ 486,515,75,23 });
	train.PushBack({ 566,515,75,23 });
	train.PushBack({ 646,515,75,23 });
	train.PushBack({ 404,546,75,23 });
	train.PushBack({ 486,546,75,23 });
	train.PushBack({ 566,546,75,23 });
	train.PushBack({ 646,546,75,23 });
	train.PushBack({ 404,579,75,23 });

	hittable = true;


	collider = App->collision->AddCollider({ 0, 0, 75, 23 }, COLLIDER_TYPE::COLLIDER_ENEMY_WAGON, (Module*)App->enemies);
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