#include "Application.h"
#include "Missile.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"

#include "ModuleInput.h"

Missile::Missile(int x, int y) : Enemy(x, y)
{
	nuclear.PushBack({ 533,228,16,13 });
	nuclear.PushBack({ 553,228,16,13 });
	nuclear.PushBack({ 573,228,16,13 });
	nuclear.loop = true;
	nuclear.speed = 0.1f;

	homing.PushBack({ 534,247,16,13 });
	homing.PushBack({ 553,247,16,13 });
	homing.PushBack({ 573,247,16,13 });
	homing.loop = true;
	homing.speed = 0.1f;

	animation = &nuclear;
	

	collider = App->collision->AddCollider({ 0, 0, 16, 13 }, COLLIDER_TYPE::COLLIDER_MISSILE, (Module*)App->enemies);
	collider->life_units = 1;

	original_pos.x = x;
	original_pos.y = y;

	path.PushBack({ +0.48f, -0.48f }, 64, &nuclear);
	path.PushBack({ -0.48f, -0.48f }, 64, &nuclear);
	path.PushBack({ -0.48f, +0.48f }, 64, &nuclear);
	path.PushBack({ +0.48f, +0.48f }, 64, &nuclear);

	path.PushBack({ +0.48f, -0.48f }, 64, &nuclear);
	path.PushBack({ -0.48f, -0.48f }, 64, &nuclear);
	path.PushBack({ -0.48f, +0.48f }, 64, &nuclear);
	path.PushBack({ +0.48f, +0.48f }, 64, &nuclear);

	path.PushBack({ +0.48f, -0.48f }, 64, &nuclear);
	path.PushBack({ -0.48f, -0.48f }, 64, &nuclear);
	path.PushBack({ -0.48f, +0.48f }, 64, &nuclear);
	path.PushBack({ +0.48f, +0.48f }, 64, &nuclear);

	path.PushBack({ +0.48f, -0.48f }, 64, &homing);
	path.PushBack({ -0.48f, -0.48f }, 64, &homing);
	path.PushBack({ -0.48f, +0.48f }, 64, &homing);
	path.PushBack({ +0.48f, +0.48f }, 64, &homing);

	path.PushBack({ +0.48f, -0.48f }, 64, &homing);
	path.PushBack({ -0.48f, -0.48f }, 64, &homing);
	path.PushBack({ -0.48f, +0.48f }, 64, &homing);
	path.PushBack({ +0.48f, +0.48f }, 64, &homing);

	path.PushBack({ +0.48f, -0.48f }, 64, &homing);
	path.PushBack({ -0.48f, -0.48f }, 64, &homing);
	path.PushBack({ -0.48f, +0.48f }, 64, &homing);
	path.PushBack({ +0.48f, +0.48f }, 64, &homing);

}

void Missile::Move()
{

	if (animation == &nuclear)
	{
		collider->type = COLLIDER_MISSILE_NUCLEAR;
	}
	else
	{
		collider->type = COLLIDER_MISSILE_HOMING;
	}

	position = original_pos + path.GetCurrentPosition();

}
