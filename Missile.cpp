#include "Application.h"
#include "Missile.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"

#include "ModuleInput.h"

Missile::Missile(int x, int y) : Enemy(x, y)
{
	nuclear.PushBack({ 534,281,15,13 });
	nuclear.PushBack({ 554,281,15,13 });
	nuclear.PushBack({ 574,281,15,13 });
	nuclear.loop = true;
	nuclear.speed = 0.1f;

	animation = &nuclear;
	

	collider = App->collision->AddCollider({ 0, 0, 15, 13 }, COLLIDER_TYPE::COLLIDER_POWER_UP, (Module*)App->enemies);
	collider->life_units = 1;

	original_pos.x = x;
	original_pos.y = y;

	path.PushBack({ +0.48f, -0.48f }, 64);
	path.PushBack({ -0.48f, -0.48f }, 64);
	path.PushBack({ -0.48f, +0.48f }, 64);
	path.PushBack({ +0.48f, +0.48f }, 64);
	path.loop = true;
}

void Missile::Move()
{

//	original_pos.y -= 1;
	position = original_pos + path.GetCurrentPosition();

}
