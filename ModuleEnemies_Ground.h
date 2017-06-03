#ifndef __ModuleEnemies_Ground_H__
#define __ModuleEnemies_Ground_H__

#include "Module.h"
#include "ModuleEnemies.h"

#define MAX_ENEMIES 1000



class Enemy;


class ModuleEnemies_Ground : public Module
{
public:

	ModuleEnemies_Ground();
	~ModuleEnemies_Ground();

	bool Start();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();
	bool FreeEnemies();
	void OnCollision(Collider* c1, Collider* c2);

	bool AddEnemy(ENEMY_TYPES type, int x, int y);

	SDL_Texture* sprites;

private:

	void SpawnEnemy(const EnemyInfo& info);

private:

	EnemyInfo queue_ground[MAX_ENEMIES];
	Enemy* enemies_ground[MAX_ENEMIES];

};

#endif // __ModuleEnemies_H__