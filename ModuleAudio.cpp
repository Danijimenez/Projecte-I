#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "SDL_mixer\include\SDL_mixer.h"

ModuleAudio::ModuleAudio()
{
}

ModuleAudio::~ModuleAudio()
{
}

bool ModuleAudio::Start()
{
	
	Mix_Init(MIX_INIT_OGG);

	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

	fx_shoot = Mix_LoadWAV("assets/fx/shootFX.wav");
	powerup_ship_explosion = Mix_LoadWAV("assets/fx/powerup_ship explosion.wav");
	green_ship_explosion = Mix_LoadWAV("assets/fx/green_ship_explosion.wav");
	basic_enemy_explosion = Mix_LoadWAV("assets/fx/basic_enemy explosion.wav");

	return true;
}


bool ModuleAudio::Play(const char* path)
{
	bool ret;

	soundtrack = Mix_LoadMUS(path);
	if (soundtrack == nullptr) {
		LOG("Error");
		ret = false;
	}
	else {
		LOG("Music Loaded");
		ret = true;
	}
	Mix_VolumeMusic(30);
	Mix_PlayMusic(soundtrack, -1);
	
	return ret;
}


bool ModuleAudio::Stop()
{
	if (App->stop_music) {
//		Mix_FreeMusic(soundtrack);
		App->stop_music = false;
	}
	return true;
}


bool ModuleAudio::CleanUp()
{
	LOG("Quitting SDL Mix");
//	Stop();
	if (App->stop_music) {
	Mix_CloseAudio();
	Mix_Quit();
	App->stop_music = false;
	}
	return true;
}
