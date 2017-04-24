#ifndef __MODULELEVEL1_ASSETS_H__
#define __MODULELEVEL1_ASSETS_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"


struct SDL_Texture;
struct Collider;

class ModuleLevel1_assets : public Module
{
public:
	ModuleLevel1_assets();
	~ModuleLevel1_assets();

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