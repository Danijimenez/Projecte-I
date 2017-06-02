#ifndef __BROWNTANK_1__

#include "Enemy.h"
#include "Path.h"

class BrownTank_Base : public Enemy
{
private:
	fPoint original_pos;
	Path path;
	bool going_up = true;
	int original_y = 0;
	Animation Brown_Tank;
	Enemy* turret = nullptr;



public:

	BrownTank_Base(int x, int y, int path);
	int life_units = 8;
	void Move();
};


#endif // !__BROWNTANK_1__

