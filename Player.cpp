#include "Player.h"

#include "Square.h"
#include "Triangle.h"

#include "InputManager.h"
#include "FrameRateManager.h"

Player::Player() {
	player = std::make_shared<PlayerDetail>();

	//}Œ`‚ğ‘g‚İ‡‚í‚¹‚Ä‘Ì‚ğì‚é
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

	//ˆê“I
	player->Test_Set_tr_rt_sc({ 100, 240 }, { 0, 0, 90 }, { 50, 50 });
}

bool Player::HitJudge(shared_ptr<GameObject> target)
{
	return player->HitJudge(target);
}

void Player::Summarize(vector<shared_ptr<GameObject>>* targets)
{
	player->Summarize(targets);
}

void Player::Update()
{
	if (InputManager::getInstance()->input_key[KEY_INPUT_W]) {
		player->MoveY(-1 * FrameRateManager::getInstance()->Get_Deltatime() * 100);
	}
	if (InputManager::getInstance()->input_key[KEY_INPUT_A]) {
		player->MoveX(-1 * FrameRateManager::getInstance()->Get_Deltatime() * 100);
	}
	if (InputManager::getInstance()->input_key[KEY_INPUT_S]) {
		player->MoveY(FrameRateManager::getInstance()->Get_Deltatime() * 100);
	}
	if (InputManager::getInstance()->input_key[KEY_INPUT_D]) {
		player->MoveX(FrameRateManager::getInstance()->Get_Deltatime() * 100);
	}

	player->Update();
}

void Player::Show() const
{
	player->Show();
}