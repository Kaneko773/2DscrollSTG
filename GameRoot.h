#pragma once
#include "SceneBase.h"

//ƒV[ƒ“‚Å‚Í‚È‚­AGameSceneŠK‘w‚Ì’‡‰î–ğ

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

private:
	SceneBase* currentScene = nullptr;
};

