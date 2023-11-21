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


void Move::MovPlayer(GT::Coord y, GT::Coord x, Player* CurrentPlayer, GT::Diagonal side)
{
	GT::CellState currentColor = CurrentPlayer->get_PawnColor();

	board->UpdateInput(y, x, GT::EMPTY);

	GT::Coord targetY, targetX;

	switch (side)
	{
		case GT::Right		: targetY = (currentColor == GT::BPAWN) ? y + 1 : y - 1; targetX = (currentColor == GT::BPAWN) ? x - 1 : x + 1; break;
		case GT::Left		: targetY = (currentColor == GT::BPAWN) ? y + 1 : y - 1; targetX = (currentColor == GT::BPAWN) ? x + 1 : x - 1; break;
		case GT::BottomRight: targetY = (currentColor == GT::BPAWN) ? y - 1 : y + 1; targetX = (currentColor == GT::BPAWN) ? x - 1 : x + 1; break;
		case GT::BottomLeft : targetY = (currentColor == GT::BPAWN) ? y - 1 : y + 1; targetX = (currentColor == GT::BPAWN) ? x + 1 : x - 1; break;

		default: break;
	}

	if (board->get_CellState(targetY, targetX) == (currentColor == GT::BPAWN ? GT::WPAWN : GT::BPAWN))
	{
		CurrentPlayer->UpdatePlayerPawns();
		std::cout << "\n" << CurrentPlayer->get_name() << " Scored one!\n\n";
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

	GT::Coord targetY = 0, targetX = 0;

	switch (Side)
	{
		case GT::Right:        targetY = (pawnColor == GT::BPAWN) ? y + 1 : y - 1; targetX = (pawnColor == GT::BPAWN) ? x - 1 : x + 1; break;
		case GT::Left:         targetY = (pawnColor == GT::BPAWN) ? y + 1 : y - 1; targetX = (pawnColor == GT::BPAWN) ? x + 1 : x - 1; break;
		case GT::BottomLeft:   targetY = (pawnColor == GT::BPAWN) ? y - 1 : y + 1; targetX = (pawnColor == GT::BPAWN) ? x + 1 : x - 1; break;
		case GT::BottomRight:  targetY = (pawnColor == GT::BPAWN) ? y - 1 : y + 1; targetX = (pawnColor == GT::BPAWN) ? x - 1 : x + 1; break;
		default: break;
	}

	return Validate_Input(targetY, targetX) && board->get_CellState(targetY, targetX) != pawnColor; 
}
