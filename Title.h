#pragma once
#include "SceneBase.h"

class Title : public SceneBase
{
public:
	Title() {};
	virtual ~Title() {};

	virtual void Start() override {};
	virtual void End() override {};
	virtual NextScene* Update() override;
	virtual void Draw() override;
};

