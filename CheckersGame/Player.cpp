#include "Player.h"

Players::Players(const GT::Player& Name, const GT::CellState PawnColor)
{
	this->Name = Name;
	this->PawnColor = PawnColor;
	this->Wins = 0;
	this->CapturedPawns = 0;
}

Players::~Players()
{

}

GT::Score Players::get_score() const
{
	return this->Wins;
}

GT::Player Players::get_name() const
{
	return this->Name;
}

GT::Score  Players::get_CapturedPawns() const
{
	return this->CapturedPawns;
}

GT::CellState Players::get_PawnColor() const
{
	return this->PawnColor;
}

void Players::UpdatePlayerState(GT::PlayerState isPlaying)
{
	this->isPlaying = isPlaying;
}

void Players::UpdatePlayerWins()
{
	this->Wins++;
}

void Players::UpdatePlayerPawns(GT::Score CapturedPawns)
{
	this->CapturedPawns = CapturedPawns;
}
