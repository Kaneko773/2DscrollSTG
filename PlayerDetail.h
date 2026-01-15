#pragma once
#include "GameObject.h"

class PlayerDetail final : public GameObject
{
public:
	PlayerDetail();
	virtual ~PlayerDetail();

	virtual void Update() override;
	void Show() const override;

	void Initialization(shared_ptr<GameObject> player);//Playerのコンストラクタで１回呼ぶ

private:

};

