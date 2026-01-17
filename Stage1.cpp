#include "Stage1.h"
#include "DxLib.h"
#include "InputManager.h"

#include "Player.h"
#include "Test_smallEnemy.h"

#include "Bullet.h"

//‘JˆÚæ


Stage1::Stage1()
{
	shared_ptr<Player> player = make_shared<Player>();
	gameObjects.push_back(player);
	//shared_ptr<Test_smallEnemy> enemy = make_shared<Test_smallEnemy>();
	//gameObjects.push_back(enemy);
}

Stage1::~Stage1()
{

}

NextScene* Stage1::Update()
{
	for (int i = 0; i < gameObjects.size(); ++i) {
		gameObjects[i]->Update(&gameObjects);
	}

	//ƒeƒXƒg
	//“–‚½‚è”»’è
	for (int i = 0; i < gameObjects.size() - 1; ++i) {
		for (int j = i + 1; j < gameObjects.size(); ++j) {

			if (gameObjects[i]->Get_manager() == gameObjects[j]->Get_manager()) { continue; }//ŠÇ—Ò‚ªˆê‚È‚ç”»’è–³‚µ

			if (gameObjects[i]->HitJudge(gameObjects[j])) {
				gameObjects[i]->Get_Damage();
				gameObjects[j]->Get_Damage();
			}
		}
	}

	gameObjects.erase(std::remove_if(gameObjects.begin(), gameObjects.end(), [](shared_ptr<GameObject> n) {
		shared_ptr<Bullet> temp = dynamic_pointer_cast<Bullet>(n);
		if (temp != nullptr) {
			if (n->Get_Hp() <= 0) return true;
		}
		return false;
		}), gameObjects.end());

	return this;
}
void Stage1::Draw()
{
	DrawString(250, 240 - 32, "Stage1", GetColor(255, 255, 255));

	for (int i = 0; i < gameObjects.size(); ++i) {
		gameObjects[i]->Show();
	}
}

void Stage1::AAA() {
	printfDx("Stage1");
}