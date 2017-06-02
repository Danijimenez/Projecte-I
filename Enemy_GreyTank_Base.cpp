#include "Application.h"
#include "Enemy_GreyTank_Base.h"
#include "ModuleCollision.h"
#include "Enemy_Grey_TankTurret.h"


GreyTank_Base::GreyTank_Base(int x, int y, int path_type) : Enemy(x, y)
{
	//Change
	Grey_Tank.PushBack({ 534,281,15,13 });
	Grey_Tank.PushBack({ 554,281,15,13 });
	Grey_Tank.PushBack({ 574,281,15,13 });
	Grey_Tank.loop = true;
	Grey_Tank.speed = 0.1f;

	animation = &Grey_Tank;
	hittable = false;

	turret = new GreyTank_Turret(x, y);


	collider = App->collision->AddCollider({ 0, 0, 15, 13 }, COLLIDER_TYPE::COLLIDER_POWER_UP, (Module*)App->enemies);
	collider->life_units = 8;

	original_pos.x = x;
	original_pos.y = y;

	//Change path && anim
	switch (path_type) {
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

void GreyTank_Base::Move()
{

	position = original_pos + path.GetCurrentPosition(&animation);

}
