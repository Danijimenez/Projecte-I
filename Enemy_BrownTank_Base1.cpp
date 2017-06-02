#include "Application.h"
#include "Enemy_BrownTank_Base1.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "Enemy_TankTurret.h"

BrownTank_Base::BrownTank_Base(int x, int y, int path_type) : Enemy(x, y)
{
	//Change
	Brown_Tank.PushBack({ 534,281,15,13 });
	Brown_Tank.PushBack({ 554,281,15,13 });
	Brown_Tank.PushBack({ 574,281,15,13 });
	Brown_Tank.loop = true;
	Brown_Tank.speed = 0.1f;

	animation = &Brown_Tank;
	hittable = false;

	turret = new Tank_Turret(x, y);


	collider = App->collision->AddCollider({ 0, 0, 15, 13 }, COLLIDER_TYPE::COLLIDER_POWER_UP, (Module*)App->enemies);
	collider->life_units = 8;

	original_pos.x = x;
	original_pos.y = y;

	//Change path && anim
	switch (path_type){
	case 1:
		path.PushBack({ +0.48f, -0.48f }, 64);
		path.PushBack({ -0.48f, -0.48f }, 64);
		path.PushBack({ -0.48f, +0.48f }, 64);
		path.PushBack({ +0.48f, +0.48f }, 64);
		path.loop = true;
		break;
	case 2:
		path.PushBack({ +0.48f, -0.48f }, 64);
		path.PushBack({ -0.48f, -0.48f }, 64);
		path.PushBack({ -0.48f, +0.48f }, 64);
		path.PushBack({ +0.48f, +0.48f }, 64);
		path.loop = true;
		break;
	case 3:
		path.PushBack({ +0.48f, -0.48f }, 64);
		path.PushBack({ -0.48f, -0.48f }, 64);
		path.PushBack({ -0.48f, +0.48f }, 64);
		path.PushBack({ +0.48f, +0.48f }, 64);
		path.loop = true;
		break;
	case 4:
		path.PushBack({ +0.48f, -0.48f }, 64);
		path.PushBack({ -0.48f, -0.48f }, 64);
		path.PushBack({ -0.48f, +0.48f }, 64);
		path.PushBack({ +0.48f, +0.48f }, 64);
		path.loop = true;
		break;
	default:
		break;
	}

}

void BrownTank_Base::Move()
{

	position = original_pos + path.GetCurrentPosition();

	if (collider->life_units > 3)
	{
		turret->Move();
		turret->position = position;
	}
	else if (collider->life_units == 3)
	{
		delete turret;
		turret = nullptr;
	}
}