#ifndef __MISSILE_H__
#define __MISSILE_H__

#include "Enemy.h"
#include "Path.h"

class Missile : public Enemy
{
private:

	fPoint original_pos;
	Path path;
	bool going_up = true;
	int original_y = 0;
	Animation nuclear;
	Animation homing;

	
public:

	Missile(int x, int y);

	void Move();
};

#endif // __MISSILE_H__

