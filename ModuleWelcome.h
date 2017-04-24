#ifndef __MODULEWELCOME_H__
#define __MODULEWELCOME_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleWelcome : public Module
{
public:
	ModuleWelcome();
	~ModuleWelcome();

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
};

#endif // __MODULESCENEKEN_H__