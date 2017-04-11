#include "Application.h"
#include "Enemy_BasicEnemy.h"
#include "ModuleCollision.h"



BasicEnemy::BasicEnemy(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 100,100,26,26 });

	fly.speed = 0.2f;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 26, 26 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;

	path.PushBack({ -0.3f, +2.469f }, 66);
	path.PushBack({ 0.0f, 0.0f }, 68);
	path.PushBack({ -0.05f, -1.63f }, 100);
}

void BasicEnemy::Move()
{
	original_pos.y -= 1;
	position = original_pos + path.GetCurrentPosition();

}
