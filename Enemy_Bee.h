#ifndef __BEE_H__
#define __BEE_H__

#include "Enemy.h"
#include "Path.h"

class Bee : public Enemy
{
private:
	fPoint original_pos;
	Path path;
	bool going_up = true;
	int original_y = 0;
	Animation spawn;
	Animation charge;
	Animation leave;
	

public:

	Bee(int x, int y);

	void Move();
};

#endif // __BEE_H__
