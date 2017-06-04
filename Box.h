#ifndef __BOX_H__
#define __BOX_H__

#include "Enemy.h"
#include "Path.h"

class Box : public Enemy
{
private:
	fPoint original_pos;
	bool going_up = true;
	int original_y = 0;
	Animation box;




public:

	Box(int x, int y);

	void Move();
};

#endif // __BOX_H__

