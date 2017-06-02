#ifndef __BOAT_H__
#define __BOAT_H__

#include "Enemy.h"
#include "Path.h"


class Boat : public Enemy
{
private:
	fPoint original_pos;
	Path path;
	bool going_up = true;
	int original_y = 0;
	Animation sail[16];
	Animation shot;
public:

	Boat(int x, int y);
	void Move();
};

#endif // __POWERUPSHIP_H__
