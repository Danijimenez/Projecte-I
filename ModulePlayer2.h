#ifndef __ModulePlayer2_H__
#define __ModulePlayer2_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"
#include "ModulePlayer.h"

struct SDL_Texture;
struct Collider;
enum SHOOT_TYPE;

class ModulePlayer2 : public Module
{
public:
	ModulePlayer2();
	~ModulePlayer2();

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
	SHOOT_TYPE shoot_type;
	Collider* player2;
	bool can_reset = false;
	int left_anim = 0;
	int right_anim = 0;
	bool move_up = true;
	bool move_down = true;
	bool living = false;
	int bombs;
	int font_score = -1;
	char score_text[10];
	char hiscore_text[10];
	bool destroyed = false;
	int speed = 1;
	bool hittable = true;
	float move_speed;
	int lifes;
	int player_points = 0;



	bool homing = true;
	bool nuclear = false;
	bool ammo = true;
	float enemy_speed = 3.0f;
	float speed_x_mult, speed_y_mult, common_mult, a_mult;

	bool homing_shot = false;

};

#endif



