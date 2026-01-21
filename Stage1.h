#pragma once
#include "GameScene.h"
#include <vector>
#include <memory>//shared_ptr
#include "DxLib.h"

class GameObject;
class EnemySpawner;

#define STAGE_HEIGHT 480
#define STAGE_WIDTH 640

using namespace std;

class Stage1 : public GameScene
{
public:
	Stage1();
	virtual ~Stage1();

	virtual void Start() override {};
	virtual void End() override {};
	virtual NextScene* Update() override;
	virtual void Draw() override;

private:
	vector<shared_ptr<GameObject>> gameObjects;//Žq

	int handle_BackGround;
	double backGround_DrawPos_x;

	VECTOR_D playerHpUI[4] = { {20, 10}, {50, 10}, {40, 50}, {10, 50} };

	EnemySpawner* enemySpawner;
};