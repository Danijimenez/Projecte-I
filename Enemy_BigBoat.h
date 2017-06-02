#ifndef __BIG_BOAT_H__
#define __BIG_BOAT_H__

#include "Enemy.h"
#include "Path.h"


class BigBoat : public Enemy
{
private:
	fPoint original_pos;
	Path path;
	bool going_up = true;
	int original_y = 0;
	Animation sail;
	Animation shot;
public:

	BigBoat(int x, int y);
	void Move();
};

#endif // __BIG_BOAT_H__
