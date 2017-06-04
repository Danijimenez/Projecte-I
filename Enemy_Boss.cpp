#include "Application.h"
#include "Enemy_GreyTank_Base.h"
#include "ModuleCollision.h"
#include "Enemy_Boss.h"


Boss::Boss(int x, int y) : Enemy(x, y)
{

	Stay.PushBack({ 1106,352,160,99 });
	Stay.PushBack({ 1296,352,160,99 });
	Stay.PushBack({ 1472,351,160,99 });
	Stay.PushBack({ 1672,351,160,99 });
	Stay.PushBack({ 915,875,160,99 });
	Stay.PushBack({ 1100,874,160,99 });
	Stay.PushBack({ 1289,873,160,99 });
	Stay.PushBack({ 1474,872,160,99 });
	Stay.PushBack({ 1652,871,160,99 });
	Stay.PushBack({ 916,1004,160,99 });
	Stay.loop = true;
	Stay.speed = 0.1f;

	Moving.PushBack({ 915,484,160,99 });
	Moving.PushBack({ 1103,848,160,99 });
	Moving.PushBack({ 1287,484,160,99 });
	Moving.PushBack({ 1477,482,160,99 });
	Moving.PushBack({ 1673,483,160,99 });
	Moving.PushBack({ 912,628,160,99 });
	Moving.PushBack({ 1143,625,160,99 });
	Moving.PushBack({ 1329,623,160,99 });
	Moving.PushBack({ 1510,622,160,99 });
	Moving.PushBack({ 1680,622,160,99 });
	Moving.PushBack({ 913,757,160,99 });
	Moving.PushBack({ 1145,751,160,99 });
	Moving.PushBack({ 1327,750,160,99 });
	Moving.PushBack({ 1507,749,160,99 });
	Moving.loop = true;
	Moving.speed = 0.1f;

	Shoot.PushBack({ 913,353,160,99 });
	Shoot.loop = true;
	Shoot.speed = 0.1f;

	Bee.PushBack({ 913,353,160,99 });
	Bee.loop = true;
	Bee.speed = 0.1f;

	Stage2Stay.PushBack({ 1110,1139,160,99 });
	Stage2Stay.PushBack({ 1301,1138,160,99 });
	Stage2Stay.PushBack({ 1479,1138,160,99 });
	Stage2Stay.PushBack({ 1659,1138,160,99 });
	Stage2Stay.PushBack({ 916,1269,160,99 });
	Stage2Stay.loop = true;
	Stage2Stay.speed = 0.1f;

	Stage2Moving.PushBack({ 1110,1269,160,99 });
	Stage2Moving.PushBack({ 1300,1269,160,99 });
	Stage2Moving.PushBack({ 1476,1269,160,99 });
	Stage2Moving.PushBack({ 1660,1269,160,99 });
	Stage2Moving.PushBack({ 916,1394,160,99 });
	Stage2Moving.PushBack({ 1108,1394,160,99 });
	Stage2Moving.PushBack({ 1296,1394,160,99 });
	Stage2Moving.PushBack({ 1472,1394,160,99 });
	Stage2Moving.loop = true;
	Stage2Moving.speed = 0.1f;

	Stage2Shoot.PushBack({ 916,1140,160,99 });
	Stage2Shoot.loop = true;
	Stage2Shoot.speed = 0.1f;




	hittable = true;


	collider = App->collision->AddCollider({ 0, 0, 160, 99 }, COLLIDER_TYPE::COLLIDER_ENEMY_TANK, (Module*)App->enemies);
	collider->life_units = 8;

	original_pos.x = x;
	original_pos.y = y;

	//Change path

	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 6, &Stay);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 6, &Stay);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 6, &Stay);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 6, &Stay);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 6, &Stay);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 6, &Stay);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 6, &Stay);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 6, &Stay);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 6, &Stay);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 6, &Stay);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 6, &Stay);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 6, &Stay);
	path.PushBack({ 0,0 }, 1, &Shoot);
	path.PushBack({ 0,0 }, 6, &Stay);
	path.PushBack({ 0,0 }, 1, &Shoot);

	path.PushBack({ 0,0 }, 117, &Stay);

	path.PushBack({ 0,0 }, 65, &Moving);

	path.PushBack({ 0.76579f , -0.76579f }, 1, &Shoot);
	path.PushBack({ 0.76579f, -0.76579f }, 6, &Stay);
	path.PushBack({ 0.76579f , -0.76579f }, 1, &Shoot);
	path.PushBack({ 0.76579f , -0.76579f }, 1, &Shoot);
	path.PushBack({ 0.76579f , -0.76579f }, 1, &Shoot);


}

void Boss::Move()
{

	position = original_pos + path.GetCurrentPosition(&animation);

}

