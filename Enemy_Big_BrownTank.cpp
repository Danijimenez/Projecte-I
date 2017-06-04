#include "Application.h"
#include "Enemy_GreyTank_Base.h"
#include "ModuleCollision.h"
#include "Enemy_Big_BrownTank.h"
#include "ModuleParticles.h"


Big_BrownTank::Big_BrownTank(int x, int y, int path_type) : Enemy(x, y)
{
	//Change

	waiting.PushBack({ 427,1110,48,47 });

	preparing.PushBack({ 427,1110,48,47 });
	preparing.PushBack({ 497,1111,48,47 });
	preparing.PushBack({ 566,1111,48,47 });
	preparing.loop = true;
	preparing.speed = 0.1f;


	shoot.PushBack({ 427,1110,48,47 });
	shoot.PushBack({ 497,1111,48,47 });
	shoot.PushBack({ 566,1111,48,47 });
	shoot.speed = 0.2f;

	collider = App->collision->AddCollider({ 0, 0, 48, 47 }, COLLIDER_TYPE::COLLIDER_ENEMY_TANK, (Module*)App->enemies);
	collider->life_units = 30;

	original_pos.x = x;
	original_pos.y = y;

	path.PushBack({ 0, 0 }, 100, &waiting);
	path.PushBack({ 0, 0 }, 30, &preparing);
	path.PushBack({ 0, 0 }, 1, &shoot);
	path.PushBack({ 0, 0 }, 6, &preparing);
	path.PushBack({ 0, 0 }, 1, &shoot);
	path.PushBack({ 0, 0 }, 6, &preparing);
	path.PushBack({ 0, 0 }, 1, &shoot);
	path.PushBack({ 0, 0 }, 6, &preparing);
	path.PushBack({ 0, 0 }, 1, &shoot);
	path.PushBack({ 0, 0 }, 6, &preparing);
	path.PushBack({ 0, 0 }, 1, &shoot);
	path.PushBack({ 0, 0 }, 6, &preparing);
	path.PushBack({ 0, 0 }, 1, &shoot);
	path.PushBack({ 0, 0 }, 6, &preparing);
	path.PushBack({ 0, 0 }, 1, &shoot);
	path.PushBack({ 0, 0 }, 6, &preparing);
	path.PushBack({ 0, 0 }, 1, &shoot);
	path.PushBack({ 0, 0 }, 6, &preparing);
	path.PushBack({ 0, 0 }, 1, &shoot);
	path.PushBack({ 0, 0 }, 6, &preparing);
	path.PushBack({ 0, 0 }, 1, &shoot);
	path.PushBack({ 0, 0 }, 6, &preparing);
	path.PushBack({ 0, 0 }, 1, &shoot);
	path.PushBack({ 0, 0 }, 6, &preparing);
	path.PushBack({ 0, 0 }, 1, &shoot);
	path.PushBack({ 0, 0 }, 6, &preparing);


}

void Big_BrownTank::Move()
{
	if (animation == &shoot) {
		shoot_type++;
		switch (shoot_type)
		{
		case 1:

			App->particles->enemy_shot.speed.x = 0;
			App->particles->enemy_shot.speed.y = 3;

			App->particles->AddParticle(App->particles->enemy_shot, position.x + 21, position.y + 15, COLLIDER_ENEMY_SHOT, 0);

			App->particles->enemy_shot.speed.x = 0;
			App->particles->enemy_shot.speed.y = -3;

			App->particles->AddParticle(App->particles->enemy_shot, position.x + 21, position.y + 27, COLLIDER_ENEMY_SHOT, 0);
			break;

		case 2:


			App->particles->enemy_shot.speed.x = -2.1213f;
			App->particles->enemy_shot.speed.y = 2.1213f;

			App->particles->AddParticle(App->particles->enemy_shot, position.x + 18, position.y + 16, COLLIDER_ENEMY_SHOT, 0);

			App->particles->enemy_shot.speed.x = 2.1213f;
			App->particles->enemy_shot.speed.y = -2.1213f;

			App->particles->AddParticle(App->particles->enemy_shot, position.x + 25, position.y + 26, COLLIDER_ENEMY_SHOT, 0);
			break;

		case 3:

			App->particles->enemy_shot.speed.x = 2.1213f;
			App->particles->enemy_shot.speed.y = 2.1213f;

			App->particles->AddParticle(App->particles->enemy_shot, position.x + 27, position.y + 24, COLLIDER_ENEMY_SHOT, 0);

			App->particles->enemy_shot.speed.x = -2.1213f;
			App->particles->enemy_shot.speed.y = -2.1213f;

			App->particles->AddParticle(App->particles->enemy_shot, position.x + 17, position.y + 26, COLLIDER_ENEMY_SHOT, 0);
			break;

		case 4:

			App->particles->enemy_shot.speed.x = 3;
			App->particles->enemy_shot.speed.y = 0;

			App->particles->AddParticle(App->particles->enemy_shot, position.x + 28, position.y + 21, COLLIDER_ENEMY_SHOT, 0);

			App->particles->enemy_shot.speed.x = -3;
			App->particles->enemy_shot.speed.y = 0;

			App->particles->AddParticle(App->particles->enemy_shot, position.x + 14, position.y + 21, COLLIDER_ENEMY_SHOT, 0);

			shoot_type = 0;
				break;
		default:
			break;
		}

	}
	
	position = original_pos + path.GetCurrentPosition(&animation);
}

