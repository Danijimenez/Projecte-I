#ifndef __GREY_TANK_H_
#define __GREY_TANK_H_

#include "Enemy.h"
#include "Path.h"


class GreyTank_Base : public Enemy
{
private:
	fPoint original_pos;
	Path path;
	bool going_up = true;
	int original_y = 0;
	Animation Grey_Tank[3];
	Enemy* turret = nullptr;


public:

	GreyTank_Base(int x, int y, int path);
	int life_units = 8;
	void Move();
};


#endif // __GREY_TANK_H_