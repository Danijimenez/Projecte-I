#include "Globals.h"
#include "Application.h"
#include "ModuleLevel1(assets).h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"

// Reference at https://youtu.be/6OlenbCC4WI?t=382

ModuleLevel1_assets::ModuleLevel1_assets()
{
	ground = {0, 0, 352, 3705};

}

ModuleLevel1_assets::~ModuleLevel1_assets()
{}

// Load assets
bool ModuleLevel1_assets::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("assets/textures/TileMap-2-LvL1.png");


	return ret;
}

// Load assets
bool ModuleLevel1_assets::CleanUp()
{


	App->textures->Unload(graphics);



	LOG("Unloading Level 1 assets");

	return true;
}

// Update: draw background
update_status ModuleLevel1_assets::Update()
{

	App->render->Blit(graphics, 0, -3449, &ground);

	return UPDATE_CONTINUE;
} 