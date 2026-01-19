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
	enemy->Set_Color(GetColor(255, 0, 0));
	enemy->Set_FillFlag(true);

	hp = 5;

	//}Œ`‚ğ‘g‚İ‡‚í‚¹‚Ä‘Ì‚ğì‚é
	shared_ptr<Triangle> body1 = make_shared<Triangle>();
	enemy->Set_child(enemy, body1);
	body1->Set_local_vec({ 0.3, 0 }, { 0, 0, 90 }, { 1, 1 });
	shared_ptr<Triangle> body2 = make_shared<Triangle>();
	enemy->Set_child(enemy, body2);
	body2->Set_local_vec({ -0.3, 0 }, { 0, 0, -90 }, { 1, 1 });

	//ˆê“I
	enemy->Test_Set_tr_rt_sc({ 700, 240 }, { 0, 0, 0 }, { 20, 20 });

	actionState = entry;
	actionTimer = 0;
}

bool Test_smallEnemy::HitJudge(shared_ptr<GameObject> target)
{
	return enemy->HitJudge(target);
}

void Test_smallEnemy::Update(vector<shared_ptr<GameObject>>* gameObjects)
{
	if (enemy->Get_Transform().x < -100) hp = 0;//

#if 0
	if (InputManager::getInstance()->input_keyDown[KEY_INPUT_RETURN]) {
		shared_ptr<Bullet> bullet = make_shared<Bullet>();
		bullet->Set_manager(this->Get_manager());
		bullet->Set_dir(-1);
		VECTOR_D pos = enemy->Get_Transform();
		pos.x = enemy->Get_leftEnd();
		bullet->Test_Set_tr_rt_sc(pos, { 0, 0, 0 }, { 10, 10 });
		gameObjects->push_back(bullet);
	}
#endif

	switch (actionState) {
	case entry:
		enemy->MoveX(-1 * FrameRateManager::getInstance()->Get_Deltatime() * 100);
		if (enemy->Get_Transform().x <= 500) {
			actionState = stop;
		}
		break;
	case stop:
		actionTimer += FrameRateManager::getInstance()->Get_Deltatime();
		if (actionTimer >= 1) {
			actionState = rush;
		}
		break;
	case rush:
		enemy->MoveX(-1 * FrameRateManager::getInstance()->Get_Deltatime() * 300);
		break;
	}

	enemy->Update(gameObjects);
}

void Test_smallEnemy::Show() const
{
	enemy->Show();
}