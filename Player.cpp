#include "Player.h"

Player::Player() {
	player = std::make_shared<PlayerDetail>();
	player->Initialization(player);
}

Player::~Player()
{

}

void Player::Update()
{
	player->Update();
}

void Player::Show() const
{
	player->Show();
}