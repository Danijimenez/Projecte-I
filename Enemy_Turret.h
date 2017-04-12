#ifndef __TURRET_H__
#define __TURRET_H__

#include "Enemy.h"
#include "Path.h"


class Turret : public Enemy
{
private:
	iPoint original_pos;
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

public:

	Turret(int x, int y);

	void Move();
};

#endif // __TURRET_H__
