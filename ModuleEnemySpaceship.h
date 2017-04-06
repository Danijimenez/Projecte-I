#ifndef __ModuleEnemySpaceship_H__
#define __ModuleEnemySpaceship_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"

struct SDL_Texture;
struct Collider;


class ModuleEnemySpaceship : public Module
{
public:
	ModuleEnemySpaceship();
	~ModuleEnemySpaceship();

	bool Start();
	update_status Update();
	bool CleanUp();
	void OnCollision(Collider* c1, Collider* c2);

public:

	SDL_Texture* graphics = nullptr;
	Animation* current_animation = nullptr;
	Animation idle;
	Animation right;
	Animation left;
	iPoint position;
	bool started = false;
	int shoot_pos;
	Collider* spaceship;
};

#endif




