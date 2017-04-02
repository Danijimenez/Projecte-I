#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleWelcome.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleLevel1.h"
#include "ModuleLevel2.h"
#include "ModulePlayer.h"
#include "ModuleAudio.h"


// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleWelcome::ModuleWelcome()
{
	welcome = { 0, 0, 358, 481 };
}

ModuleWelcome::~ModuleWelcome()
{}

// Load assets
bool ModuleWelcome::Start()
{
	LOG("Loading ken scene");
	App->stop_music = false;
	graphics = App->textures->Load("assets/textures/welcome.png");
	App->render->camera.x = -25;
	App->render->camera.y = 0;


//	App->player->Enable();


	return true;
}

// UnLoad assets
bool ModuleWelcome::CleanUp()
{
	LOG("Unloading ken scene");
	
//	App->player->Disable();
	
	App->textures->Unload(graphics);

	App->audio->Stop();

//	App->gate = true;


	return true;
}

// Update: draw background
update_status ModuleWelcome::Update()
{


	// Draw everything --------------------------------------
	App->render->Blit(graphics, 0, 0, &welcome);


	if (App->input->keyboard[SDL_SCANCODE_SPACE]) {
		App->fade->FadeToBlack(this, App->level_1, 2.0f);
	}
	return UPDATE_CONTINUE;
}