#pragma once
#include "EnemyDetail.h"

//ラッパークラス
class Enemy : public GameObject
{
public:
	Enemy() {};
	virtual ~Enemy() {};

	virtual bool HitJudge(shared_ptr<GameObject> target) = 0;

	void Summarize(vector<shared_ptr<GameObject>>* targets) override;

	virtual void Update(vector<shared_ptr<GameObject>>* gameObjects) = 0;
	virtual void Show() const = 0;

	void Get_Damage() override {
		hp -= 1;
		hit = true;
	}

protected:
	std::shared_ptr<EnemyDetail> enemy;
};