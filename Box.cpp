#include "Application.h"
#include "Box.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"

#include "ModuleInput.h"

Box::Box(int x, int y) : Enemy(x, y)
{
	box.PushBack({ 431,224,26,24 });
	box.PushBack({ 464,224,26,24 });
	
	box.loop = true;
	box.speed = 0.1f;

	animation = &box;
	

	collider = App->collision->AddCollider({ 0, 0, 15, 13 }, COLLIDER_TYPE::COLLIDER_BOX, (Module*)App->enemies);
	collider->life_units = 1;

	original_pos.x = x;
	original_pos.y = y;


}

void Box::Move()
{


	position.y = position.y-1;

}
