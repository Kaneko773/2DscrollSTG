#pragma once
#include "SceneBase.h"

//シーンではなく、GameScene階層の仲介役

class GameRoot : public SceneBase
{
public:
	GameRoot();
	virtual ~GameRoot();

	virtual void Start() override;
	virtual void End() override;
	virtual NextScene* Update() override;
	virtual void Draw() override;

	virtual void Transition_Start(SceneBase* prevScene) override;

	virtual void AAA() override;//誰のトランジションか確認用

private:
	SceneBase* currentScene = nullptr;
};

