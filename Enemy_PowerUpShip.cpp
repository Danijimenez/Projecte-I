#include "Application.h"
#include "Enemy_PowerUpShip.h"
#include "ModuleCollision.h"



PowerUpShip::PowerUpShip(int x, int y) : Enemy(x, y)
{

	//Animation
	fly.PushBack({ 11,2,56,58 });
	fly.PushBack({ 76,2,56,58 });
	fly.PushBack({ 144,2,56,58 });
	fly.PushBack({ 211,2,56,58 });
	fly.PushBack({ 272,2,56,58 });
	fly.PushBack({ 339,2,56,58 });
	fly.PushBack({ 403,2,56,58 });
	fly.PushBack({ 12,63,56,58 });
	fly.PushBack({ 79,63,56,58 });
	fly.speed = 0.2f;

	shoot.PushBack({ 12,125,56,58 });
	shoot.PushBack({ 79,125,56,58 });
	shoot.PushBack({ 143,125,56,58 });
	shoot.PushBack({ 208,125,56,58 });
	shoot.PushBack({ 273,125,56,58 });
	shoot.PushBack({ 339,125,56,58 });
	shoot.speed = 0.2f;

	leave.PushBack({ 12,189,56,58 });
	leave.PushBack({ 79,189,56,58 });
	leave.PushBack({ 142,189,56,58 });
	leave.PushBack({ 208,189,56,58 });
	shoot.speed = 0.01f;


	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 56, 58 }, COLLIDER_TYPE::COLLIDER_ENEMY_POWERUPSHIP, (Module*)App->enemies);
	collider->life_units = 5;

	original_pos.x = x;
	original_pos.y = y;


	//path
	path.PushBack({ -1, -0.0 }, 100, &fly);
	path.PushBack({ 1, -0.0 }, 100, &shoot);
	path.PushBack({ -1, 1.0 }, 300, &fly);
//	path.PushBack({ 0, -1.0 }, 240, &leave);
}

void PowerUpShip::Move()
{
	position = original_pos + path.GetCurrentPosition(&animation);

}
