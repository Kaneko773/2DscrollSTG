#include "Enemy.h"

Enemy::Enemy()
{
	enemy = std::make_shared<EnemyDetail>();
}

bool Enemy::HitJudge(shared_ptr<GameObject> target)
{
	return enemy->HitJudge(target);
}

void Enemy::Update()
{
	enemy->Update();
}

void Enemy::Show() const
{
	enemy->Show();
}