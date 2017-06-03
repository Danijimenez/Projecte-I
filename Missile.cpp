#include "Application.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"

#include "ModuleInput.h"

{

	

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

{

//	original_pos.y -= 1;
	position = original_pos + path.GetCurrentPosition();

}
