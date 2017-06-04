#ifndef __Enemy_Big_BrownTank_H__
#define __Enemy_Big_BrownTank_H__

#include "Enemy.h"
#include "Path.h"


class Big_BrownTank : public Enemy
{
private:
	fPoint original_pos;
	bool going_up = true;
	int original_y = 0;
	Animation waiting;
	Animation preparing;
	Animation shoot;
	Path path;
	int shoot_type;

	int proj_speed;


public:

	Big_BrownTank(int x, int y, int path);
	int life_units = 8;
	void Move();

};

#endif // __Enemy_Big_BrownTank_H__