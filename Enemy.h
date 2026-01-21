#pragma once
#include "EnemyDetail.h"
#include "Explosion_Animation.h"

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
		if (hp <= 0)explosion_animation.Explosion_Start(30);
	}

protected:
	std::shared_ptr<EnemyDetail> enemy;

	Explosion_Animation explosion_animation;
};