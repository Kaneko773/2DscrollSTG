#pragma once
#include "GameObject.h"

class EnemyDetail final : public GameObject
{
public:
	EnemyDetail() {};
	virtual ~EnemyDetail() {};

	virtual bool HitJudge(shared_ptr<GameObject> target) override;

	virtual void Update(vector<shared_ptr<GameObject>>* gameObjects) override;
	void Show() const override;
};