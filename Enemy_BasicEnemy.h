#ifndef __BASIC_ENEMY__
#define __BASIC_ENEMY__

#include "Enemy.h"
#include "Path.h"

class BasicEnemy : public Enemy
{
private:
	iPoint original_pos;
	Path path;
	bool going_up = true;
	int original_y = 0;
	Animation up;
	Animation down;
	Animation left;
	Animation right;
	Animation right_up;
	Animation right_down;
	Animation left_up;
	Animation left_down;
	

public:

	BasicEnemy(int x, int y);

	void Move();
};

#endif // __BASIC_ENEMY__
