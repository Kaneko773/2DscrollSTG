#include "EnemySpawner.h"
#include "FrameRateManager.h"

EnemySpawner::EnemySpawner()
{
	timer = 0;
	finish = false;
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

void EnemySpawner::Update(vector<shared_ptr<GameObject>>* gameObjects)
{
	if (finish) return;

	for (int i = 0; i < details.size(); ++i) {
		if (!details[i].spawn) {
			if (timer >= details[i].time) {
				gameObjects->push_back(details[i].obj);
				details[i].spawn = true;
				//ÅŒã‚ð¶¬
				if ((i + 1) == details.size()) finish = true;
			}
		}
	}

	timer += FrameRateManager::getInstance()->Get_Deltatime();
}