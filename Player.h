#pragma once
#include "PlayerDetail.h"

//ラッパークラス
class Player final : public GameObject
{
public:
	Player();
	virtual ~Player();

	virtual void Update() override;
	void Show() const override;

private:
	std::shared_ptr<PlayerDetail> player;
};

