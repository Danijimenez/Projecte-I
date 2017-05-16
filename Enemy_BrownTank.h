
#include "Enemy.h"
#include "Path.h"

class BasicEnemy : public Enemy
{
private:
	fPoint original_pos;
	Path path;
	bool going_up = true;
	int original_y = 0;
	Animation leave;
	Animation anim[16];
	

public:

	BasicEnemy(int x, int y);

	void Move();
};

