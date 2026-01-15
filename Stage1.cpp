#include "Stage1.h"
#include "DxLib.h"
#include "InputManager.h"

#include "Player.h"
#include "Test_smallEnemy.h"

//遷移先


Stage1::Stage1()
{
	InputManager::getInstance()->Set_input_keyFewSec_time(KEY_INPUT_W, 0.01f);
	InputManager::getInstance()->Set_input_keyFewSec_time(KEY_INPUT_A, 0.01f);
	InputManager::getInstance()->Set_input_keyFewSec_time(KEY_INPUT_S, 0.01f);
	InputManager::getInstance()->Set_input_keyFewSec_time(KEY_INPUT_D, 0.01f);
	InputManager::getInstance()->Set_input_keyFewSec_time(KEY_INPUT_RIGHT, 0.01f);
	InputManager::getInstance()->Set_input_keyFewSec_time(KEY_INPUT_LEFT, 0.01f);
	InputManager::getInstance()->Set_input_keyFewSec_time(KEY_INPUT_UP, 0.01f);
	InputManager::getInstance()->Set_input_keyFewSec_time(KEY_INPUT_DOWN, 0.01f);

	//shared_ptr<Player> player = make_shared<Player>();
	//gameObjects.push_back(player);
	shared_ptr<Test_smallEnemy> enemy = make_shared<Test_smallEnemy>();
	gameObjects.push_back(enemy);
}

Stage1::~Stage1()
{

}

NextScene* Stage1::Update()
{
	for (int i = 0; i < gameObjects.size(); ++i) {
		gameObjects[i]->Update();
	}

	//テスト
	//当たり判定
	for (int i = 0; i < gameObjects.size() - 1; ++i) {
		if (gameObjects[i]->HitJudge(gameObjects[i + 1])) {
			gameObjects[i]->hit = true;
		}
		else {
			gameObjects[i]->hit = false;
		}
	}
	

	return this;
}
void Stage1::Draw()
{
	//テスト
	//当たり判定
	if (gameObjects[0]->hit)printfDx("当たってる"); else printfDx("当たってない");

	DrawString(250, 240 - 32, "Stage1", GetColor(255, 255, 255));

	for (int i = 0; i < gameObjects.size(); ++i) {
		gameObjects[i]->Show();
	}
}

void Stage1::AAA() {
	printfDx("Stage1");
}