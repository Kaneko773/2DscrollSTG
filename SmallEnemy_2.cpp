#include "SmallEnemy_2.h"

#include "Square.h"
#include "Triangle.h"

#include "FrameRateManager.h"

#include "Bullet.h"

#include <cmath>

#define PI 3.14159265358979323846

SmallEnemy_2::SmallEnemy_2()
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

	posY = 480.0f / 6.0f;
	posY *= (GetRand(4) + 1);

	temp = 0;
	stop = false;
	ActionTime = 1.0 / 180;

	//ˆê“I
	enemy->Test_Set_tr_rt_sc({ 700, posY }, { 0, 0, 0 }, { 20, 20 });

	actionTimer = 0;
}

bool SmallEnemy_2::HitJudge(shared_ptr<GameObject> target)
{
	return enemy->HitJudge(target);
}

void SmallEnemy_2::Update(vector<shared_ptr<GameObject>>* gameObjects)
{
	if (enemy->Get_Transform().x < -100) destroy = true;
	if (!explosion_animation.Explosion_Update()) destroy = true;
	if (explosion_animation.Get_Exploding()) return;

	if(!stop)enemy->MoveX(-1 * FrameRateManager::getInstance()->Get_Deltatime() * 100);
	if (actionTimer >= ActionTime) {
		actionTimer = 0;
		stop = false;
		if (GetRand(799) == 0) {
			stop = true;
			ActionTime = 1;
			shared_ptr<Bullet> bullet = make_shared<Bullet>();
			bullet->Set_manager(this->Get_manager());
			bullet->Set_dir(-2);
			VECTOR_D pos = enemy->Get_Transform();
			pos.x = enemy->Get_leftEnd();
			bullet->Test_Set_tr_rt_sc(pos, { 0, 0, 0 }, { 10, 10 });
			gameObjects->push_back(bullet);
		}
		else {
			ActionTime = 1.0 / 180;
			double moveY = posY + sin(temp * PI / 180.0) * 50;
			enemy->Set_Transform_y(moveY);
			++temp;
			if (temp >= 360) temp = 0;
		}
	}
	actionTimer += FrameRateManager::getInstance()->Get_Deltatime();

	enemy->Update(gameObjects);
}

void SmallEnemy_2::Show() const
{
	enemy->Show();
	explosion_animation.Show(enemy->Get_Transform());
}