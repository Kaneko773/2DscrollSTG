#include "Player.h"

#include "Square.h"
#include "Triangle.h"

#include "InputManager.h"
#include "FrameRateManager.h"

#include "Bullet.h"

#define SCREEN_HEIGHT 480

Player::Player() {
	player = std::make_shared<PlayerDetail>();
	manager = "Player";
	player->Set_Color(GetColor(0, 0, 255));
	player->Set_FillFlag(true);

	hp = 5;

	//図形を組み合わせて体を作る
	shared_ptr<Square> body = make_shared<Square>();
	player->Set_child(player, body);
	shared_ptr<Triangle> head = make_shared<Triangle>();
	player->Set_child(player, head);
	head->Set_local_vec({ 0, -0.79 }, { 0, 0, 0 }, { 1, 1 });
	shared_ptr<Triangle> wing1 = make_shared<Triangle>();
	player->Set_child(player, wing1);
	wing1->Set_local_vec({ -0.79, 0.5 }, { 0, 0, 30 }, { 1, 1 });
	shared_ptr<Triangle> wing2 = make_shared<Triangle>();
	player->Set_child(player, wing2);
	wing2->Set_local_vec({ 0.79, 0.5 }, { 0, 0, -30 }, { 1, 1 });

	//一時的
	player->Test_Set_tr_rt_sc({ 100, SCREEN_HEIGHT / 2 }, { 0, 0, 90 }, { 20, 30 });

	invincibleTimer = 0;
	invincible = false;
	prevBlinkingTime = invincibleTimer;
	hide = false;
}

bool Player::HitJudge(shared_ptr<GameObject> target)
{
	return player->HitJudge(target);
}

void Player::Summarize(vector<shared_ptr<GameObject>>* targets)
{
	player->Summarize(targets);
}

void Player::Update(vector<shared_ptr<GameObject>>* gameObjects)
{
	if (!explosion_animation.Explosion_Update()) destroy = true;
	if (InputManager::getInstance()->input_keyDown[KEY_INPUT_RETURN]) Get_Damage();//デバッグ
	if (explosion_animation.Get_Exploding()) return;

	if (InputManager::getInstance()->input_key[KEY_INPUT_W]) {
		player->MoveY(-1 * FrameRateManager::getInstance()->Get_Deltatime() * 100);
	}
	if (InputManager::getInstance()->input_key[KEY_INPUT_S]) {
		player->MoveY(FrameRateManager::getInstance()->Get_Deltatime() * 100);
	}

	player->Update(gameObjects);

	if (InputManager::getInstance()->input_keyDown[KEY_INPUT_F]) {
		shared_ptr<Bullet> bullet = make_shared<Bullet>();
		bullet->Set_manager(this->Get_manager());
		bullet->Set_dir(1);
		VECTOR_D pos = player->Get_Transform();
		pos.x = player->Get_rightEnd();
		bullet->Test_Set_tr_rt_sc( pos, {0, 0, 0}, {10, 10});
		gameObjects->push_back(bullet);
	}

	//画面外に出ないようにする
	if (player->Get_upperLimit() < 0) {
		player->Shift_transform_y(0 - player->Get_upperLimit());
	}
	if (player->Get_lowerLimit() > SCREEN_HEIGHT) {
		player->Shift_transform_y(SCREEN_HEIGHT - player->Get_lowerLimit());
	}
	player->Update(gameObjects);//DrawPointだけで良いかも

	//無敵時間更新
	if (invincible) {
		invincibleTimer += FrameRateManager::getInstance()->Get_Deltatime();
		//点滅
		if (invincibleTimer >= prevBlinkingTime + 0.05) {
			hide = !hide;
			prevBlinkingTime = invincibleTimer;
		}
		if (invincibleTimer >= InvincibleTime) {
			invincible = false;
			hide = false;
		}
	}
}

void Player::Show() const
{
	if (hide)return;//無敵時間中(点滅)
	player->Show();
	explosion_animation.Show(player->Get_Transform());
}