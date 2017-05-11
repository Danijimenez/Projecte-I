#ifndef __BASIC_ENEMY2__
#define __BASIC_ENEMY2__

#include "Enemy.h"
#include "Path.h"

class BasicEnemy2 : public Enemy
{
private:
	fPoint original_pos;
	Path path;
	bool going_up = true;
	bool direction=false;
	int original_y = 0;
	Animation up;
	Animation down;
	Animation left;
	Animation right;
	Animation right_up;
	Animation right_down;
	Animation left_up;
	Animation left_down;
	Animation anim[16];

	float proj_speed = 3.0f;
	float speed_x_mult, speed_y_mult, common_mult, a_mult;

public:

	BasicEnemy2(int x, int y);

	void Move();
};

#endif // __BASIC_ENEMY2__
