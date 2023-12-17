#include "Movement.h"
#include "GameConfig.h"


Move::Move(Board* board)
{
	this->board = board;
}

Move::~Move()
{
	board = nullptr;
}

void Move::CoordinateCalculator(GT::Coord& y1, GT::Coord& x1, GT::Diagonal side, GT::CellState currentColor, GT::Coord y, GT::Coord x)
{
	switch (side)
	{
		case GT::Right:	      
			y1 = (currentColor == GT::BPAWN) ? y + 1 : y - 1; x1 = (currentColor == GT::BPAWN) ? x - 1 : x + 1; 
			break;
		case GT::Left:	      
			y1 = (currentColor == GT::BPAWN) ? y + 1 : y - 1; x1 = (currentColor == GT::BPAWN) ? x + 1 : x - 1; 
			break;
		case GT::BottomRight: 
			y1 = (currentColor == GT::BPAWN) ? y - 1 : y + 1; x1 = (currentColor == GT::BPAWN) ? x - 1 : x + 1; 
			break;
		case GT::BottomLeft:  
			y1 = (currentColor == GT::BPAWN) ? y - 1 : y + 1; x1 = (currentColor == GT::BPAWN) ? x + 1 : x - 1; 
			break;

		default: break;
	}
}

void Move::MovPlayer(GT::Coord y, GT::Coord x, Player* CurrentPlayer, GT::Diagonal side)
{
	GT::CellState currentColor = CurrentPlayer->get_PawnColor();

	board->UpdateInput(y, x, GT::EMPTY);

	GT::Coord targetY = 0, targetX = 0; 

	CoordinateCalculator(targetY, targetX, side, currentColor, y , x); 

	if (board->get_CellState(targetY, targetX) == (currentColor == GT::BPAWN ? GT::WPAWN : GT::BPAWN))
	{
		CurrentPlayer->UpdatePlayerPawns();
	}

	board->UpdateInput(targetY, targetX, currentColor);
}



bool Move::Validate_Input(GT::Coord y, GT::Coord x) // validates coordinates 
{
	return (x <= 7 && x >= 0) && (y <= 7 && y >= 0);
}


bool Move::CheckPlayerPawn(Player* currentPlayer, GT::Coord y, GT::Coord x) // validates if the selected coordinates match player stone
{
	return currentPlayer->get_PawnColor() == board->get_CellState(y, x);
}


bool Move::Validate_Next(GT::Coord y, GT::Coord x, const GT::Diagonal Side)
{
	GT::CellState pawnColor = board->get_CellState(y, x);

	GT::Coord targetY = 0; 
	GT::Coord targetX = 0;

	CoordinateCalculator(targetY, targetX, Side, pawnColor, y, x); 
	return Validate_Input(targetY, targetX) && board->get_CellState(targetY, targetX) != pawnColor;
}
