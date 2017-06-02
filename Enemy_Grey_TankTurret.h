#ifndef __GREY_TANK_TURRET_H__
#define __GREY_TANK_TURRET_H__

#include "Enemy.h"
#include "Path.h"


class GreyTank_Turret : public Enemy
{
private:
	fPoint original_pos;
	Path path;
	bool going_up = true;
	int original_y = 0;

	Animation turret_anim[16];
	int shoot;

public:

	GreyTank_Turret(int x, int y);
	void Move();
};

#endif // __TANK_TURRET_H__
