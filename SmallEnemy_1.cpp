#include "SmallEnemy_1.h"

#include "Triangle.h"

#include "FrameRateManager.h"

SmallEnemy_1::SmallEnemy_1()
{
	enemy = std::make_shared<EnemyDetail>();
	manager = "SmallEnemy_1";
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

bool SmallEnemy_1::HitJudge(shared_ptr<GameObject> target)
{
	return enemy->HitJudge(target);
}

void SmallEnemy_1::Update(vector<shared_ptr<GameObject>>* gameObjects)
{
	if (enemy->Get_Transform().x < -100) destroy = true;
	if (!explosion_animation.Explosion_Update()) destroy = true;
	if (explosion_animation.Get_Exploding()) return;

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

void SmallEnemy_1::Show() const
{
	enemy->Show();
	explosion_animation.Show(enemy->Get_Transform());
}