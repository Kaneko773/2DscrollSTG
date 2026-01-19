#pragma once
#include "PlayerDetail.h"

//ラッパークラス
class Player final : public GameObject
{
public:
	Player();
	virtual ~Player() {};

	bool HitJudge(shared_ptr<GameObject> target) override;

	void Summarize(vector<shared_ptr<GameObject>>* targets) override;

	void Update(vector<shared_ptr<GameObject>>* gameObjects) override;
	void Show() const override;

	shared_ptr<PlayerDetail> Get_player() const{
		return player;
	}

	bool Get_Invincible() const {
		return invincible;
	}

	void Get_Damage() override{
		hp -= 1;
		hit = true;
		invincible = true;
		invincibleTimer = 0;
		prevBlinkingTime = invincibleTimer;
	}

private:
	shared_ptr<PlayerDetail> player;
	const double InvincibleTime = 1;
	double invincibleTimer;
	bool invincible;
	double prevBlinkingTime;
	bool hide;
};