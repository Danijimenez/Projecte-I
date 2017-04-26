#ifndef __MODULEWELCOMEASSETS_H__
#define __MODULEWELCOMEASSETS_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleWelcomeAssets : public Module
{
public:
	ModuleWelcomeAssets();
	~ModuleWelcomeAssets();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	
	SDL_Texture* graphics = nullptr;
	SDL_Texture* background = nullptr;
	SDL_Rect welcome;
	SDL_Rect ground;

	bool player1 = false;
	bool player2 = false;

	bool gate_welcome = true;
	int speed = 1;
};

#endif // __MODULESCENEKEN_H__