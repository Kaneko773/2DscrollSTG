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

	virtual void Update() = 0;
	virtual void Show() const = 0;

protected:
	std::shared_ptr<EnemyDetail> enemy;
};