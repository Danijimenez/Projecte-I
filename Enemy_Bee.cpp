#include "Application.h"
#include "Enemy_Bee.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleInput.h"

Bee::Bee(int x, int y) : Enemy(x, y)
{

	//Change

	spawn.PushBack({ 413,925,32,39 });
	spawn.PushBack({ 447,924,32,39 });
	spawn.PushBack({ 483,925,32,39 });
	spawn.PushBack({ 523,927,32,39 });

	charge.PushBack({ 416,972,32,29 });
	charge.PushBack({ 460,972,32,29 });	
	charge.PushBack({ 500,972,32,29 });

	leave.PushBack({ 540,972,32,39 });
	leave.PushBack({ 580,972,32,39 });

	collider = App->collision->AddCollider({ 0, 0, 32, 30 }, COLLIDER_TYPE::COLLIDER_ENEMY_BASIC, (Module*)App->enemies);
	collider->life_units = 1;

	original_pos.x = x;
	original_pos.y = y;

	path.PushBack({ -0.21f, +2.08f }, 90);
	path.PushBack({ 0.0f, 0.0f }, 40);
	path.PushBack({ -0.05f, -1.392f }, 135);
	path.loop = false;
}

void Bee::Move()
{	

	position = original_pos + path.GetCurrentPosition();

}
