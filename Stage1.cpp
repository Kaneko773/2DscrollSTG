#include "Stage1.h"
#include "DxLib.h"
#include "InputManager.h"
#include "FrameRateManager.h"

#include "Player.h"
#include "Test_smallEnemy.h"

#include "Bullet.h"

//遷移先


Stage1::Stage1()
{
	handle_BackGround = LoadGraph("画像/space.png");
	backGround_DrawPos_x = 0;

	shared_ptr<Player> player = make_shared<Player>();
	gameObjects.push_back(player);
	shared_ptr<Test_smallEnemy> enemy = make_shared<Test_smallEnemy>();
	gameObjects.push_back(enemy);
}

Stage1::~Stage1()
{
	DeleteGraph(handle_BackGround);

	gameObjects.clear();
}

NextScene* Stage1::Update()
{
	for (int i = 0; i < gameObjects.size(); ++i) {
		gameObjects[i]->Update(&gameObjects);
	}

	//テスト
	//当たり判定
	//リセット
	for (int i = 0; i < gameObjects.size(); ++i) {
		gameObjects[i]->Reset_Hit();
	}
	for (int i = 0; i < gameObjects.size() - 1; ++i) {
		for (int j = i + 1; j < gameObjects.size(); ++j) {

			if (gameObjects[i]->Get_manager() == gameObjects[j]->Get_manager()) continue;//管理者が一緒なら判定無し
			if (gameObjects[i]->Get_Hit() || gameObjects[j]->Get_Hit()) continue;//このフレームで１度でも当たっていれば他とは当たらない

			//プレイヤーが無敵状態なら判定無し
			//一時的
			shared_ptr<Player> temp1 = dynamic_pointer_cast<Player>(gameObjects[i]);
			if (temp1 != nullptr) {
				if (temp1->Get_Invincible()) continue;
			}
			shared_ptr<Player> temp2 = dynamic_pointer_cast<Player>(gameObjects[j]);
			if (temp2 != nullptr) {
				if (temp2->Get_Invincible()) continue;
			}

			if (gameObjects[i]->HitJudge(gameObjects[j])) {
				gameObjects[i]->Get_Damage();
				gameObjects[j]->Get_Damage();
			}
		}
	}

	gameObjects.erase(std::remove_if(gameObjects.begin(), gameObjects.end(), [](shared_ptr<GameObject> n) {
		if (n->Get_Hp() <= 0) return true;
		return false;
		}), gameObjects.end());


	//背景移動
	backGround_DrawPos_x -= FrameRateManager::getInstance()->Get_Deltatime() * 50;
	if (backGround_DrawPos_x <= STAGE_WIDTH * -1)backGround_DrawPos_x += STAGE_WIDTH;

	return this;
}
void Stage1::Draw()
{
	//DrawGraph((int)backGround_DrawPos_x, 0, handle_BackGround, TRUE);
	//DrawGraph((int)backGround_DrawPos_x + STAGE_WIDTH, 0, handle_BackGround, TRUE);

	printfDx("%d", gameObjects.size());

	DrawString(250, 240 - 32, "Stage1", GetColor(255, 255, 255));

	for (int i = 0; i < gameObjects.size(); ++i) {
		gameObjects[i]->Show();
	}
}

void Stage1::AAA() {
	printfDx("Stage1");
}