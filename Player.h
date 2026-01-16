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

	void Update() override;
	void Show() const override;

private:
	std::shared_ptr<PlayerDetail> player;
};