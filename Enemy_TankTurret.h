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
	Animation up;
	Animation down;
	Animation left;
	Animation right;
	Animation right_up;
	Animation right_down;
	Animation left_up;
	Animation left_down;
	Animation turret_anim[16];
	int shoot;

public:

	Tank_Turret(int x, int y);
//	int life_units = 4;
	void Move();
};

#endif // __TANK_TURRET_H__
