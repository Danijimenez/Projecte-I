#include "Application.h"
#include "Enemy_GreenShip.h"
#include "ModuleCollision.h"



GreenShip::GreenShip(int x, int y) : Enemy(x, y)
{

	//Animation
	fly.PushBack({ 100,100,10,10 });

	fly.speed = 0.2f;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 10, 10 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;


	//path
	path.PushBack({ -0.5f, 0.0 }, 240);
	path.PushBack({ 0.5f, 0.0 }, 240);
}

void GreenShip::Move()
{

	position = original_pos + path.GetCurrentPosition();

}
