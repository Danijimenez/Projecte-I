#ifndef __ModuleAudio_H__
#define __ModuleAudio_H__

#include "Module.h"
#include "Globals.h"
#include "SDL_mixer\include\SDL_mixer.h"



class ModuleAudio : public Module
{
public:
	ModuleAudio();
	~ModuleAudio();

	bool Start();
	bool Play(const char*);
	bool Stop();
	bool CleanUp();

public:
	Mix_Music* soundtrack = nullptr;
	Mix_Chunk* fx_shoot = nullptr;
	Mix_Chunk* powerup_ship_explosion = nullptr;
	Mix_Chunk* green_ship_explosion = nullptr;
	Mix_Chunk* basic_enemy_explosion = nullptr;
};

#endif
