#pragma once
#include "Transition.h"

class SceneBase;
using NextScene = SceneBase;

class SceneBase : public Transition {
public:
	SceneBase() {};
	virtual ~SceneBase() {};

	virtual void Start() = 0;
	virtual void End() = 0;
	virtual NextScene* Update() = 0;
	virtual void Draw() = 0;

	virtual void AAA() {};//誰のトランジションか確認用
};