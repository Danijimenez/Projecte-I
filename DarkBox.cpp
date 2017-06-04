#include "Application.h"
#include "DarkBox.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"

#include "ModuleInput.h"

DarkBox::DarkBox(int x, int y) : Enemy(x, y)
{
	darkbox.PushBack({ 431,267,26,24 });
	darkbox.PushBack({ 464,267,26,24 });

	darkbox.loop = true;
	darkbox.speed = 0.1f;

	animation = &darkbox;


	collider = App->collision->AddCollider({ 0, 0, 15, 13 }, COLLIDER_TYPE::COLLIDER_BOX, (Module*)App->enemies);
	collider->life_units = 1;

	original_pos.x = x;
	original_pos.y = y;


}

void DarkBox::Move()
{


	position.y = position.y - 1;

}
