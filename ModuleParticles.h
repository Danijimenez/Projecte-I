#ifndef __MODULEPARTICLES_H__
#define __MODULEPARTICLES_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"


#define MAX_ACTIVE_PARTICLES 100

struct SDL_Texture;
struct Collider;
enum COLLIDER_TYPE;


struct Particle
{
	Collider* collider = nullptr;
	Animation anim;
	uint fx = 0;
	iPoint position;
	fPoint speed;
	Uint32 born = 0;
	Uint32 life = 0;
	bool fx_played = false;

	Particle();
	Particle(const Particle& p);
	bool Update();

};

class ModuleParticles : public Module
{
public:
	ModuleParticles();
	~ModuleParticles();

	bool Start();
	update_status Update();
	bool CleanUp();
	void OnCollision(Collider* c1, Collider* c2);

	void AddParticle(const Particle& particle, int x, int y, COLLIDER_TYPE collider_type, Uint32 delay);

private:

	SDL_Texture* shoots = nullptr;
	Particle* active[MAX_ACTIVE_PARTICLES];
	uint last_particle = 0;

public:

	Particle shoot;


	Particle enemy_shot;
	Particle enemy_shot_flash;
	Particle ground_explosion;
	Particle basic_enemy_explosion;
	Particle air_enemy_explosion;
	Particle standard_shot;
	Particle standard_shot_flash;
	Particle laser;
	Particle laser_flash;
	Particle laser2;
	Particle box_explosion;
	Particle player_explosion;
};

#endif // __MODULEPARTICLES_H__