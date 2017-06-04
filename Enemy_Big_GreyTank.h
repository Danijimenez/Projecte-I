#ifndef __Enemy_Big_GreyTank_H__
#define __Enemy_Big_GreyTank_H__

#include "Enemy.h"
#include "Path.h"


class Big_GreyTank : public Enemy
{
private:
	fPoint original_pos;
	Path path;
	bool going_up = true;
	int original_y = 0;
	Animation Prepare;
	Animation Open;
	Animation Moving;
	Animation Shoot;

	float proj_speed = 4.0f;
	float speed_x_mult, speed_y_mult, common_mult, a_mult;

public:

	Big_GreyTank(int x, int y, int path);
	int life_units = 8;
	void Move();

};

#endif // __Enemy_Big_GreyTank_H__