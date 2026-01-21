#include "Stage1.h"
#include "DxLib.h"
#include "InputManager.h"
#include "FrameRateManager.h"

#include "Player.h"
#include "SmallEnemy_1.h"
#include "SmallEnemy_2.h"

#include "Bullet.h"

//遷移先


Stage1::Stage1()
{
	handle_BackGround = LoadGraph("画像/space.png");
	backGround_DrawPos_x = 0;

	//gameObjectsが０にならないように 応急処置
	shared_ptr<Circle> circle = make_shared<Circle>();
	gameObjects.push_back(circle);
	circle->Set_Transform_y(-1000);
	circle->Set_hp(10000);

	shared_ptr<Player> player = make_shared<Player>();
	gameObjects.push_back(player);
	shared_ptr<SmallEnemy_1> enemy = make_shared<SmallEnemy_1>();
	gameObjects.push_back(enemy);
}

Stage1::~Stage1()
{
	DeleteGraph(handle_BackGround);

	gameObjects.clear();
}

NextScene* Stage1::Update()
{
	//オブジェクトの更新
	for (int i = 0; i < gameObjects.size(); ++i) {
		gameObjects[i]->Update(&gameObjects);
	}

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

	//オブジェクト消去
	gameObjects.erase(std::remove_if(gameObjects.begin(), gameObjects.end(), [](shared_ptr<GameObject> n) {
		if (n->Get_Destroy()) return true;
		return false;
		}), gameObjects.end());

	//背景移動
	backGround_DrawPos_x -= FrameRateManager::getInstance()->Get_Deltatime() * 50;
	if (backGround_DrawPos_x <= STAGE_WIDTH * -1)backGround_DrawPos_x += STAGE_WIDTH;

	//敵生成


	return this;
}
void Stage1::Draw()
{
	DrawGraph((int)backGround_DrawPos_x, 0, handle_BackGround, TRUE);
	DrawGraph((int)backGround_DrawPos_x + STAGE_WIDTH, 0, handle_BackGround, TRUE);

	//プレイヤーのHP
	for (int i = 0; i < gameObjects.size(); ++i) {
		if (gameObjects[i]->Get_manager() == "Player") {
			for (int hp = 0; hp < gameObjects[i]->Get_Hp(); ++hp) {

				unsigned int color = GetColor(255, 255, 255);
				switch (hp) {
				case 0:
					color = GetColor(255, 0, 0);//赤　オレンジ　黄色　黄緑　緑
					break;
				case 1:
					color = GetColor(255, 165, 0);
					break;
				case 2:
					color = GetColor(255, 255, 0);
					break;
				case 3:
					color = GetColor(181, 255, 20);
					break;
				case 4:
					color = GetColor(0, 255, 0);
					break;
				}

				DrawTriangle(
					(int)playerHpUI[0].x + (hp * 35), (int)playerHpUI[0].y,
					(int)playerHpUI[1].x + (hp * 35), (int)playerHpUI[1].y,
					(int)playerHpUI[2].x + (hp * 35), (int)playerHpUI[2].y,
					color, TRUE);
				DrawTriangle(
					(int)playerHpUI[0].x + (hp * 35), (int)playerHpUI[0].y,
					(int)playerHpUI[3].x + (hp * 35), (int)playerHpUI[3].y,
					(int)playerHpUI[2].x + (hp * 35), (int)playerHpUI[2].y,
					color, TRUE);
			}
		}
	}

	DrawString(250, 240 - 32, "Stage1", GetColor(255, 255, 255));

	for (int i = 0; i < gameObjects.size(); ++i) {
		gameObjects[i]->Show();
	}
}

void Stage1::AAA() {
	printfDx("Stage1");
}