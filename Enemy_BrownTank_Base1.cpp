#include "Application.h"
#include "Enemy_BrownTank_Base1.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "Enemy_TankTurret.h"
#include "ModuleEnemies_Ground.h"


BrownTank_Base::BrownTank_Base(int x, int y, int path_type) : Enemy(x, y)
{
	//Change
	Brown_Tank[0].PushBack({ 30,795,34,34 });
	Brown_Tank[1].PushBack({ 80,792,34,34 });
	Brown_Tank[2].PushBack({ 133,798,34,34 });
	Brown_Tank[3].PushBack({ 40,833,34,34 });
	Brown_Tank[4].PushBack({ 89,832,34,34 });
	Brown_Tank[5].PushBack({ 134,835,34,34 });
	Brown_Tank[6].PushBack({ 39,870,34,34 });
	Brown_Tank[7].PushBack({ 91,871,34,34 });

	hittable = true;

	turret = new Tank_Turret(x, y);


	collider = App->collision->AddCollider({ 0, 0, 34, 34 }, COLLIDER_TYPE::COLLIDER_ENEMY_TANK, (Module*)App->enemies);
	collider->life_units = 3;

	original_pos.x = x;
	original_pos.y = y;

	//Change path && anim
	switch (path_type){

	case 1:
		path.PushBack({ 0, -1.0833f }, 270, &Brown_Tank[0]);
		path.loop = true;

		break;
	case 2:
		path.PushBack({ -1.0833f, 0 }, 270, &Brown_Tank[1]);
		path.loop = true;
		break;

	case 3:
		path.PushBack({ 0.76579f, -0.76579f }, 97, &Brown_Tank[7]);
		path.PushBack({ 0, 0 }, 5, &Brown_Tank[5]);
		path.PushBack({ 0, -1.0833f }, 270, &Brown_Tank[0]);

		break;
	case 4:
		path.PushBack({ -0.76579f, -0.76579f }, 97, &Brown_Tank[4]);
		path.PushBack({ 0, 0 }, 5, &Brown_Tank[2]);
		path.PushBack({ 0, -1.0833f }, 270, &Brown_Tank[0]);
		path.loop = true;
		
		break;
	case 5:
		path.PushBack({ 0.76579f, -0.76579f }, 97, &Brown_Tank[7]);
		break;
	case 6:
		path.PushBack({ 0, 0 }, 1, &Brown_Tank[15]);
	default:
		break;
	}

}

void BrownTank_Base::Move()
{

	position = original_pos + path.GetCurrentPosition();

	if (collider->life_units > 1)
	{
		turret->Move();
		turret->position = position;
		turret->Draw(App->enemies_ground->sprites);
	}
	else if (collider->life_units == 1)
	{
		hittable = true;
		delete turret;
		turret = nullptr;
	}
}