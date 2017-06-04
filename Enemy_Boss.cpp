#include "Application.h"
#include "Enemy_GreyTank_Base.h"
#include "ModuleCollision.h"
#include "Enemy_Boss.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"

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

	

	collider = App->collision->AddCollider({ 0, 0, 160, 70 }, COLLIDER_TYPE::COLLIDER_ENEMY_BOSS, (Module*)App->enemies);
	collider->life_units = 270;

	original_pos.x = x;
	original_pos.y = y;

	{
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

		path.PushBack({ 0,0 }, 20, &Stay);

	}
	

	float speed_x = 0.76579f;
	float speed_y = -0.76579f;

	{
		path.PushBack({ 0.76579f,0 }, 65, &Moving);

		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 3, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Bee);

		path.PushBack({ speed_x, speed_y }, 2, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x, speed_y }, 15, &Stay);
		path.PushBack({ speed_x, speed_y }, 1, &Bee);

	}

	speed_x = -speed_x;

	
		path.PushBack({ speed_x, speed_y }, 74, &Moving);
		path.PushBack({ speed_x, speed_y }, 1, &Bee);

		path.PushBack({ speed_x, speed_y }, 91, &Moving);


		{


		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x, speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 3, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Bee);

		path.PushBack({ speed_x, speed_y }, 2, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x, speed_y }, 15, &Stay);
		path.PushBack({ speed_x, speed_y }, 1, &Bee);

	}


	speed_x = -speed_x;

	path.PushBack({ speed_x, speed_y }, 74, &Moving);
	path.PushBack({ speed_x, speed_y }, 1, &Bee);

	path.PushBack({ 0, 0 }, 55, &Stay);


	{


		speed_x = -speed_x;

		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 3, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Bee);

		path.PushBack({ speed_x, speed_y }, 2, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x, speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 3, &Stay);



		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 1, &Bee);
		path.PushBack({ speed_x, speed_y }, 2, &Stay);
	
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x, speed_y }, 15, &Stay);
		path.PushBack({ speed_x, speed_y }, 1, &Bee);


	}


	speed_x = -speed_x;

	{

		path.PushBack({ speed_x, speed_y }, 74, &Moving);
		path.PushBack({ speed_x, speed_y }, 1, &Bee);

		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x, speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 3, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Bee);

		path.PushBack({ speed_x, speed_y }, 2, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x, speed_y }, 15, &Stay);
		path.PushBack({ speed_x, speed_y }, 1, &Bee);

		path.PushBack({ speed_x, speed_y }, 2, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x, speed_y }, 15, &Stay);
		path.PushBack({ speed_x, speed_y }, 1, &Bee);
	}


	speed_x = -speed_x;

	{
		path.PushBack({ speed_x, speed_y }, 74, &Moving);
		path.PushBack({ speed_x, speed_y }, 1, &Bee);

		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x, speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 3, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Bee);

		path.PushBack({ speed_x, speed_y }, 2, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x, speed_y }, 15, &Stay);
		path.PushBack({ speed_x, speed_y }, 1, &Bee);

		path.PushBack({ speed_x, speed_y }, 2, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x , speed_y }, 1, &Shoot);
		path.PushBack({ speed_x, speed_y }, 6, &Stay);
		path.PushBack({ speed_x, speed_y }, 15, &Stay);
		path.PushBack({ speed_x, speed_y }, 1, &Bee);
	}



}

void Boss::Move()
{
	
	if (animation == &Shoot) {

		switch (shot_type)
		{
		case 1:
			App->particles->AddParticle(App->particles->enemy_shot, position.x + 72, position.y + 69, COLLIDER_ENEMY_SHOT, 0);
			break;
		case 2:
			App->particles->AddParticle(App->particles->enemy_shot, position.x + 81, position.y + 67, COLLIDER_ENEMY_SHOT, 0);
			break;

		case 3:
			App->particles->AddParticle(App->particles->enemy_shot, position.x + 89, position.y + 69, COLLIDER_ENEMY_SHOT, 0);
			shot_type = 0;
			break;

		default:
			break;
		}
		shot_type++;
	
	}

	else if (animation == &Bee) {


		App->enemies->AddEnemy(ENEMY_TYPES::BEE, position.x + 20, position.y + 20);
		App->enemies->AddEnemy(ENEMY_TYPES::BEE, position.x + 40, position.y + 20);
		App->enemies->AddEnemy(ENEMY_TYPES::BEE, position.x + 20, position.y + 40);
		App->enemies->AddEnemy(ENEMY_TYPES::BEE, position.x + 40, position.y + 40);


		App->enemies->AddEnemy(ENEMY_TYPES::BEE, position.x + 120, position.y + 20);
		App->enemies->AddEnemy(ENEMY_TYPES::BEE, position.x + 140, position.y + 20);
		App->enemies->AddEnemy(ENEMY_TYPES::BEE, position.x + 120, position.y + 40);
		App->enemies->AddEnemy(ENEMY_TYPES::BEE, position.x + 140, position.y + 40);

	}
	original_pos.y += 0.2f;
	position = original_pos + path.GetCurrentPosition(&animation);

}

