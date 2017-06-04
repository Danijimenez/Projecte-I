#ifndef __BEE_H__
#define __BEE_H__

#include "Enemy.h"
#include "Path.h"

class Bee : public Enemy
{
private:
	fPoint original_pos;
	Path path;
	bool going_up = true;
	int original_y = 0;
	Animation spawn;
	Animation charge;
	Animation leave;
	
	float proj_speed = 2.0f;
	float speed_x_mult, speed_y_mult, common_mult, a_mult;
	bool direction = false;

public:

	Bee(int x, int y);

	void Move();
};

#endif // __BEE_H__
