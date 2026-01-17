#pragma once
#include "Enemy.h"

class Test_smallEnemy final : public Enemy
{
public:
	Test_smallEnemy();
	virtual ~Test_smallEnemy() {};

	bool HitJudge(shared_ptr<GameObject> target) override;

	void Update(vector<shared_ptr<GameObject>>* gameObjects) override;
	void Show() const override;
};

