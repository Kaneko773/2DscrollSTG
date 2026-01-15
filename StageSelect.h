#pragma once
#include "GameScene.h"

class StageSelect : public GameScene
{
public:
	StageSelect() {};
	virtual ~StageSelect() {};

	virtual void Start() override {};
	virtual void End() override {};
	virtual NextScene* Update() override;
	virtual void Draw() override;

	virtual void AAA() override;////誰のトランジションか確認用
};

