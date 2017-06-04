#include "Application.h"
#include "Bomb.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"

#include "ModuleInput.h"

Bomb::Bomb(int x, int y) : Enemy(x, y)
{
	bomb.PushBack({ 599,152,24,34 });
	bomb.PushBack({ 623,152,24,34 });
	bomb.PushBack({ 645,152,24,34 });
	bomb.PushBack({ 599,198,24,34 });
	bomb.PushBack({ 623,198,24,34 });
	bomb.PushBack({ 645,198,24,34 });
	bomb.PushBack({ 599,244,24,34 });
	bomb.PushBack({ 623,244,24,34 });
	bomb.PushBack({ 645,244,24,34 });
	bomb.PushBack({ 599,287,24,34 });
	bomb.PushBack({ 623,287,24,34 });
	bomb.PushBack({ 647,287,24,34 });
	bomb.PushBack({ 599,334,24,34 });
	bomb.PushBack({ 623,334,24,34 });
	bomb.PushBack({ 647,334,24,34 });
	//Explosion
	bombexplosion.PushBack({ 676,152,24,34 });
	bombexplosion.PushBack({ 700,152,24,34 });
	bombexplosion.PushBack({ 722,152,24,34 });
	//Moradas
	purplebomb.PushBack({ 675,197,24,34 });
	purplebomb.PushBack({ 701,197,24,34 });
	purplebomb.PushBack({ 724,197,24,34 });

	bomb.loop = true;
	bomb.speed = 0.1f;

	animation = &bomb;
	

	collider = App->collision->AddCollider({ 0, 0, 15, 13 }, COLLIDER_TYPE::COLLIDER_ENEMY_BASIC, (Module*)App->enemies);
	collider->life_units = 1;

	original_pos.x = x;
	original_pos.y = y;


}

void Bomb::Move()
{


	position.y = position.y-1;

}
