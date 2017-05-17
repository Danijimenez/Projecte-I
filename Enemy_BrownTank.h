#ifndef __ENEMY_BROWN_TANK_H__
#define __ENEMY_BROWN_TANK_H__

#include "Enemy.h"
#include "Path.h"

class BrownTank : public Enemy
{
private:
	fPoint original_pos;
	Path path;
	bool going_up = true;
	int original_y = 0;
	Animation leave;
	Animation anim[16];
	

public:

	BrownTank(int x, int y);

	void Move();
};

#endif // __ENEMY_BROWN_TANK_H__
