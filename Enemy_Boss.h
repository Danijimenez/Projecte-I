#ifndef __BOSS_H__
#define __BOSS_H__

#include "Enemy.h"
#include "Path.h"


class Boss : public Enemy
{
private:
	fPoint original_pos;
	Path path;
	bool going_up = true;
	int original_y = 0;
	Animation Open;
	Animation Moving;
	Animation Shoot;

public:

	Boss(int x, int y);
	int life_units = 8;
	void Move();

};

#endif // __Enemy_Big_GreyTank_H__