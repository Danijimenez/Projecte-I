#ifndef __MODULEPOWERUP_H__
#define __MODULEPOWERUP_H__

#include "Module.h"

#define MAX_POWERUP 5

enum POWERUP_TYPE
{
	POWERUP_NONE = -1,
	POWERUP_LASER,

	POWERUP_MAX
};

//struct PowerUp
//{
//	SDL_Rect rect;
//	bool to_delete = false;
//	COLLIDER_TYPE type;
//	Module* callback = nullptr;
//	int life_units;
//
//	Collider(SDL_Rect rectangle, COLLIDER_TYPE type, Module* callback = nullptr) :
//		rect(rectangle),
//		type(type),
//		callback(callback)
//	{}
//
//	void SetPos(int x, int y)
//	{
//		rect.x = x;
//		rect.y = y;
//	}
//
//	bool CheckCollision(const SDL_Rect& r) const;
//};

class ModulePowerUp : public Module
{
public:

	ModulePowerUp();
	~ModulePowerUp();

	update_status PreUpdate();
	update_status Update();
	//update_status PostUpdate();
	bool CleanUp();

	Collider* AddCollider(SDL_Rect rect, COLLIDER_TYPE type, Module* callback = nullptr);
	bool EraseCollider(Collider* collider);
	void DebugDraw();

private:

	
};











#endif // !__MODULEPOWERUP_H__
