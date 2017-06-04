#ifndef __BOMB_H__
#define __BOMB_H__

#include "Enemy.h"
#include "Path.h"

class Bomb : public Enemy
{
private:
	fPoint original_pos;
	bool going_up = true;
	int original_y = 0;
	Animation bomb;




public:

	Bomb(int x, int y);

	void Move();
};

#endif // __BOMB_H__

