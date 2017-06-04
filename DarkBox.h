#ifndef __DARKBOX_H__
#define __DARKBOX_H__

#include "Enemy.h"
#include "Path.h"

class DarkBox : public Enemy
{
private:
	fPoint original_pos;
	bool going_up = true;
	int original_y = 0;
	Animation darkbox;




public:

	DarkBox(int x, int y);

	void Move();
};

#endif // __DARKBOX_H__


