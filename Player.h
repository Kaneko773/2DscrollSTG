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

private:
	shared_ptr<PlayerDetail> player;
};