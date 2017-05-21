#ifndef __MODULELEVEL2_H__
#define __MODULELEVEL2_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleLevel2 : public Module
{
public:
	ModuleLevel2();
	~ModuleLevel2();

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
	bool gate_level2 = true;


	Collider* top;
	int top_pos;
	Collider* bottom;
	int bottom_pos;
	int hi_score = 0;
	float speed = 0.5;
	bool move = true;

};

#endif // __MODULESCENEHONDA_H__
