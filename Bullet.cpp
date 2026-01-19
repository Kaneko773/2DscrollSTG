#include "Bullet.h"

#include "FrameRateManager.h"

Bullet::Bullet()
{
	hp = 1;

	dir = 0;
}

void Bullet::Update(vector<shared_ptr<GameObject>>* gameObjects)
{
	if (transform.x < -100) hp = 0;//
	if (transform.x > 740) hp = 0;//

	MoveX(FrameRateManager::getInstance()->Get_Deltatime() * 100 * dir);

	Circle::Update(gameObjects);
}