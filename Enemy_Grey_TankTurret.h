#ifndef __TANK_TURRET_H__
#define __TANK_TURRET_H__

#include "Enemy.h"
#include "Path.h"


class Tank_Turret : public Enemy
{
private:
	fPoint original_pos;
	Path path;
	bool going_up = true;
	int original_y = 0;

	Animation turret_anim[16];
	int shoot;

public:

	Tank_Turret(int x, int y);
	void Move();
};

#endif // __TANK_TURRET_H__
