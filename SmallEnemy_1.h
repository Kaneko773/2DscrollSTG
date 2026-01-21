#pragma once
#include "Enemy.h"

//“Ëi‚·‚é“G

enum Action {
	entry,
	stop,
	rush,
};

class SmallEnemy_1 final : public Enemy
{
public:
	SmallEnemy_1();
	virtual ~SmallEnemy_1() {};

	bool HitJudge(shared_ptr<GameObject> target) override;

	void Update(vector<shared_ptr<GameObject>>* gameObjects) override;
	void Show() const override;

private:
	Action actionState;
	double actionTimer;
};

