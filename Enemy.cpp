#include "Application.h"
#include "Enemy_BasicEnemy.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"

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

	switch (collider->type)	{
	case COLLIDER_ENEMMY_TURRET:
		App->particles->AddParticle(App->particles->turret_explosion, position.x, position.y, COLLIDER_NONE, 0);
	break;
	case COLLIDER_ENEMY_BASIC:
		App->particles->AddParticle(App->particles->turret_explosion, position.x, position.y, COLLIDER_NONE, 0);
		break;
	default:
		break;
	}
	
	collider->to_delete = true;
}