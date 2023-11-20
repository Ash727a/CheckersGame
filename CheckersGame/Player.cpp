#include "Player.h"

Player::Player()
{

}

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

// get methods 
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

// set methods

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

/*
* 
* 	this->x = static_cast<GT::Coord>(input[0] - GT::yOffset); // reverse this 
	this->y = static_cast<GT::Coord>(input[1] - GT::xOffset);
*/

void Player::UpdateInputs(Board* board) // updates all possible inputs 
{
	PossibleInputs.clear(); 

	std::string tmp = "  ";

	for (int i = 0; i < GT::BoardSize; i++)
	{
		for (int j = 0; j < GT::BoardSize; j++)
		{
			if (board->get_CellState(j, i) == PawnColor)
			{
				PossibleInputs.insert(std::make_pair(static_cast<char>(i + GT::yOffset), static_cast<char>(j + GT::xOffset)));
			}
		}
	}

}

void Player::Display_PossibleInputs()
{
	for (const auto& i : PossibleInputs)
	{
		std::cout << "(" << i.first << i.second << ") ";
	}
}

GT::Pawnss Player::Remaining_Pawns() const
{
	return this->PossibleInputs.size(); 
}

