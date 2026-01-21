#pragma once
#include <vector>
#include <memory>//shared_ptr

class GameObject;

using namespace std;

struct SpawnDetails {
	shared_ptr<GameObject> obj;
	float time;
	bool spawn;
};

class EnemySpawner
{
public:
	EnemySpawner();
	virtual ~EnemySpawner();

	void Set_enemy(shared_ptr<GameObject> _obj, float _time);

	void Update(vector<shared_ptr<GameObject>>* gameObjects);

	bool Spawn_Finish() const {
		return finish;
	}

private:
	float timer;
	vector<SpawnDetails> details;

	bool finish;
};

