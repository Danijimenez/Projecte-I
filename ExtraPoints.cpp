#include "Application.h"
#include "ExtraPoints.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"

#include "ModuleInput.h"

ExtraPoints::ExtraPoints(int x, int y) : Enemy(x, y)
{
	medal.PushBack({ 572,202,16,16 });
	medal.loop = true;
	medal.speed = 0.1f;

	miclus.PushBack({ 533,201,16,16 });
	miclus.PushBack({ 550,201,16,16 });
	miclus.loop = true;
	miclus.speed = 0.1f;

	animation = &medal;
	

	collider = App->collision->AddCollider({ 0, 0, 16, 16 }, COLLIDER_TYPE::COLLIDER_EXTRA_POINTS, (Module*)App->enemies);
	collider->life_units = 1;

	original_pos.x = x;
	original_pos.y = y;

	path.PushBack({ +0.48f, -0.48f }, 64);
	path.PushBack({ -0.48f, -0.48f }, 64);
	path.PushBack({ -0.48f, +0.48f }, 64);
	path.PushBack({ +0.48f, +0.48f }, 64);
	path.loop = true;
}

void ExtraPoints::Move()
{

//	original_pos.y -= 1;
	position = original_pos + path.GetCurrentPosition();

}
