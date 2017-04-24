#ifndef __MODULEDEBUG_H__
#define __MODULEDEBUG_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"


struct SDL_Texture;
struct Collider;

class ModuleDebug : public Module
{
public:
	ModuleDebug();
	~ModuleDebug();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	SDL_Rect ground;
	SDL_Rect roof;
	SDL_Rect foreground;
	SDL_Rect background;
	Animation water;
	bool gate_level1 = true;
	Collider* top;
	int top_pos;
	Collider* bottom;
	int bottom_pos;
};

#endif 
