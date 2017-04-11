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
	Animation fly;

public:

	BasicEnemy(int x, int y);

	void Move();
};

#endif // __BASIC_ENEMY__
