#include "Stage1.h"
#include "DxLib.h"
#include "InputManager.h"
#include "Player.h"

#include "Circle.h"
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

	shared_ptr<Player> player = make_shared<Player>();
	gameObjects.push_back(player);

	shared_ptr<Circle> circle = make_shared<Circle>();
	gameObjects.push_back(circle);
	circle->Test_Set_tr_sc({ 100, 100 }, { 50, 50 });
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
	//オブジェクトがprimitiveなら判定　違うなら無視
	//当たり判定の関数に対象を渡して子オブジェクトがprimitiveなら判定　違うなら無視

	

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