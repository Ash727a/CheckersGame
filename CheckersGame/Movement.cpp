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

	switch (CurrentPlayer->get_PawnColor())
	{
		case GT::BPAWN: 

				board->UpdateInput(y, x, GT::EMPTY);

				if (side == GT::Right) 
				{
					if (board->get_CellState((y + 1), (x - 1)) == GT::WPAWN) 
					{ 
						CurrentPlayer->UpdatePlayerPawns(); 
						std::cout<<"\n"<< CurrentPlayer->get_name() << "Scored one!\n\n"; 
					}

					board->UpdateInput (
						(y + 1), (x - 1), CurrentPlayer->get_PawnColor()  // instead of nesting have game logic replace this part 
					); 
				}
				else if(side == GT::Left)
				{
					if (board->get_CellState((y + 1), (x + 1)) == GT::WPAWN)
					{ 
						CurrentPlayer->UpdatePlayerPawns(); 
						std::cout << "\n" << CurrentPlayer->get_name() << "Scored one!\n\n"; 
					}

					board->UpdateInput (
						(y + 1), (x + 1), CurrentPlayer->get_PawnColor() 
					);
				}
				else if (side == GT::BottomLeft)
				{
					if (board->get_CellState((y - 1), (x + 1)) == GT::WPAWN)
					{
						CurrentPlayer->UpdatePlayerPawns();
						std::cout << "\n" << CurrentPlayer->get_name() << "Scored one!\n\n";
					}

					board->UpdateInput(
						(y - 1), (x + 1), CurrentPlayer->get_PawnColor()
					);
				}
				else if (side == GT::BottomRight)
				{
					if (board->get_CellState((y - 1), (x - 1)) == GT::WPAWN)
					{
						CurrentPlayer->UpdatePlayerPawns();
						std::cout << "\n" << CurrentPlayer->get_name() << "Scored one!\n\n";
					}

					board->UpdateInput(
						(y - 1), (x - 1), CurrentPlayer->get_PawnColor()
					);
				}

		break; 

		case GT::WPAWN:

			board->UpdateInput(y, x, GT::EMPTY);

			if (side == GT::Right)
			{

				if (board->get_CellState((y - 1), (x + 1)) == GT::BPAWN) 
				{ 
					CurrentPlayer->UpdatePlayerPawns();
					std::cout << "\n" << CurrentPlayer->get_name() << "Scored one!\n\n";
				}

				board->UpdateInput (
					(y - 1), (x + 1), CurrentPlayer->get_PawnColor()
				);
			}
			else if(side == GT::Left)
			{
				if (board->get_CellState((y - 1), (x - 1)) == GT::BPAWN)
				{ 
					CurrentPlayer->UpdatePlayerPawns(); 
					std::cout << "\n" << CurrentPlayer->get_name() << "Scored one!\n\n"; 
				}
				board->UpdateInput (
					(y - 1), (x - 1), CurrentPlayer->get_PawnColor()
				);
			}
			else if (side == GT::BottomLeft)
			{
				if (board->get_CellState((y + 1), (x - 1)) == GT::BPAWN)
				{
					CurrentPlayer->UpdatePlayerPawns();
					std::cout << "\n" << CurrentPlayer->get_name() << "Scored one!\n\n";
				}

				board->UpdateInput(
					(y + 1), (x - 1), CurrentPlayer->get_PawnColor()
				);
			}
			else if (side == GT::BottomRight)
			{
				if (board->get_CellState((y + 1), (x + 1)) == GT::BPAWN)
				{
					CurrentPlayer->UpdatePlayerPawns();
					std::cout << "\n" << CurrentPlayer->get_name() << "Scored one!\n\n";
				}

				board->UpdateInput(
					(y + 1), (x + 1), CurrentPlayer->get_PawnColor()  
				);
			}

		break;


		default: break; 


	}

}

bool Move::Validate_Input(GT::Coord y, GT::Coord x) // validates coordinates 
{
	return (x <= 7 && x >= 0) && (y <= 7 && y >= 0);
}


bool Move::CheckPlayerPawn(Player* currentPlayer, GT::Coord y, GT::Coord x) // validates if the selected coordinates match player stone
{
	return currentPlayer->get_PawnColor() == board->get_CellState(y, x); 
}

bool Move::Validate_Next(GT::Coord y,GT::Coord x, const GT::Diagonal Side) // logic to validate the movements 
{
	switch (board->get_CellState(y,x)) 
	{
		case GT::BPAWN:

			
			if (board->get_CellState((y + 1), (x - 1)) != GT::BPAWN && Side == GT::Right && (y + 1) <= 7 && (x - 1) >= 0)
			{
				return true; 
			}
			else if(board->get_CellState((y + 1), (x + 1)) != GT::BPAWN && Side == GT::Left && (y + 1) <= 7 && (x + 1) <= 7)
			{
				return true; 
			}
			else if (board->get_CellState((y - 1), (x + 1)) != GT::BPAWN && Side == GT::BottomLeft && (y - 1) >= 0 && (x + 1) <= 7)
			{
				return true;
			}
			else if (board->get_CellState((y - 1), (x - 1)) != GT::BPAWN && Side == GT::BottomRight && (y - 1) >= 0 && (x - 1) >= 0)
			{
				return true;
			}

		break;

		case GT::WPAWN:

			if (board->get_CellState((y - 1), (x + 1)) != GT::WPAWN && Side == GT::Right && (y - 1) >= 0 && (x + 1) <= 7)
			{
				return true;
			}
			else if (board->get_CellState((y - 1), (x - 1)) != GT::WPAWN && Side == GT::Left && (y - 1) >= 0 && (x - 1) >= 0)
			{
				return true;
			}
			else if (board->get_CellState((y + 1), (x - 1)) != GT::WPAWN && Side == GT::BottomLeft && (y + 1) <= 7 && (x - 1) >= 0)
			{
				return true;
			}
			else if (board->get_CellState((y + 1), (x + 1)) != GT::WPAWN && Side == GT::BottomRight && (y + 1) <= 7 && (x + 1) <= 7)
			{
				return true;
			}

			break;

		default: break;

	}
	return false; 
}
