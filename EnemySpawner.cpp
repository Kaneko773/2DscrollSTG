#include "EnemySpawner.h"
#include "FrameRateManager.h"

EnemySpawner::EnemySpawner()
{
	timer = 0;
}

EnemySpawner::~EnemySpawner()
{
	details.clear();
}

void EnemySpawner::Set_enemy(shared_ptr<GameObject> _obj, float _time)
{
	SpawnDetails detail = { _obj, _time, false };
	details.push_back(detail);
}

bool EnemySpawner::Update(vector<shared_ptr<GameObject>>* gameObjects)
{
	for (int i = 0; i < details.size(); ++i) {
		if (!details[i].spawn) {
			if (timer >= details[i].time) {
				gameObjects->push_back(details[i].obj);
				details[i].spawn = true;
			}
		}
	}

	timer += FrameRateManager::getInstance()->Get_Deltatime();
}