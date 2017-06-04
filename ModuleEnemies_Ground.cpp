#include "Application.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleEnemies.h"
#include "ModuleEnemies_Ground.h"
#include "ModuleParticles.h"
#include "ModuleTextures.h"
#include "Enemy_BrownTank_Base1.h"
#include "Enemy_GreyTank_Base.h"
#include "Enemy_Boat.h"
#include "Enemy_BigBoat.h"
#include "Enemy_Big_GreyTank.h"
#include "Enemy_Big_BrownTank.h"
#include "Box.h"
#include "DarkBox.h"
#include "ModuleCollision.h"



#define SPAWN_MARGIN 50

ModuleEnemies_Ground::ModuleEnemies_Ground()
{
	for(uint i = 0; i < MAX_ENEMIES; ++i)
		enemies_ground[i] = nullptr;
}

// Destructor
ModuleEnemies_Ground::~ModuleEnemies_Ground()
{
}

bool ModuleEnemies_Ground::Start()
{
	if (sprites == nullptr) {
		LOG("No cargado");
	}
	sprites = App->textures->Load("assets/textures/enemieslvl2.png");
	if (sprites != nullptr) {
		LOG("Cargado");
	}

	return true;
}

update_status ModuleEnemies_Ground::PreUpdate()
{
	// check camera position to decide what to spawn
	for(uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if(queue_ground[i].type != ENEMY_TYPES::NO_TYPE)
		{
			if (-queue_ground[i].y < (App->render->camera.y) + SPAWN_MARGIN)
			{
				SpawnEnemy(queue_ground[i]);
				queue_ground[i].type = ENEMY_TYPES::NO_TYPE;
				LOG("Spawning enemy at %d", queue_ground[i].x * SCREEN_SIZE);
			}
		}
	}

	return UPDATE_CONTINUE;
}

// Called before render is available
update_status ModuleEnemies_Ground::Update()
{


	for (uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies_ground[i] != nullptr) enemies_ground[i]->Draw(sprites);

	for(uint i = 0; i < MAX_ENEMIES; ++i)
		if(enemies_ground[i] != nullptr) enemies_ground[i]->Move();


	return UPDATE_CONTINUE;
}

update_status ModuleEnemies_Ground::PostUpdate()
{
	// check camera position to decide what to spawn
	for(uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if(enemies_ground[i] != nullptr)
		{
			if (-enemies_ground[i]->position.y *SCREEN_SIZE < (App->render->camera.y) - SPAWN_MARGIN*5)
			{
				LOG("DeSpawning enemy at %d", enemies_ground[i]->position.y);
			delete enemies_ground[i];
				enemies_ground[i] = nullptr;
			}
		}
	}

	return UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleEnemies_Ground::CleanUp()
{
	LOG("Freeing all enemies");

	App->textures->Unload(sprites);

	for(uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if(enemies_ground[i] != nullptr)
		{
			delete enemies_ground[i];
			enemies_ground[i] = nullptr;
		}
	}

	return true;
}


bool ModuleEnemies_Ground::FreeEnemies()
{

	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies_ground[i] != nullptr)
		{
			delete enemies_ground[i];
			enemies_ground[i] = nullptr;
		}
	}

	return true;
}

bool ModuleEnemies_Ground::AddEnemy(ENEMY_TYPES type, int x, int y, int path)
{
	bool ret = false;

	for(uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if(queue_ground[i].type == ENEMY_TYPES::NO_TYPE)
		{
			queue_ground[i].type = type;
			queue_ground[i].x = x;
			queue_ground[i].y = y;
			queue_ground[i].path = path;
			ret = true;
			break;
		}
	}

	return ret;
}

void ModuleEnemies_Ground::SpawnEnemy(const EnemyInfo& info)
{
	// find room for the new enemy
	uint i = 0;
	for(; enemies_ground[i] != nullptr && i < MAX_ENEMIES; ++i);

	if (i != MAX_ENEMIES)
	{
		switch (info.type)
		{


		case ENEMY_TYPES::BOAT:
			enemies_ground[i] = new Boat(info.x, info.y);
			break;
		case ENEMY_TYPES::BIG_BOAT:
			enemies_ground[i] = new BigBoat(info.x, info.y);
			break;
		case ENEMY_TYPES::BROWN_TANK:
			enemies_ground[i] = new BrownTank_Base(info.x, info.y, info.path);
			break;
		case ENEMY_TYPES::GREY_TANK:
			enemies_ground[i] = new GreyTank_Base(info.x, info.y, info.path);
			break;
		case ENEMY_TYPES::BIGGREYTANK:
			enemies_ground[i] = new Big_GreyTank(info.x, info.y, info.path);
			break;
		case ENEMY_TYPES::BIGBROWNTANK:
			enemies_ground[i] = new Big_BrownTank(info.x, info.y, info.path);
			break;
		case ENEMY_TYPES::BOX:
			enemies_ground[i] = new Box(info.x, info.y);
			break;
		case ENEMY_TYPES::DARKBOX:
			enemies_ground[i] = new DarkBox(info.x, info.y);
			break;

		}			
	}
}

void ModuleEnemies_Ground::OnCollision(Collider* c1, Collider* c2)
{
	
	for(uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if(enemies_ground[i] != nullptr && enemies_ground[i]->GetCollider() == c1)
		{
			c1->life_units--;
			if (c1->life_units <= 0) {
				enemies_ground[i]->OnCollision(c2, c1);
				delete enemies_ground[i];
				enemies_ground[i] = nullptr;
				break;
			}
		}
	}
	
}