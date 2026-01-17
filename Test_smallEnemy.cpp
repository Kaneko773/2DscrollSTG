#include "Test_smallEnemy.h"

#include "Square.h"
#include "Triangle.h"

#include "InputManager.h"
#include "FrameRateManager.h"

#include "Bullet.h"

Test_smallEnemy::Test_smallEnemy()
{
	enemy = std::make_shared<EnemyDetail>();
	manager = "Test_smallEnemy";

	//}Œ`‚ğ‘g‚İ‡‚í‚¹‚Ä‘Ì‚ğì‚é
	shared_ptr<Square> body = make_shared<Square>();
	enemy->Set_child(enemy, body);
	shared_ptr<Triangle> head = make_shared<Triangle>();
	enemy->Set_child(enemy, head);
	head->Set_local_vec({ 0, -0.79 }, { 0, 0, 0 }, { 1, 1 });
	shared_ptr<Triangle> wing1 = make_shared<Triangle>();
	enemy->Set_child(enemy, wing1);
	wing1->Set_local_vec({ -0.79, 0.5 }, { 0, 0, 30 }, { 1, 1 });
	shared_ptr<Triangle> wing2 = make_shared<Triangle>();
	enemy->Set_child(enemy, wing2);
	wing2->Set_local_vec({ 0.79, 0.5 }, { 0, 0, -30 }, { 1, 1 });

	//ˆê“I
	enemy->Test_Set_tr_rt_sc({ 500, 240 }, { 0, 0, -90 }, { 50, 50 });
}

bool Test_smallEnemy::HitJudge(shared_ptr<GameObject> target)
{
	return enemy->HitJudge(target);
}

void Test_smallEnemy::Update(vector<shared_ptr<GameObject>>* gameObjects)
{
	if (InputManager::getInstance()->input_key[KEY_INPUT_I]) {
		enemy->MoveY(-1 * FrameRateManager::getInstance()->Get_Deltatime() * 100);
	}
	if (InputManager::getInstance()->input_key[KEY_INPUT_J]) {
		enemy->MoveX(-1 * FrameRateManager::getInstance()->Get_Deltatime() * 100);
	}
	if (InputManager::getInstance()->input_key[KEY_INPUT_K]) {
		enemy->MoveY(FrameRateManager::getInstance()->Get_Deltatime() * 100);
	}
	if (InputManager::getInstance()->input_key[KEY_INPUT_L]) {
		enemy->MoveX(FrameRateManager::getInstance()->Get_Deltatime() * 100);
	}

	if (InputManager::getInstance()->input_keyDown[KEY_INPUT_H]) {
		shared_ptr<Bullet> bullet = make_shared<Bullet>();
		bullet->Set_manager(this->Get_manager());
		bullet->Set_dir(-1);
		bullet->Test_Set_tr_rt_sc(enemy->Get_Transform(), { 0, 0, 0 }, { 10, 10 });
		gameObjects->push_back(bullet);
	}

	enemy->Update(gameObjects);
}

void Test_smallEnemy::Show() const
{
	enemy->Show();
}