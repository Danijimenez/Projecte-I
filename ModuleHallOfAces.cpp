#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleHallOfAces.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleWelcome.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleAudio.h"
#include "ModuleEnemies.h"
#include "ModuleEnemies_Ground.h"
#include "ModuleLevel1.h"
#include "ModuleParticles.h"
#include "ModuleCollision.h"
#include "ModuleFonts.h"

#include <stdio.h>
#include <string>

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleHallOfAces::ModuleHallOfAces()
{
	HallOfAces = { 0, 0, 224, 256 };
}

ModuleHallOfAces::~ModuleHallOfAces()
{}

// Load assets
bool ModuleHallOfAces::Start()
{
	LOG("Loading Hall of Aces scene");

	graphics = App->textures->Load("assets/textures/hall_of_aces.png");

	App->stop_music = true;
	App->audio->Play("assets/music/hall_of_aces.ogg");
	App->render->camera.x = 0;
	App->render->camera.y = 0;

	if (App->player->player_points > App->player2->player_points) {
		temp_hiScore = App->player->player_points;
	}

	else {
		temp_hiScore = App->player2->player_points;
	}

	scores[9] = temp_hiScore;

	while (!ordered)
	{
		for (int i = 0; i < 9; i++) {
			if (scores[i] < scores[i + 1]) {
				aux1 = scores[i + 1];
				aux2 = scores[i];
				scores[i] = aux1;
				scores[i + 1] = aux2;
				numSwaps++;
			}
		}
		if (numSwaps == 0) {
			ordered = true;
		}
		else
			numSwaps = 0;
	}
	ordered = false;
	//Save scores as text

	sprintf_s(App->player->score_text, 10, "%7d", App->player->player_points); 
	sprintf_s(App->player2->score_text, 10, "%7d", App->player2->player_points);
	sprintf_s(App->player->hiscore_text, 10, "%7d", App->level_1->hi_score);

	sprintf_s(scores_text_1, 10, "%7d", scores[0]);
	sprintf_s(scores_text_2, 10, "%7d", scores[1]);
	sprintf_s(scores_text_3, 10, "%7d", scores[2]);
	sprintf_s(scores_text_4, 10, "%7d", scores[3]);
	sprintf_s(scores_text_5, 10, "%7d", scores[4]);
	sprintf_s(scores_text_6, 10, "%7d", scores[5]);
	sprintf_s(scores_text_7, 10, "%7d", scores[6]);
	sprintf_s(scores_text_8, 10, "%7d", scores[7]);
	sprintf_s(scores_text_9, 10, "%7d", scores[8]);

	return true;
}

// UnLoad assets
bool ModuleHallOfAces::CleanUp()
{
	LOG("Unloading Hall of Aces scene");

	App->textures->Unload(graphics);

	return true;
}

// Update: draw background
update_status ModuleHallOfAces::Update()
{


	// Draw everything --------------------------------------
	App->render->Blit(graphics, 0, 0, &HallOfAces);


	App->fonts->BlitText(10, 9, 2, App->player->score_text); // player score
	App->fonts->BlitText(150, 9, 2, App->player2->score_text); // player 2 score
	App->fonts->BlitText(78, 9, 2, App->player->hiscore_text); // hi score

	App->fonts->BlitText(100, 78, 1, scores_text_1);
	App->fonts->BlitText(100, 96, 1, scores_text_2);
	App->fonts->BlitText(100, 112, 1, scores_text_3);
	App->fonts->BlitText(100, 127, 1, scores_text_4);
	App->fonts->BlitText(100, 144, 1, scores_text_5);
	App->fonts->BlitText(100, 160, 1, scores_text_6);
	App->fonts->BlitText(100, 176, 1, scores_text_7);
	App->fonts->BlitText(100, 192, 1, scores_text_8);
	App->fonts->BlitText(100, 208, 1, scores_text_9);

	if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_DOWN || App->input->contrkey[SDL_CONTROLLER_BUTTON_DPAD_UP] == KEY_STATE::KEY_DOWN) {
		character++;
		if (character == 65) {
			character = 0;
		}
	}
	if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_DOWN || App->input->contrkey[SDL_CONTROLLER_BUTTON_DPAD_DOWN] == KEY_STATE::KEY_DOWN) {
		character--;
		if (character == 0) {
			character = 64;
		}
	}
	std::string sym(1, name[character]);
	screen_name = sym.c_str();

	App->fonts->BlitText(55, 80, 1, screen_name);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] || App->input->contrkey[SDL_CONTROLLER_BUTTON_A] == KEY_STATE::KEY_DOWN) {
		App->fade->FadeToBlack(this, App->welcome, 2.0f);
	}

	return UPDATE_CONTINUE;
}

