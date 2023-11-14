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

			if (side == GT::Right)
			{
				board->UpdateInput(y, x, GT::EMPTY);

				board->UpdateInput (
					(y - 1), (x + 1), CurrentPlayer->get_PawnColor()
				);
			}
			else
			{
				board->UpdateInput(y, x, GT::EMPTY);

				board->UpdateInput (
					(y - 1), (x - 1), CurrentPlayer->get_PawnColor()
				);
			}

		break;


		default: break; 


	}

	this->Currentplayer = nullptr; 

}