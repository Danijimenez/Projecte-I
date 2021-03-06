#ifndef __ModuleCollision_H__
#define __ModuleCollision_H__

#define MAX_COLLIDERS 200

#include "Module.h"
#include "SDL/include/SDL_rect.h"

enum COLLIDER_TYPE
{
	COLLIDER_NONE = -1,
	COLLIDER_PLAYER,
	COLLIDER_PLAYER_2,
	COLLIDER_ENEMY_BASIC,
	COLLIDER_ENEMY_GREENSHIP,
	COLLIDER_ENEMY_POWERUPSHIP,
	COLLIDER_ENEMY_TURRET,
	COLLIDER_PLAYER_SHOT,
	COLLIDER_PLAYER_2_SHOT,
	COLLIDER_ENEMY_SHOT,
	COLLIDER_POWER_UP_VULCAN,
	COLLIDER_POWER_UP_LASER,
	COLLIDER_MISSILE,
	COLLIDER_EXTRA_POINTS,
	COLLIDER_BOX,
	COLLIDER_DARK_BOX,
	COLLIDER_WALL_UP,
	COLLIDER_WALL_DOWN,
	COLLIDER_BOMB,
	COLLIDER_ENEMY_TANK,
	COLLIDER_ENEMY_BIGTANK,
	COLLIDER_ENEMY_BIGBOAT,
	COLLIDER_ENEMY_WAGON,
	COLLIDER_ENEMY_BOSS,
	COLLIDER_MISSILE_HOMING,
	COLLIDER_MISSILE_NUCLEAR,
	
	COLLIDER_MAX
};

struct Collider
{
	SDL_Rect rect;
	bool to_delete = false;
	COLLIDER_TYPE type;
	Module* callback = nullptr;
	int life_units;

	Collider(SDL_Rect rectangle, COLLIDER_TYPE type, Module* callback = nullptr) :
		rect(rectangle),
		type(type),
		callback(callback)
	{}

	void SetPos(int x, int y)
	{
		rect.x = x;
		rect.y = y;
	}

	bool CheckCollision(const SDL_Rect& r) const;
};

class ModuleCollision : public Module
{
public:

	ModuleCollision();
	~ModuleCollision();

	bool Start();

	update_status PreUpdate();
	update_status Update();
	//update_status PostUpdate();
	bool CleanUp();

	Collider* AddCollider(SDL_Rect rect, COLLIDER_TYPE type, Module* callback = nullptr);
	bool EraseCollider(Collider* collider);
	void DebugDraw();
	bool debug = true;
private:

	Collider* colliders[MAX_COLLIDERS];
	bool matrix[COLLIDER_MAX][COLLIDER_MAX];

};

#endif // __ModuleCollision_H__