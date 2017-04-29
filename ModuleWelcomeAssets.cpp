#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleWelcome.h"
#include "ModuleWelcomeAssets.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleLevel1.h"
#include "ModuleLevel2.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleAudio.h"
#include "ModuleDebug.h"
#include "ModuleLevel1(assets).h"


// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleWelcomeAssets::ModuleWelcomeAssets()
{
	welcome = { 0, 0, 352, 3705 };
}

ModuleWelcomeAssets::~ModuleWelcomeAssets()
{}

// Load assets
bool ModuleWelcomeAssets::Start()
{
	LOG("Loading welcome scene");
	App->stop_music = false;

	graphics = App->textures->Load("assets/textures/TileMap-Full-LvL1.png");
	App->render->camera.x = -25;
	App->render->camera.y = 0;



	return true;
}

// UnLoad assets
bool ModuleWelcomeAssets::CleanUp()
{
	LOG("Unloading ken scene");
		
	App->textures->Unload(graphics);



	return true;
}

// Update: draw background
update_status ModuleWelcomeAssets::Update()
{


	// Draw everything --------------------------------------

	App->render->Blit(graphics, 0, -3449, &welcome);

	App->render->camera.y += speed*SCREEN_SIZE;


	

	if (App->render->camera.y > 10000) {
		App->render->camera.y = 0;
	}


	return UPDATE_CONTINUE;
}