#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 19

class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleRender;
class ModuleWelcome;
class ModuleLevel1;
class ModuleLevel2;
class ModuleHallOfAces;
class ModulePlayer;
class ModuleFadeToBlack;
class Module;
class ModuleAudio;
class ModuleParticles;
class ModuleCollision;
class ModuleEnemySpaceship;
class ModuleEnemies;
class ModulePlayer2;
class ModuleLevel1_assets;
class ModuleEnemies_Ground;
class ModuleFonts;
class ModuleDebug;

class Application
{
public:

	Module* modules[NUM_MODULES];
	ModuleWindow* window;
	ModuleRender* render;
	ModuleInput* input;
	ModuleTextures* textures;
	ModuleWelcome* welcome;
	ModuleLevel1* level_1;
	ModuleLevel2* level_2;
	ModuleDebug* debug;
	ModuleLevel1_assets* level_1_assets;
	ModuleHallOfAces* HallOfAces;
	ModuleCollision* collision;
	ModulePlayer* player;
	ModulePlayer2* player2;
	ModuleEnemySpaceship* spaceship;
	ModuleFadeToBlack* fade;
	ModuleAudio* audio;
	ModuleParticles* particles;
	ModuleEnemies* enemies;
	ModuleEnemies_Ground* enemies_ground;
	ModuleFonts* fonts;

	bool stop_music;


public:

	Application();
	~Application();

	bool Init();
	update_status Update();
	bool CleanUp();

};

// Global var made extern for Application ---
extern Application* App;

#endif // __APPLICATION_H__