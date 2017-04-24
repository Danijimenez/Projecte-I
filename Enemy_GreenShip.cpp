#include "Application.h"
#include "Enemy_GreenShip.h"
#include "ModuleCollision.h"
#include "ModuleInput.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"



GreenShip::GreenShip(int x, int y) : Enemy(x, y)
{

	//Animation
	fly.PushBack({ 233,265,72,52 });
	fly.PushBack({ 310,266,72,52 });
	fly.speed = 0.2f;

	leave.PushBack({ 235,329,72,52 });
	leave.PushBack({ 313,328,72,52 });
	leave.PushBack({ 389,328,72,52 });

	leave.PushBack({ 470,328,72,52 });
	leave.PushBack({ 550,328,72,52 });
	leave.speed = 0.2f;

	back.PushBack({ 236,399,72,52 });
	back.PushBack({ 313,399,72,52 });
	back.speed = 0.2f;

	back.PushBack({ 390,399,72,52 });
	back.PushBack({ 470,399,72,52 });



	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 72, 52 }, COLLIDER_TYPE::COLLIDER_ENEMY_GREENSHIP, (Module*)App->enemies);
	collider->life_units = 20;

	original_pos.x = x;
	original_pos.y = y;


	//path

	path.PushBack({ 0.0f, 0.756f }, 250, &fly);
	path.PushBack({ -1.07f, 1.214f }, 100, &leave);
	path.PushBack({ 0.0f, -0.75f }, 500, &back);

	path.loop = false;
}

void GreenShip::Move()
{
	if (App->input->keyboard[SDL_SCANCODE_RCTRL] == KEY_STATE::KEY_DOWN)
	{
		float proj_speed = 4.0f;
		float speed_x_mult, speed_y_mult, common_mult, a_mult;

		speed_x_mult = (App->player->position.x - position.x);
		speed_y_mult = (App->player->position.y - position.y);

		a_mult = sqrt((pow(speed_x_mult, 2) + pow(speed_y_mult, 2)));

		common_mult = (proj_speed / a_mult);

		App->particles->laser2.speed.x = (common_mult * speed_x_mult);

		App->particles->laser2.speed.y = (common_mult * speed_y_mult);

		if (App->particles->laser2.speed.x != 0 && App->particles->laser2.speed.y != 0)
			App->particles->AddParticle(App->particles->laser2, position.x + 11, position.y + 10, COLLIDER_ENEMY_SHOT, 0);
		App->particles->AddParticle(App->particles->laser2, position.x + 11, position.y + 10, COLLIDER_ENEMY_SHOT, 0);
		App->particles->AddParticle(App->particles->laser2, position.x + 11, position.y + 10, COLLIDER_ENEMY_SHOT, 0);
		App->particles->AddParticle(App->particles->laser2, position.x + 11, position.y + 10, COLLIDER_ENEMY_SHOT, 0);
		App->particles->AddParticle(App->particles->laser2, position.x + 11, position.y + 10, COLLIDER_ENEMY_SHOT, 0);
	}
	position = original_pos + path.GetCurrentPosition(&animation);

}
