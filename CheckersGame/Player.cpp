#include "Player.h"

Player::Player(const GT::Player& Name, const GT::CellState PawnColor)
{
	this->Name = Name;
	this->PawnColor = PawnColor;
	this->Wins = 0;
	this->CapturedPawns = 0;
}

Player::~Player()
{

}

GT::Score Player::get_score() const
{
	return this->Wins;
}

GT::Player Player::get_name() const
{
	return this->Name;
}

GT::Score  Player::get_CapturedPawns() const
{
	return this->CapturedPawns;
}

GT::CellState Player::get_PawnColor() const
{
	return this->PawnColor;
}

void Player::UpdatePlayerState(GT::PlayerState isPlaying)
{
	this->isPlaying = isPlaying;
}

void Player::UpdatePlayerWins()
{
	this->Wins++;
}

void Player::UpdatePlayerPawns()
{
	this->CapturedPawns++;
}
