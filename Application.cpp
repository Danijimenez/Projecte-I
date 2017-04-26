#include "Application.h"
#include "ModuleWindow.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleWelcome.h"
#include "ModuleLevel1.h"
#include "ModuleLevel2.h"
#include "ModuleHallOfAces.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleFadeToBlack.h"
#include "ModuleAudio.h"
#include "ModuleParticles.h"
#include "ModuleCollision.h"
#include "ModuleEnemySpaceship.h"
#include "ModuleEnemies.h"
#include "ModuleLevel1(assets).h"
#include "ModuleEnemies_Ground.h"
#include "ModuleFonts.h"
#include "ModuleDebug.h"
#include "ModuleWelcomeAssets.h"

Application::Application()
{
	int i = 0;

	modules[i++] = window = new ModuleWindow();
	modules[i++] = render = new ModuleRender();
	modules[i++] = input = new ModuleInput();
	modules[i++] = textures = new ModuleTextures();
	modules[i++] = level_1 = new ModuleLevel1();
	modules[i++] = level_2 = new ModuleLevel2();
	modules[i++] = debug = new ModuleDebug();
	modules[i++] = HallOfAces = new ModuleHallOfAces();
	modules[i++] = welcomeassets = new ModuleWelcomeAssets();
	modules[i++] = enemies_ground = new ModuleEnemies_Ground();
	modules[i++] = level_1_assets = new ModuleLevel1_assets();
	modules[i++] = enemies = new ModuleEnemies();
	modules[i++] = particles = new ModuleParticles();
	modules[i++] = player = new ModulePlayer();
	modules[i++] = welcome = new ModuleWelcome();
	modules[i++] = player2 = new ModulePlayer2();
	modules[i++] = collision = new ModuleCollision();
	modules[i++] = fonts = new ModuleFonts();
	modules[i++] = audio = new ModuleAudio();
	modules[i++] = fade = new ModuleFadeToBlack();



}

Application::~Application()
{
	for (int i = NUM_MODULES - 1; i >= 0; --i)
		delete modules[i];
}

bool Application::Init()
{
	bool ret = true;

	// Player will be enabled on the first update of a new scene
	player->Disable();
	player2->Disable();
	// Disable the map that you do not start with
	//	welcome->Disable();
	welcomeassets->Disable();
	debug->Disable();
	level_1->Disable();
	level_1_assets->Disable();
	level_2->Disable();
	HallOfAces->Disable();


	for (int i = 0; i < NUM_MODULES && ret == true; ++i)
		ret = modules[i]->Init();

	for (int i = 0; i < NUM_MODULES && ret == true; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Start() : true;

	return ret;
}

update_status Application::Update()
{
	update_status ret = UPDATE_CONTINUE;

	for (int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PreUpdate() : UPDATE_CONTINUE;

	for (int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Update() : UPDATE_CONTINUE;

	for (int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PostUpdate() : UPDATE_CONTINUE;

	return ret;
}

bool Application::CleanUp()
{
	bool ret = true;
	stop_music = false;
	for (int i = NUM_MODULES - 1; i >= 0 && ret == true; --i)
		ret = modules[i]->CleanUp();

	return ret;
}