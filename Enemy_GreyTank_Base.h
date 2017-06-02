#ifndef __POWERUPSHIP_H__
#define __POWERUPSHIP_H__

#include "Enemy.h"
#include "Path.h"


class PowerUpShip : public Enemy
{
private:
	fPoint original_pos;
	Path path;
	bool going_up = true;
	int original_y = 0;
	Animation fly;
	Animation shoot;
	Animation leave;

public:

	PowerUpShip(int x, int y);
//	int life_units = 5;
	void Move();
};

#endif // __POWERUPSHIP_H__