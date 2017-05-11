#ifndef __MODULELEVEL1_H__
#define __MODULELEVEL1_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"


struct SDL_Texture;
struct Collider;

class ModuleLevel1 : public Module
{
public:
	ModuleLevel1();
	~ModuleLevel1();

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
	int hi_score = 0;
	float speed = 0.5;
	bool move=true;
};

#endif // __MODULESCENEHONDA_H__