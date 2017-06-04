#include "Application.h"
#include "Enemy_BasicEnemy.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "PowerUp.h"
#include "ModuleEnemies.h"
#include "ModuleAudio.h"


Enemy::Enemy(int x, int y) : position(x, y)
{}

Enemy::~Enemy()
{
	if (collider != nullptr)
		collider->to_delete = true;
}

const Collider* Enemy::GetCollider() const
{
	return collider;
}



void Enemy::Draw(SDL_Texture* sprites)
{
	if (collider != nullptr)
		collider->SetPos(position.x, position.y);

	if (animation != nullptr)
		App->render->Blit(sprites, position.x, position.y, &(animation->GetCurrentFrame()));
}

void Enemy::OnCollision(Collider* c1, Collider* c2)
{
	//if (c2->type)
	switch (collider->type) {
	case COLLIDER_ENEMY_TURRET:
		App->particles->AddParticle(App->particles->ground_explosion, position.x, position.y, COLLIDER_NONE, 0);

		break;
	case COLLIDER_ENEMY_WAGON:
		App->particles->AddParticle(App->particles->ground_explosion, position.x, position.y, COLLIDER_NONE, 0);
		break;
	case COLLIDER_ENEMY_BOSS:
		App->particles->AddParticle(App->particles->air_enemy_explosion, position.x, position.y, COLLIDER_NONE, 0);
		App->particles->AddParticle(App->particles->air_enemy_explosion, position.x+5, position.y-5, COLLIDER_NONE, 5);
		App->particles->AddParticle(App->particles->air_enemy_explosion, position.x-5, position.y+5, COLLIDER_NONE, 10);
		App->particles->AddParticle(App->particles->air_enemy_explosion, position.x-10, position.y+10, COLLIDER_NONE, 15);
		App->particles->AddParticle(App->particles->air_enemy_explosion, position.x-5, position.y-5, COLLIDER_NONE, 20);
		App->particles->AddParticle(App->particles->air_enemy_explosion, position.x+5, position.y+5, COLLIDER_NONE, 25);
		App->particles->AddParticle(App->particles->air_enemy_explosion, position.x, position.y, COLLIDER_NONE, 30);
		break;

		
	case COLLIDER_ENEMY_BASIC:
		App->particles->AddParticle(App->particles->basic_enemy_explosion, position.x, position.y, COLLIDER_NONE, 0);
		Mix_PlayChannel(-1, App->audio->basic_enemy_explosion, 0);
		break;
	case COLLIDER_ENEMY_GREENSHIP:
		App->particles->AddParticle(App->particles->air_enemy_explosion, position.x, position.y, COLLIDER_NONE, 0);
		Mix_PlayChannel(-1, App->audio->green_ship_explosion, 0);

		break;
	case COLLIDER_DARK_BOX:
		App->particles->AddParticle(App->particles->ground_explosion, position.x, position.y, COLLIDER_NONE, 0);
		App->enemies->AddEnemy(MISSILE, position.x + 15, position.y + 15);

	case COLLIDER_ENEMY_POWERUPSHIP:
		App->particles->AddParticle(App->particles->air_enemy_explosion, position.x, position.y, COLLIDER_NONE, 0);
		App->enemies->AddEnemy(POWERUP, position.x + 28, position.y + 29);
		Mix_PlayChannel(-1, App->audio->powerup_ship_explosion, 0);
		break;
	case COLLIDER_ENEMY_TANK:
		App->particles->AddParticle(App->particles->ground_explosion, position.x, position.y, COLLIDER_NONE, 0);

		break;
	case COLLIDER_POWER_UP_LASER:
		if (c1->type == COLLIDER_PLAYER) {
			if (App->player->shoot_type != SHOOT_TYPE::LASER) {
				App->player->shoot_type = SHOOT_TYPE::LASER;
			}
			else if (App->player->shoot_type == SHOOT_TYPE::LASER) {
				App->player->shoot_type = SHOOT_TYPE::LASER_LVL2;
			}
		}
		else {
			if (App->player2->shoot_type != SHOOT_TYPE::LASER) {
				App->player2->shoot_type = SHOOT_TYPE::LASER;
			}
			else if (App->player2->shoot_type == SHOOT_TYPE::LASER) {
				App->player2->shoot_type = SHOOT_TYPE::LASER_LVL2;
			}
		}
		break;
	case COLLIDER_POWER_UP_VULCAN:
		if (c1->type == COLLIDER_PLAYER) {
			if (App->player->shoot_type != SHOOT_TYPE::LASER) {
				App->player->shoot_type = SHOOT_TYPE::LASER;
			}
			else if (App->player->shoot_type == SHOOT_TYPE::LASER) {
				App->player->shoot_type = SHOOT_TYPE::LASER_LVL2;
			}
		}
		else {
			if (App->player2->shoot_type != SHOOT_TYPE::LASER) {
				App->player2->shoot_type = SHOOT_TYPE::LASER;
			}
			else if (App->player2->shoot_type == SHOOT_TYPE::LASER) {
				App->player2->shoot_type = SHOOT_TYPE::LASER_LVL2;
			}
		}
		break;
	case COLLIDER_MISSILE_HOMING:
		if (c1->type == COLLIDER_PLAYER) {
			App->player->homing = true;
		}
		else {
			App->player2->homing = true;
		}
		break;

	case COLLIDER_MISSILE_NUCLEAR:
		if (c1->type == COLLIDER_PLAYER) {
			App->player->nuclear= true;
		}
		else {
			App->player2->nuclear = true;
		}
		break;
	default:
		break;
	}
	
	collider->to_delete = true;
}
