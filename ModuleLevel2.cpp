#include "Globals.h"
#include "Application.h"
#include "ModuleLevel1.h"
#include "ModuleLevel2.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModulePlayer.h"
#include "ModuleWelcome.h"
#include "ModuleAudio.h"
#include "ModuleHallOfAces.h"
#include "ModuleCollision.h"
#include "ModulePlayer2.h"
#include "ModuleEnemies.h"
#include "ModuleEnemies_Ground.h"


ModuleLevel2::ModuleLevel2()
{

	ground = { 0, 0, 402, 4755 };

}

ModuleLevel2::~ModuleLevel2()
{}

// Load assets
bool ModuleLevel2::Start()
{
	LOG("Loading background assets");
	bool ret = true;

	graphics = App->textures->Load("assets/textures/TileMap-LvL2.png");
	App->audio->Play("assets/music/2-7.ogg");
	App->stop_music = true;
	App->render->camera.x = -64;
	App->render->camera.y = 0;

	App->collision->debug = false;

	if (App->welcome->player1) {
		App->player->Enable();
	}
	if (App->welcome->player2) {
		App->player2->Enable();
	}

	speed = 1;

	top_pos = App->render->camera.y - 10;
	bottom_pos = App->render->camera.y + App->render->camera.h;

	top = App->collision->AddCollider({ 0, top_pos , 352 ,10 }, COLLIDER_WALL_UP);
	bottom = App->collision->AddCollider({ 0, bottom_pos , 352 ,10 }, COLLIDER_WALL_DOWN);
	//Derecha 2 / Abajo 1 / BajarDiagonal-Quito-Bajar 3 / DiagonalIzquierda-Quieto-Baja 4 / DiagonalArriba 5 / Quieto 6

	App->enemies->AddEnemy(ENEMY_TYPES::BROWN_TANK, 0, -41, 2);
	App->enemies->AddEnemy(ENEMY_TYPES::BROWN_TANK, 270, -89, 1);
	App->enemies->AddEnemy(ENEMY_TYPES::BROWN_TANK, 270, -129, 1);
	App->enemies->AddEnemy(ENEMY_TYPES::BROWN_TANK, 270, -169, 1);
	App->enemies->AddEnemy(ENEMY_TYPES::BROWN_TANK, 0, -145, 2);
	
	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY2, 0, -149);
	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY2, 337, -173,1);
	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY2, 337, -203,1);

	App->enemies->AddEnemy(ENEMY_TYPES::BROWN_TANK, 0, -170, 2);
	App->enemies->AddEnemy(ENEMY_TYPES::BROWN_TANK, 270, -274, 1);

	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY2, 340, -292,1);
	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY2, 337, -355,1);

	App->enemies->AddEnemy(ENEMY_TYPES::POWERUP_SHIP, 191, -298);

	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY2, 0, -306);
	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY2, 0, -346);

	App->enemies->AddEnemy(ENEMY_TYPES::BROWN_TANK, 0, -357, 2);
	App->enemies->AddEnemy(ENEMY_TYPES::BROWN_TANK, 0, -377, 2);

	App->enemies->AddEnemy(ENEMY_TYPES::BROWN_TANK, 278, -399, 1);
	App->enemies->AddEnemy(ENEMY_TYPES::BROWN_TANK, 278, -439, 1);

	App->enemies->AddEnemy(ENEMY_TYPES::BROWN_TANK, 107, -505, 6);
	App->enemies->AddEnemy(ENEMY_TYPES::BROWN_TANK, 138, -518, 6);
	App->enemies->AddEnemy(ENEMY_TYPES::BROWN_TANK, 155, -496, 6);
	App->enemies->AddEnemy(ENEMY_TYPES::BROWN_TANK, 185, -511, 6);
	App->enemies->AddEnemy(ENEMY_TYPES::BROWN_TANK, 210, -487, 6);
	App->enemies->AddEnemy(ENEMY_TYPES::BROWN_TANK, 229, -504, 6);

	App->enemies->AddEnemy(ENEMY_TYPES::BROWN_TANK, 97, -579, 1);
	App->enemies->AddEnemy(ENEMY_TYPES::BROWN_TANK, 97, -609, 1);

	App->enemies->AddEnemy(ENEMY_TYPES::BROWN_TANK, 270, -580, 1);
	App->enemies->AddEnemy(ENEMY_TYPES::BROWN_TANK, 270, -600, 1);
	App->enemies->AddEnemy(ENEMY_TYPES::BROWN_TANK, 270, -640, 1);

	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY2, 0, -575);
	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY2, 0, -595);
	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY2, 351, -581,1);
	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY2, 351, -601,1);

	App->enemies->AddEnemy(ENEMY_TYPES::POWERUP_SHIP, 189, -586);

	App->enemies->AddEnemy(ENEMY_TYPES::BROWN_TANK, 0, -626, 2);

	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY2, 351, -645,1);
	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY2, 351, -665,1);
	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY2, 351, -720,1);
	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY2, 351, -740,1);

	App->enemies->AddEnemy(ENEMY_TYPES::BROWN_TANK, 105, -755, 1);
	App->enemies->AddEnemy(ENEMY_TYPES::BROWN_TANK, 270, -780, 1);
	App->enemies->AddEnemy(ENEMY_TYPES::BROWN_TANK, 270, -800, 1);

	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY2, 0, -775);
	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY2, 0, -846);
	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY2, 0, -866);
	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY2, 0, -886);

	App->enemies->AddEnemy(ENEMY_TYPES::BROWN_TANK, 0, -837, 2);
	//App->enemies->AddEnemy(ENEMY_TYPES::BROWN_TANK, 0, -857, 2);
	//App->enemies->AddEnemy(ENEMY_TYPES::BROWN_TANK, 351, -837, izquierda);

	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY2, 351, -859,1);
	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY2, 351, -879,1);
	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY2, 351, -899,1);
	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY2, 351, -919,1);
	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY2, 351, -939,1);
	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY2, 351, -959,1);

	App->enemies->AddEnemy(ENEMY_TYPES::BROWN_TANK, 104, -919, 1);
	App->enemies->AddEnemy(ENEMY_TYPES::BROWN_TANK, 104, -939, 1);

	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY2, 0, -941);

	App->enemies->AddEnemy(ENEMY_TYPES::BROWN_TANK, 14, -1023, 4);
	App->enemies->AddEnemy(ENEMY_TYPES::BROWN_TANK, 283, -1035, 3);

	App->enemies->AddEnemy(ENEMY_TYPES::DARKBOX, 126, -992);

	App->enemies->AddEnemy(ENEMY_TYPES::BIGBROWNTANK, 175, -948);

	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY2, 0, -1109);
	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY2, 0, -1129);
	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY2, 0, -1149);
	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY2, 0, -1169);
	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY2, 0, -1189);
	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY2, 0, -1209);
	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY2, 0, -1229);

	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY2, 351, -1109,1);
	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY2, 351, -1129,1);
	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY2, 351, -1149,1);
	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY2, 351, -1169,1);
	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY2, 351, -1189,1);
	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY2, 351, -1209,1);
	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY2, 351, -1229,1);

	App->enemies->AddEnemy(ENEMY_TYPES::GREENSHIP, 41, -1245);
	App->enemies->AddEnemy(ENEMY_TYPES::GREENSHIP, 311, -1245);

	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY2, 0, -1229);
	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY2, 0, -1249);
	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY2, 0, -1269);
	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY2, 0, -1289);
	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY2, 351, -1229,1);
	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY2, 351, -1249,1);
	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY2, 351, -1269,1);
	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY2, 351, -1289,1);

	App->enemies->AddEnemy(ENEMY_TYPES::POWERUP_SHIP, 173, -1093);

	App->enemies->AddEnemy(ENEMY_TYPES::GREY_TANK, 59, -1350, 8);
	App->enemies->AddEnemy(ENEMY_TYPES::GREY_TANK, 104, -1547, 8);

	App->enemies->AddEnemy(ENEMY_TYPES::GREY_TANK, 84, -1394, 8);
	App->enemies->AddEnemy(ENEMY_TYPES::GREY_TANK, 143, -1394, 8);
	App->enemies->AddEnemy(ENEMY_TYPES::GREY_TANK, 195, -1394, 8);

	App->enemies->AddEnemy(ENEMY_TYPES::GREY_TANK, 189, -1443, 8);
	App->enemies->AddEnemy(ENEMY_TYPES::GREY_TANK, 246, -1443, 8);
	App->enemies->AddEnemy(ENEMY_TYPES::GREY_TANK, 295, -1443, 8);

	App->enemies->AddEnemy(ENEMY_TYPES::GREY_TANK, 0, -1416, 9);

	App->enemies->AddEnemy(ENEMY_TYPES::WAGON, 351, -1714);

	App->enemies->AddEnemy(ENEMY_TYPES::GREY_TANK, 165, -1496, 8);
	App->enemies->AddEnemy(ENEMY_TYPES::GREY_TANK, 207, -1496, 8);

	App->enemies->AddEnemy(ENEMY_TYPES::POWERUP_SHIP, 189, -1619);

	App->enemies->AddEnemy(ENEMY_TYPES::GREY_TANK, 292, -1628, 8);

	App->enemies->AddEnemy(ENEMY_TYPES::GREY_TANK, 271, -1665, 8);
	App->enemies->AddEnemy(ENEMY_TYPES::GREY_TANK, 98, -1665, 8);
	App->enemies->AddEnemy(ENEMY_TYPES::GREY_TANK, 0, -1651, 9);

	App->enemies->AddEnemy(ENEMY_TYPES::WAGON, 351, -1794);

	App->enemies->AddEnemy(ENEMY_TYPES::GREY_TANK, 351, -1849, 10);
	App->enemies->AddEnemy(ENEMY_TYPES::GREY_TANK, 391, -1849, 10);
	App->enemies->AddEnemy(ENEMY_TYPES::GREY_TANK, 431, -1849, 10);
	App->enemies->AddEnemy(ENEMY_TYPES::GREY_TANK, 110, -1865, 8);
	App->enemies->AddEnemy(ENEMY_TYPES::GREY_TANK, 165, -1865, 8);
	App->enemies->AddEnemy(ENEMY_TYPES::GREY_TANK, 227, -1865, 8);

	App->enemies->AddEnemy(ENEMY_TYPES::GREENSHIP, 230, -1999);
	App->enemies->AddEnemy(ENEMY_TYPES::GREENSHIP, 112, -2108);

	App->enemies->AddEnemy(ENEMY_TYPES::BROWN_TANK, 46, -2196, 4);
	App->enemies->AddEnemy(ENEMY_TYPES::BROWN_TANK, 34, -2253, 4);
	App->enemies->AddEnemy(ENEMY_TYPES::BROWN_TANK, 97, -2303, 1);
	App->enemies->AddEnemy(ENEMY_TYPES::BROWN_TANK, 97, -2333, 1);

	App->enemies->AddEnemy(ENEMY_TYPES::BOX, 272, -2023);
	App->enemies->AddEnemy(ENEMY_TYPES::BOX, 244, -2045);
	App->enemies->AddEnemy(ENEMY_TYPES::BOX, 222, -2066);
	App->enemies->AddEnemy(ENEMY_TYPES::BOX, 198, -2086);
	App->enemies->AddEnemy(ENEMY_TYPES::BOX, 173, -2110);
	App->enemies->AddEnemy(ENEMY_TYPES::BOX, 150, -2157);
	App->enemies->AddEnemy(ENEMY_TYPES::BOX, 150, -2206);

	App->enemies->AddEnemy(ENEMY_TYPES::GREENSHIP, 174, -2237);

	App->enemies->AddEnemy(ENEMY_TYPES::BIG_BOAT, 238, -2409);

	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY2, 0, -2355);
	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY2, 351, -2386, 1);

	App->enemies->AddEnemy(ENEMY_TYPES::BROWN_TANK, 94, -2492, 1);
	App->enemies->AddEnemy(ENEMY_TYPES::BROWN_TANK, 94, -2522, 1);

	App->enemies->AddEnemy(ENEMY_TYPES::BIGGREYTANK, 177, -2562);

	App->enemies->AddEnemy(ENEMY_TYPES::BOAT, 268, -2547);
	App->enemies->AddEnemy(ENEMY_TYPES::BOAT, 268, -2600);
	App->enemies->AddEnemy(ENEMY_TYPES::BOAT, 268, -2640);

	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY2, 0, -2589);
	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY2, 0, -2691);
	App->enemies->AddEnemy(ENEMY_TYPES::BASICENEMY2, 0, -2721);

	App->enemies->AddEnemy(ENEMY_TYPES::POWERUP_SHIP, 137, -2948);

	App->enemies->AddEnemy(ENEMY_TYPES::BROWN_TANK, 0, -2995, 6);
	App->enemies->AddEnemy(ENEMY_TYPES::BROWN_TANK, 0, -3025, 6);
	App->enemies->AddEnemy(ENEMY_TYPES::BROWN_TANK, 0, -3055, 6);

	App->enemies->AddEnemy(ENEMY_TYPES::BROWN_TANK, 170, -3038, 6);

	App->enemies->AddEnemy(ENEMY_TYPES::GREY_TANK, 68, -3209, 8);
	App->enemies->AddEnemy(ENEMY_TYPES::GREY_TANK, 133, -3230, 8);

	App->enemies->AddEnemy(ENEMY_TYPES::WAGON, 351, -3370);

	App->enemies->AddEnemy(ENEMY_TYPES::BEE, 0, -3338);
	App->enemies->AddEnemy(ENEMY_TYPES::BEE, -20, -3338);
	App->enemies->AddEnemy(ENEMY_TYPES::BEE, -40, -3338);
	App->enemies->AddEnemy(ENEMY_TYPES::BEE, -60, -3338);
	App->enemies->AddEnemy(ENEMY_TYPES::BEE, -80, -3338);
	App->enemies->AddEnemy(ENEMY_TYPES::BEE, -100, -3338);
	App->enemies->AddEnemy(ENEMY_TYPES::BEE, 351, -3338);
	App->enemies->AddEnemy(ENEMY_TYPES::BEE, 371, -3338);
	App->enemies->AddEnemy(ENEMY_TYPES::BEE, 391, -3338);
	App->enemies->AddEnemy(ENEMY_TYPES::BEE, 411, -3338);
	App->enemies->AddEnemy(ENEMY_TYPES::BEE, 431, -3338);
	App->enemies->AddEnemy(ENEMY_TYPES::BEE, 451, -3338);

	App->enemies->AddEnemy(ENEMY_TYPES::BEE, 0, -3537);
	App->enemies->AddEnemy(ENEMY_TYPES::BEE, -20, -3537);
	App->enemies->AddEnemy(ENEMY_TYPES::BEE, -40, -3537);
	App->enemies->AddEnemy(ENEMY_TYPES::BEE, -60, -3537);
	App->enemies->AddEnemy(ENEMY_TYPES::BEE, -80, -3537);
	App->enemies->AddEnemy(ENEMY_TYPES::BEE, -100, -3537);
	App->enemies->AddEnemy(ENEMY_TYPES::BEE, -120, -3537);
	App->enemies->AddEnemy(ENEMY_TYPES::BEE, 351, -3537);
	App->enemies->AddEnemy(ENEMY_TYPES::BEE, 371, -3537);
	App->enemies->AddEnemy(ENEMY_TYPES::BEE, 391, -3537);
	App->enemies->AddEnemy(ENEMY_TYPES::BEE, 411, -3537);
	App->enemies->AddEnemy(ENEMY_TYPES::BEE, 431, -3537);
	App->enemies->AddEnemy(ENEMY_TYPES::BEE, 451, -3537);
	App->enemies->AddEnemy(ENEMY_TYPES::BEE, 471, -3537);

	App->enemies->AddEnemy(ENEMY_TYPES::BOMB, 248, -3943);
	App->enemies->AddEnemy(ENEMY_TYPES::BOMB, 248, -4134);
	App->enemies->AddEnemy(ENEMY_TYPES::BOMB, 248, -4323);

	App->enemies->AddEnemy(ENEMY_TYPES::BOSS, 80, -3784);







	





	//	App->enemies_ground->AddEnemy(ENEMY_TYPES::TURRET, 48, -337);

	


	return ret;
}

// Load assets
bool ModuleLevel2::CleanUp()
{


	if (App->player->player_points > hi_score) {
		hi_score = App->player->player_points;
	}

	else if (App->player2->player_points > hi_score) {
		hi_score = App->player2->player_points;
	}

	App->textures->Unload(graphics);

	App->player->Disable();
	App->player2->Disable();

	//top->to_delete = true;
	//bottom->to_delete = true;

	App->enemies->FreeEnemies();
	App->enemies_ground->FreeEnemies();

	LOG("Unloading Level 2");

	return true;
}

// Update: draw background
update_status ModuleLevel2::Update()
{

	//Scroll

	if (move)
	{
		App->render->camera.y += speed;
		top_pos -= speed;
		bottom_pos -= speed;

		top->SetPos(0, top_pos);
		bottom->SetPos(0, bottom_pos);
	}



	if (App->input->keyboard[SDL_SCANCODE_F1]) {
		App->fade->FadeToBlack(this, App->welcome, 2.0f);
		top->to_delete = true;
		bottom->to_delete = true;
	}

	if (App->render->camera.y > 4500) {
		speed = 0;
		App->player->speed = 0;
		App->player2->speed = 0;
		App->render->camera.y += 0;
		App->fade->FadeToBlack(this, App->HallOfAces, 2.0f);
		top->to_delete = true;
		bottom->to_delete = true;

	}

	if (App->input->keyboard[SDL_SCANCODE_F6])
	{
		App->fade->FadeToBlack(this, App->HallOfAces, 2.0f);
		top->to_delete = true;
		bottom->to_delete = true;
	}

	move = !move;



	App->render->Blit(graphics, 0, -4500, &ground);


	return UPDATE_CONTINUE;
}