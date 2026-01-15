#include "Player.h"

Player::Player() {
	player = std::make_shared<PlayerDetail>();
	player->Initialization(player);
}

Player::~Player()
{

}

bool Player::HitJudge(shared_ptr<GameObject> target)
{
	return player->HitJudge(target);
}

void Player::Update()
{
	player->Update();
}

void Player::Show() const
{
	player->Show();
}