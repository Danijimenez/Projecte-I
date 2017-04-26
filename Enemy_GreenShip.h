#ifndef __GREENSHIP_H__
#define __GREENSHIP_H__

#include "Enemy.h"
#include "Path.h"


class GreenShip : public Enemy
{
private:
	fPoint original_pos;
	Path path;
	bool going_up = true;
	int original_y = 0;
	Animation fly;
	Animation leave;
	Animation back;
	Animation leave_back;

public:

	GreenShip(int x, int y);
	void Move();
};

#endif // __POWERUPSHIP_H__
