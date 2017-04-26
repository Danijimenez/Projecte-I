#ifndef __POWERUP_H__
#define __POWERUP_H__

#include "Enemy.h"
#include "Path.h"

class PowerUp : public Enemy
{
private:
	fPoint original_pos;
	Path path;
	bool going_up = true;
	int original_y = 0;
	Animation power_up;




public:

	PowerUp(int x, int y);

	void Move();
};

#endif // __POWERUP_H__

