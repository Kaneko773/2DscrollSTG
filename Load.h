#pragma once
#include "GameScene.h"

class Load : public GameScene
{
public:
	Load() {};
	virtual ~Load() {};

	virtual void Start() override {};
	virtual void End() override {};
	virtual NextScene* Update() override;
	virtual void Draw() override;

	virtual void AAA() override;////誰のトランジションか確認用
};