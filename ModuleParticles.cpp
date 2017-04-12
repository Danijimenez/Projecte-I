#include <math.h>
#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleParticles.h"
#include "ModuleCollision.h"

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
	shoots = App->textures->Load("assets/textures/Shoots.png");

	shoot.anim.PushBack({ 5, 1, 6, 6 });
	shoot.anim.loop = true ;
	shoot.anim.speed = 0.3f;
	shoot.speed.y -= 6;
	shoot.life = 1200;

//	spaceship_shot.anim.PushBack({ 13,1,5,11 });
//	spaceship_shot.speed.y += 6;
//	spaceship_shot.life = 1000;


	shoots = App->textures->Load("assets/textures/Ground Explosions.png");

	turret_explosion.anim.PushBack({ 8, 3, 30, 27 });
	turret_explosion.anim.PushBack({ 47, 3, 30, 27 });
	turret_explosion.anim.PushBack({ 79, 3, 30, 27 });
	turret_explosion.anim.PushBack({ 107, 2, 30, 27 });
	turret_explosion.anim.PushBack({ 141, 2, 30, 27 });
	turret_explosion.anim.PushBack({ 9, 40, 30, 27 });
	turret_explosion.anim.PushBack({ 46, 40, 30, 27 });
	turret_explosion.anim.PushBack({ 80, 38, 30, 27 });
	turret_explosion.anim.PushBack({ 111, 37, 30, 27 });
	turret_explosion.anim.PushBack({ 142, 38, 30, 27 });
	turret_explosion.anim.speed = 0.2f;
	turret_explosion.anim.loop = false;
	
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
			p->born = SDL_GetTicks() + delay;
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
		if (active[i] != nullptr && active[i]->collider == c1)
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
fx(p.fx), born(p.born), life(p.life)
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

	if (collider != nullptr)
		collider->SetPos(position.x, position.y);

	return ret;
}