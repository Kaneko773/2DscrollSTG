#pragma once
#include "Enemy.h"

//‚­‚Ë‚­‚Ë“®‚­“G

class SmallEnemy_2 final : public Enemy
{
public:
	SmallEnemy_2();
	virtual ~SmallEnemy_2() {};

	bool HitJudge(shared_ptr<GameObject> target) override;

	void Update(vector<shared_ptr<GameObject>>* gameObjects) override;
	void Show() const override;

private:
	double posY;
	int temp;
	bool stop;
	double ActionTime;
	double actionTimer;
};

