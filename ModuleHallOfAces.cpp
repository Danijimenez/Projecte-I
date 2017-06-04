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

	char_num = 0;

	scores[9].score = temp_hiScore;

	while (!ordered)
	{
		for (int i = 0; i < 9; i++) {
			if (scores[i].score < scores[i + 1].score) {

				score_aux1 = scores[i + 1].score;
				score_aux2 = scores[i].score;

				char1_aux1 = scores[i + i].character[0];
				char2_aux1 = scores[i + i].character[1];
				char3_aux1 = scores[i + i].character[2];
				char1_aux2 = scores[i].character[0];
				char2_aux2 = scores[i].character[1];
				char3_aux2 = scores[i].character[2];

				scores[i].score = score_aux1;
				scores[i + 1].score = score_aux2;

				scores[i].character[0] = char1_aux1;
				scores[i].character[1] = char2_aux1;
				scores[i].character[2] = char3_aux1;
				scores[i + 1].character[0] = char1_aux2;
				scores[i + 1].character[1] = char2_aux2;
				scores[i + 1].character[2] = char3_aux2;

				score_index = i;

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

	for (int i = 0; i < 9; i++) {
		sprintf_s(scores[i].score_text, 10, "%7d", scores[i].score);
	}

	scores[score_index].character[0] = 27;
	scores[score_index].character[1] = 27;
	scores[score_index].character[2] = 27;



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


	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_DOWN || App->input->contrkey1[SDL_CONTROLLER_BUTTON_DPAD_RIGHT] == KEY_STATE::KEY_DOWN) {
		char_num++;
		if (char_num == 3) {
			char_num = 0;
		}
	}
	if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_DOWN || App->input->contrkey1[SDL_CONTROLLER_BUTTON_DPAD_LEFT] == KEY_STATE::KEY_DOWN) {
		char_num--;
		if (char_num == -1) {
			char_num = 2;
		}
	}


	if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_DOWN || App->input->contrkey1[SDL_CONTROLLER_BUTTON_DPAD_UP] == KEY_STATE::KEY_DOWN) {
		scores[score_index].character[char_num]++;
		if (scores[score_index].character[char_num] == 27) {
			scores[score_index].character[char_num] = 0;
		}
	}
	if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_DOWN || App->input->contrkey1[SDL_CONTROLLER_BUTTON_DPAD_DOWN] == KEY_STATE::KEY_DOWN) {
		scores[score_index].character[char_num]--;
		if (scores[score_index].character[char_num] == -1) {
			scores[score_index].character[char_num] = 26;
		}
	}


	for (int i = 0; i < 9; i++) {



		App->fonts->BlitText(100, 80 + (16 * i), 1, scores[i].score_text);

		for (int j = 0; j < 3; j++) {
			std::string sym(1, scores[i].name[j][scores[i].character[j]]);
			scores[i].screen_name[j] = sym.c_str();

			if (i == score_index && j == char_num) {
				if (pop) {
					App->fonts->BlitText(60 + (8 * j), 80 + (16 * i), 1, " ");

				}
				else {
					App->fonts->BlitText(60 + (8 * j), 80 + (16 * i), 1, scores[i].screen_name[j]);
				}
			}
			else
				App->fonts->BlitText(60 + (8 * j), 80 + (16 * i), 1, scores[i].screen_name[j]);
		}
	}



	blit++;

	if (blit == 15) {
		pop = !pop;
		blit = 0;
	}

	if (App->input->keyboard[SDL_SCANCODE_SPACE] || App->input->contrkey1[SDL_CONTROLLER_BUTTON_A] == KEY_STATE::KEY_DOWN) {
		App->fade->FadeToBlack(this, App->welcome, 2.0f);
	}


	return UPDATE_CONTINUE;
}

