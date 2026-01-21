#pragma once
#include "GameScene.h"

#include "Vector2.h"//

#include "GameObject.h"

#include "Triangle.h"
#include "Square.h"

#define STAGE_HEIGHT 480
#define STAGE_WIDTH 640

class Stage1 : public GameScene
{
public:
	Stage1();
	virtual ~Stage1();

	virtual void Start() override {};
	virtual void End() override {};
	virtual NextScene* Update() override;
	virtual void Draw() override;

	virtual void AAA() override;////誰のトランジションか確認用

private:
	vector<shared_ptr<GameObject>> gameObjects;//子

	int handle_BackGround;
	double backGround_DrawPos_x;

	VECTOR_D playerHpUI[4] = { {20, 10}, {50, 10}, {40, 50}, {10, 50} };
};