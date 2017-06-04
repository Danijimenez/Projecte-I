#ifndef __TRAIN_H__
#define __TRAIN_H__

#include "Enemy.h"
#include "Path.h"

class Train : public Enemy
{
private:
	fPoint original_pos;
	Path path;
	bool going_up = true;
	int original_y = 0;
	Animation train;




public:

	Train(int x, int y);
	int life_units = 8;
	void Move();
};


#endif // !__BROWNTANK_1__

