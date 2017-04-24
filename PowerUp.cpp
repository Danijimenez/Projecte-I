#include "Application.h"
#include "PowerUp.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"

#include "ModuleInput.h"

PowerUp::PowerUp(int x, int y) : Enemy(x, y)
{
	power_up.PushBack({ 534,281,15,13 });
	power_up.PushBack({ 554,281,15,13 });
	power_up.PushBack({ 574,281,15,13 });
	power_up.loop = true;
	power_up.speed = 0.1f;

	animation = &power_up;
	

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

void PowerUp::Move()
{

//	original_pos.y -= 1;
	position = original_pos + path.GetCurrentPosition();

}
