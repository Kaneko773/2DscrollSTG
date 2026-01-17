#pragma once
#include "GameObject.h"

class PlayerDetail final : public GameObject
{
public:
	PlayerDetail() {};
	virtual ~PlayerDetail() {};

	virtual bool HitJudge(shared_ptr<GameObject> target) override;

	virtual void Update(vector<shared_ptr<GameObject>>* gameObjects) override;
	void Show() const override;
};