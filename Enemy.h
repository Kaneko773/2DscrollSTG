#pragma once
#include "EnemyDetail.h"

//ラッパークラス
class Enemy : public GameObject
{
public:
	Enemy();
	virtual ~Enemy() {};

	virtual bool HitJudge(shared_ptr<GameObject> target) override;

	virtual void Update() override;
	void Show() const override;

protected:
	std::shared_ptr<EnemyDetail> enemy;
};