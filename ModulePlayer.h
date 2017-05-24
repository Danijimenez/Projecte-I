#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"

struct SDL_Texture;
struct Collider;

enum SHOOT_TYPE {
	STANDARD,
	LASER,
	LASER_LVL2,
	VULCAN,
	VULCAN_LVL2
};

class ModulePlayer : public Module
{
public:
	ModulePlayer();
	~ModulePlayer();

	bool Start();
	update_status Update();
	bool CleanUp();
	void OnCollision(Collider* c1, Collider* c2);

public:

	SDL_Texture* graphics = nullptr;
	Animation* current_animation = nullptr;
	Animation idle;
	Animation right[2];
	Animation left[2];
	iPoint position;
	bool started = false;
	Collider* player;
	SHOOT_TYPE shoot_type = STANDARD;
	bool can_reset = false;
	int left_anim = 0;
	int right_anim = 0;
	bool move_up = true;
	bool move_down = true;

	bool move = true;

	int font_score = -1;
	char score_text[10];
	char hiscore_text[10];
	bool destroyed = false;
	float speed = 1;
	
	float move_speed;
	int lifes;
	int player_points = 0;
	bool living = false;
	bool hittable = true;
	int damage = 0;
	int bombs;
	bool movep;

	bool homing = true;
	bool nuclear = false;
	bool ammo = true;
	float enemy_speed = 3.0f;
	float speed_x_mult, speed_y_mult, common_mult, a_mult;

	bool homing_shot = false;

};

#endif



