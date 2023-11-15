#include "Movement.h"
#include "GameConfig.h"




Move::Move(Board* board)
{
	this->board         = board;
	this->Currentplayer = nullptr; 
}

Move::~Move()
{
	board         = nullptr; 
	Currentplayer = nullptr; 
}

Move::Move() 
{

}; 

// logic functions to be added just a test

void Move::MovPlayer(const std::string& input, Player* CurrentPlayer, GT::Diagonal side)
{ 
	int x = static_cast<GT::Coord>(input[0] - GT::yOffset);
	int y = static_cast<GT::Coord>(input[1] - GT::xOffset);

	switch (CurrentPlayer->get_PawnColor())
	{
		case GT::BPAWN: 

				board->UpdateInput(y, x, GT::EMPTY);

				if (side == GT::Right) 
				{
				
					board->UpdateInput (
						(y + 1), (x - 1), CurrentPlayer->get_PawnColor() 
					); 
				}
				else
				{
					board->UpdateInput (
						(y + 1), (x + 1), CurrentPlayer->get_PawnColor() 
					);
				}

		break; 

		case GT::WPAWN:

			board->UpdateInput(y, x, GT::EMPTY);

			if (side == GT::Right)
			{
				board->UpdateInput (
					(y - 1), (x + 1), CurrentPlayer->get_PawnColor()
				);
			}
			else
			{
			
				board->UpdateInput (
					(y - 1), (x - 1), CurrentPlayer->get_PawnColor()
				);
			}

		break;


		default: break; 


	}


}


bool Move::Validate_Input(const std::string& input)
{
	int x = static_cast<GT::Coord>(input[0] - GT::yOffset); 
	int y = static_cast<GT::Coord>(input[1] - GT::xOffset); 

	std::cout << x << " " << y << " "; 
	return ((x && y <= 7) && (x && y >= 0));
}

bool Move::Validate_Next(const std::string& input, const GT::Diagonal Side)
{
	int x = static_cast<GT::Coord>(input[0] - GT::yOffset);
	int y = static_cast<GT::Coord>(input[1] - GT::xOffset);

	switch (board->get_CellState(y,x)) 
	{
		case GT::BPAWN:


			if (board->get_CellState((y + 1), (x - 1)) != GT::BPAWN && Side == GT::Right)
			{
				return true; 
			}
			else if(board->get_CellState((y + 1), (x + 1)) != GT::BPAWN && Side == GT::Left)
			{
				return true; 
			}

		break;

		case GT::WPAWN:

			if (board->get_CellState((y - 1), (x + 1)) != GT::WPAWN && Side == GT::Right)
			{
				return true;
			}
			else if (board->get_CellState((y - 1), (x - 1)) != GT::WPAWN && Side == GT::Left)
			{
				return true;
			}

			break;


		default: break;


	}
	return false; 
}