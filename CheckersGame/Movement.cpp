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

Move::Move() {}; 

// logic functions to be added just a test

void Move::Movement(GT::Coord y, GT::Coord x, Player* CurrentPlayer, GT::Diagonal side)
{
	this->Currentplayer = CurrentPlayer; 

	switch (CurrentPlayer->get_PawnColor())
	{
		case GT::BPAWN: 

				board->UpdateInput(y, x, GT::EMPTY);

				if (side == GT::Right) 
				{
					if(board)

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

	this->Currentplayer = nullptr; 

}



bool Move::Proc_Input(const std::string& input, const GT::CellState Pawn)
{
	int y = static_cast<GT::Coord>(input[0] - GT::yOffset); 
	int x = static_cast<GT::Coord>(input[1] - GT::xOffset); 


	std::cout << y <<" "<< x << std::endl;
	return (x && y <= 7 && x && y >= 0) && !(board->get_CellState(y , x) == Pawn); 
}