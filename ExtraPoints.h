#ifndef __EXTRAPOINTS_H__
#define __EXTRAPOINTS_H__

#include "Enemy.h"
#include "Path.h"

class ExtraPoints : public Enemy
{
private:
	fPoint original_pos;
	Path path;
	bool going_up = true;
	int original_y = 0;
	Animation medal;
	Animation miclus;

public:

	ExtraPoints(int x, int y);

	void Move();
};

#endif // __EXTRAPOINTS_H__

