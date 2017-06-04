#include <math.h>
#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleParticles.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"

#include "SDL/include/SDL_timer.h"

ModuleParticles::ModuleParticles()
{
	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
		active[i] = nullptr;
}

ModuleParticles::~ModuleParticles()
{}

// Load assets
bool ModuleParticles::Start()
{
	LOG("Loading particles");




	shoots = App->textures->Load("assets/textures/Particles.png");

	shoot.anim.PushBack({ 5, 1, 6, 6 });
	shoot.anim.loop = true;
	shoot.anim.speed = 0.3f;
	shoot.speed.y -= 6;
	shoot.life = 1200;


	// Player laser PowerUp shot

	laser2.anim.PushBack({ 224, 327, 2, 15 });
	laser2.anim.PushBack({ 224, 327, 2, 15 });
	laser2.anim.speed = 0.01f;
	laser2.anim.loop = true;
	laser2.speed.y = -5;


	laser.anim.PushBack({ 224, 327, 2, 15 });
	laser.anim.PushBack({ 224, 327, 2, 15 });
	laser.anim.speed = 0.01f;
	laser.anim.loop = true;
	laser.speed.y = -5;



	laser_flash.anim.PushBack({ 230, 328, 22, 29 }); //spawn player y + 1;
	laser_flash.anim.speed = 0.2f;
	laser_flash.anim.loop = false;

	//Players standard shot

	standard_shot.anim.PushBack({ 221, 367, 6, 6 });
	standard_shot.anim.speed = 0.01f;
	standard_shot.anim.loop = true;
	standard_shot.speed.y = -10;



	standard_shot_flash.anim.PushBack({ 227, 366, 22, 7 }); //spawn player y + 5;
	standard_shot_flash.anim.speed = 0.2f;
	standard_shot_flash.anim.loop = false;

	// Players bombs

	bomb.anim.PushBack({ 474, 18, 166,154 });
	bomb.anim.PushBack({ 697, 15, 166,154 });
	bomb.anim.PushBack({ 912, 13, 166,154 });
	bomb.anim.PushBack({ 1112, 17, 166,154 });
	bomb.anim.PushBack({ 472, 178, 166,154 });
	bomb.anim.PushBack({ 683, 175, 166,154 });	
	bomb.anim.PushBack({ 913, 182, 166,154 });
	bomb.anim.PushBack({ 1112, 180, 166,154 });
	bomb.anim.PushBack({ 1322, 188, 166,154 });
	bomb.anim.PushBack({ 1537, 189, 166,154 });
	bomb.anim.PushBack({ 470, 358, 166,154 });
	bomb.anim.PushBack({ 682, 359, 166,154 });
	bomb.anim.PushBack({ 915, 360, 166,154 });
	bomb.anim.PushBack({ 1118, 367, 166,154 });
	bomb.anim.PushBack({ 1326, 378, 166,154 });
	bomb.anim.PushBack({ 1540, 372, 166,154 });
	bomb.anim.PushBack({ 463, 551, 166,154 });
	bomb.anim.PushBack({ 684, 540, 166,154 });
	bomb.anim.PushBack({ 910, 545, 166,154 });
	bomb.anim.PushBack({ 1114, 547, 166,154 });
	bomb.anim.PushBack({ 1328, 552, 166,154 });
	bomb.anim.PushBack({ 1528, 551, 166,154 });
	bomb.anim.PushBack({ 461, 731, 166,154 });
	bomb.anim.PushBack({ 673, 732, 166,154 });
	bomb.anim.PushBack({ 906, 733, 166,154 });
	bomb.anim.PushBack({ 1109, 740, 166,154 });
	bomb.anim.PushBack({ 1321, 738, 166,154 });
	bomb.anim.PushBack({ 1535, 732, 166,154 });
	bomb.anim.PushBack({ 457, 928, 166,154 });
	bomb.anim.PushBack({ 683, 927, 166,154 });
	bomb.anim.PushBack({ 890, 925, 166,154 });
	bomb.anim.PushBack({ 1094, 914, 166,154 });
	bomb.anim.PushBack({ 1326, 918, 166,154 });
	bomb.anim.PushBack({ 1531, 919, 166,154 });
	
	bomb.anim.speed = 0.2f;
	bomb.anim.loop = false;

	// Player missiles

		///Homing missile

	homing_missile.anim.PushBack({ 165, 64, 6, 11 });
	homing_missile.anim.PushBack({ 172, 64, 6, 11 });
	homing_missile.anim.PushBack({ 181, 65, 6, 11 });

	homing_missile.anim.PushBack({ 186, 65, 6, 11 });
	homing_missile.anim.PushBack({ 193, 65, 6, 11 });
	homing_missile.anim.PushBack({ 200, 65, 6, 11 });

	homing_missile.anim.loop = true;
	homing_missile.life = 1000;

	homing_missile.reload = true;

		///Nuclear missile

	nuclear_missile.anim.PushBack({ 164,44,4,11 });
	nuclear_missile.anim.PushBack({ 171,44,4,11 });

	nuclear_missile.speed.x = 0;
	nuclear_missile.speed.y = -4;
	nuclear_missile.life = 1000;

	nuclear_missile.reload = true;
	

	// Enemy shots

	enemy_shot.anim.PushBack({ 88, 86, 6, 5 });
	enemy_shot.anim.PushBack({ 96, 86, 6, 5  });
	enemy_shot.anim.loop = true;
	enemy_shot.anim.speed = 5.0f;
	enemy_shot.speed.y = 3;
	enemy_shot.life = 1200;

	enemy_shot_flash.anim.PushBack({ 57,83,12,11 });
	enemy_shot_flash.anim.PushBack({ 73,83,6,5 });
	enemy_shot.anim.loop = false;
	enemy_shot.anim.speed = 5.0f;


	// Player explosion

	player_explosion.anim.PushBack({ 44, 118, 41, 38 });
	player_explosion.anim.PushBack({ 94, 117, 41, 38 });
	player_explosion.anim.PushBack({ 149, 118, 41, 38 });
	player_explosion.anim.PushBack({ 198, 118, 41, 38 });
	player_explosion.anim.PushBack({ 44, 163, 41, 38 });
	player_explosion.anim.PushBack({ 95, 162, 41, 38 });
	player_explosion.anim.PushBack({ 169, 161, 41, 38 });
	player_explosion.anim.PushBack({ 200, 160, 41, 38 });
	player_explosion.anim.speed = 0.2f;
	player_explosion.anim.loop = false;


	// Ground explosions

	ground_explosion.anim.PushBack({ 51, 321, 30, 27 });
	ground_explosion.anim.PushBack({ 90, 321, 30, 27 });
	ground_explosion.anim.PushBack({ 122, 320, 30, 27 });
	ground_explosion.anim.PushBack({ 150, 320, 30, 27 });
	ground_explosion.anim.PushBack({ 184, 320, 30, 27 });
	ground_explosion.anim.PushBack({ 52, 359, 30, 27 });
	ground_explosion.anim.PushBack({ 89, 359, 30, 27 });
	ground_explosion.anim.PushBack({ 123, 357, 30, 27 });
	ground_explosion.anim.PushBack({ 154, 356, 30, 27 });
	ground_explosion.anim.PushBack({ 185, 357, 30, 27 });

	ground_explosion.anim.speed = 0.2f;
	ground_explosion.anim.loop = false;

	// Basc enemy explosion

	basic_enemy_explosion.anim.PushBack({ 39, 516, 32, 30 });
	basic_enemy_explosion.anim.PushBack({ 96, 511, 32, 30 });
	basic_enemy_explosion.anim.PushBack({ 161, 511, 32, 30 });
	basic_enemy_explosion.anim.PushBack({ 208, 511, 32, 30 });
	basic_enemy_explosion.anim.PushBack({ 39, 562, 32, 30 });
	basic_enemy_explosion.anim.PushBack({ 95, 563, 32, 30 });
	basic_enemy_explosion.anim.PushBack({ 159, 563, 32, 30 });
	basic_enemy_explosion.anim.PushBack({ 216, 564, 32, 30 });
	basic_enemy_explosion.anim.PushBack({ 42, 612, 32, 30 });
	basic_enemy_explosion.anim.PushBack({ 96, 613, 32, 30 });
	basic_enemy_explosion.anim.PushBack({ 157, 612, 32, 30 });
	basic_enemy_explosion.anim.PushBack({ 218, 610, 32, 30 });
	basic_enemy_explosion.anim.PushBack({ 40, 666, 32, 30 });
	basic_enemy_explosion.anim.PushBack({ 95, 666, 32, 30 });
	basic_enemy_explosion.anim.PushBack({ 154, 666, 32, 30 });
	basic_enemy_explosion.anim.PushBack({ 218, 666, 32, 30 });

	basic_enemy_explosion.anim.speed = 0.2f;
	basic_enemy_explosion.anim.loop = false;

	// Air enemies explosion

	air_enemy_explosion.anim.PushBack({ 21, 735, 77, 75});
	air_enemy_explosion.anim.PushBack({ 110, 734, 77, 75 });
	air_enemy_explosion.anim.PushBack({ 208, 731, 77, 75 });
	air_enemy_explosion.anim.PushBack({ 25, 821, 77, 75 });
	air_enemy_explosion.anim.PushBack({ 122, 818, 77, 75 });
	air_enemy_explosion.anim.PushBack({ 229, 815, 77, 75 });
	air_enemy_explosion.anim.PushBack({ 14, 921, 77, 75 });
	air_enemy_explosion.anim.PushBack({ 98, 920, 77, 75 });
	air_enemy_explosion.anim.PushBack({ 186, 922, 77, 75 });
	air_enemy_explosion.anim.PushBack({ 275, 922, 77, 75 });
	air_enemy_explosion.anim.PushBack({ 371, 915, 77, 75 });

	air_enemy_explosion.anim.speed = 0.2f;
	air_enemy_explosion.anim.loop = false;

	
	return true;
}

// Unload assets
bool ModuleParticles::CleanUp()
{
	LOG("Unloading particles");
	App->textures->Unload(shoots);

	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if(active[i] != nullptr)
		{
			delete active[i];
			active[i] = nullptr;
		}
	}

	return true;
}

// Update: draw background
update_status ModuleParticles::Update()
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		Particle* p = active[i];

		if (p == nullptr)
			continue;

		if (p->Update() == false)
		{
			if (p->reload) {
				App->player->ammo = true;

			}
			App->collision->EraseCollider(active[i]->collider);
			delete p;
			active[i] = nullptr;
		
		}
		else if (SDL_GetTicks() >= p->born)
		{
			App->render->Blit(shoots, p->position.x, p->position.y, &(p->anim.GetCurrentFrame()));
			if (p->fx_played == false)
			{
				p->fx_played = true;
			}
		}
	}

	return UPDATE_CONTINUE;
}

void ModuleParticles::AddParticle(const Particle& particle, int x, int y, COLLIDER_TYPE collider_type, Uint32 delay)
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if (active[i] == nullptr)
		{
			Particle* p = new Particle(particle);
			p->born = SDL_GetTicks();
			p->born += delay;
			p->position.x = x;
			p->position.y = y;
			if (collider_type != COLLIDER_NONE)
				p->collider = App->collision->AddCollider(p->anim.GetCurrentFrame(), collider_type, this);
			active[i] = p;
			break;
		}
	}
}

void ModuleParticles::OnCollision(Collider* c1, Collider* c2)
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		// Always destroy particles that collide
		if (active[i] != nullptr && active[i]->collider == c1 && active[i]->collider->type!=COLLIDER_BOMB)
		{
			//			App->particles->AddParticle(App->particles->explosion, active[i]->position.x, active[i]->position.y, COLLIDER_NONE);
			active[i]->collider->to_delete=true;
			delete active[i];
			active[i] = nullptr;
			break;
		}
	}

}

// -------------------------------------------------------------
// -------------------------------------------------------------

Particle::Particle()
{
	position.SetToZero();
	speed.SetToZero();
}

Particle::Particle(const Particle& p) : 
anim(p.anim), position(p.position), speed(p.speed),
fx(p.fx), born(p.born), life(p.life), reload(p.reload)
{}

bool Particle::Update()
{
	bool ret = true;

	if (life > 0)
	{
		if ((SDL_GetTicks() - born) > life)
			ret = false;
	}
	else
		if (anim.Finished())
			ret = false;

	position.x += speed.x;
	position.y += speed.y;

	if (reload) {
		position.x += App->particles->movement_x;
		position.y += App->particles->movement_y;
	}

	if (collider != nullptr)
		collider->SetPos(position.x, position.y);

	return ret;
}