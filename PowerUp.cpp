#include "Application.h"
#include "PowerUp.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"

#include "ModuleInput.h"

PowerUp::PowerUp(int x, int y) : Enemy(x, y)
{
	laser.PushBack({ 534,281,15,13 });
	laser.PushBack({ 554,281,15,13 });
	laser.PushBack({ 574,281,15,13 });
	laser.loop = true;
	laser.speed = 0.1f;

	vulcan.PushBack({ 534,264,15,13 });
	vulcan.PushBack({ 554,264,15,13 });
	vulcan.PushBack({ 574,264,15,13 });
	vulcan.loop = true;
	vulcan.speed = 0.1f;

	bombamo.PushBack({ 516,176,16,14 });
	bombamo.PushBack({ 538,175,13,16 });
	bombamo.PushBack({ 553,175,13,15 });
	bombamo.PushBack({ 570,177,16,13 });
	bombamo.loop = true;
	bombamo.speed = 0.1f;

	animation = &laser;
	

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
