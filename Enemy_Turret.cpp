#include "Application.h"
#include "Enemy_Turret.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"


Turret::Turret(int x, int y) : Enemy(x, y)
{

	//Animation
	up.PushBack({ 116,36,22,21 });
	down.PushBack({ 76,36,22,21 });
	left.PushBack({ 155,35,22,21 });
	right.PushBack({ 74,75,22,21 });
	right_up.PushBack({ 157,73,22,21 });
	right_down.PushBack({ 116,105,22,21 });
	left_up.PushBack({ 156,173,22,21 });
	left_down.PushBack({ 74,107,22,21 });

	collider = App->collision->AddCollider({ 0, 0, 22, 21 }, COLLIDER_TYPE::COLLIDER_ENEMMY_TURRET, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;

	animation = &down;
	//path
	path.PushBack({ 0.0, 0.0 }, 240);
}

//22 28

void Turret::Move()
{
	if (position.x + 22 < App->player->position.x) {

		if (position.y > App->player->position.y + 28) {
			animation = &right_up;
		}

		else if (position.y + 21 < App->player->position.y) {
			animation = &right_down;
		}

		else {
			animation = &right;
		}
	}
	else if (position.x > App->player->position.x+28) {

		if (position.y > App->player->position.y + 28) {
			animation = &left_up;
		}

		else if (position.y + 21 < App->player->position.y) {
			animation = &left_down;
		}

		else {
			animation = &left;
		}
	}
	else if (position.y - 21 > App->player->position.y){
		animation = &up;
	}
	else {
		animation = &down;
	}

	//else if()
	position = original_pos + path.GetCurrentPosition();

}
