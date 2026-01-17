#include "Bullet.h"

#include "FrameRateManager.h"

Bullet::Bullet()
{
	hp = 1;

	dir = 0;
}

void Bullet::Update(vector<shared_ptr<GameObject>>* gameObjects)
{
	MoveX(FrameRateManager::getInstance()->Get_Deltatime() * 100 * dir);

	Circle::Update(gameObjects);
}