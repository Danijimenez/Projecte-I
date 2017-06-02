#include "Application.h"
#include "Enemy_Bee.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleInput.h"

Bee::Bee(int x, int y) : Enemy(x, y)
{

	//Change

	anim.PushBack({ 27,511,32,30 });



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

	position = original_pos + path.GetCurrentPosition(&animation);

}
