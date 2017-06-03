#include "Application.h"
#include "Enemy_GreyTank_Base.h"
#include "ModuleCollision.h"
#include "Enemy_Grey_TankTurret.h"
#include "ModuleEnemies_Ground.h"


GreyTank_Base::GreyTank_Base(int x, int y, int path_type) : Enemy(x, y)
{
	//Change
	Grey_Tank[0].PushBack({ 58,736,34,34 });
	Grey_Tank[1].PushBack({ 110,734,34,34 });
	Grey_Tank[2].PushBack({ 166,732,34,34 });


	animation = &Grey_Tank[0];
	hittable = false;

	turret = new GreyTank_Turret(x, y);


	collider = App->collision->AddCollider({ 0, 0, 15, 13 }, COLLIDER_TYPE::COLLIDER_ENEMY_TANK, (Module*)App->enemies);
	collider->life_units = 8;

	original_pos.x = x;
	original_pos.y = y;

	//Change path && anim
	switch (path_type) {

	case 1:
		path.PushBack({ 0, 0 }, 80, &Grey_Tank[0]);
		path.PushBack({ 1.0833f, 0 }, 100, &Grey_Tank[0]);
		path.loop = true;

		break;
	case 2:
		path.PushBack({ 0, 0 }, 80, &Grey_Tank[0]);
		path.PushBack({ -1.0833f, 0 }, 100, &Grey_Tank[0]);
		path.loop = true;

		break;

	case 3:
		path.PushBack({ 0, 0 }, 15, &Grey_Tank[1]);
		path.PushBack({ 0.76579f, -0.76579f }, 137, &Grey_Tank[1]);
		path.PushBack({ 1.0833f, 0 }, 22, &Grey_Tank[0]);
		path.PushBack({ -1.0833f, 0 }, 160, &Grey_Tank[0]);
		path.loop = true;

		break;
	case 4:
		path.PushBack({ -0.76579f, 0.76579f }, 200, &Grey_Tank[1]);
		path.loop = true;

		break;
	default:
		break;
	}
}

void GreyTank_Base::Move()
{

	position = original_pos + path.GetCurrentPosition();

	if (collider->life_units > 3)
	{
		turret->Move();
		turret->position = position;
		turret->Draw(App->enemies_ground->sprites);
	}
	else if (collider->life_units == 3)
	{
		hittable = true;
		delete turret;
		turret = nullptr;
	}

}
