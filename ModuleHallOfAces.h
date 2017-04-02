#ifndef __MODULEHALLOFACES_H__
#define __MODULEHALLOFACES_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleHallOfAces : public Module
{
public:
	ModuleHallOfAces();
	~ModuleHallOfAces();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	SDL_Rect HallOfAces;

	bool gate_aces = true;
};

#endif // __MODULESCENEKEN_H__