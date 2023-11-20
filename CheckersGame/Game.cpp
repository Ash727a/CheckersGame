#include "Game.h"



Game::Game()
{
	ProgramStat = true;
}

Game::~Game()
{

}

void Game::Menu()
{
	char tmp; 

	std::cout <<
		"\twelcome to the Game of Checkers!\n\n"
		<< "-----------------------------------------------\n"; 

	do
	{
			std::cout
			<< "| a) Play Checkers         \n"
			<< "| b) Game Logs & Replays   \n"
			<< "| c) Exit                  \n";

		std::cout << "\nSelect from (a - c) \n";

		std::cin >> tmp; 
	} 
	while (tmp != 'a' && tmp != 'b' && tmp != 'c'); 

	switch (tmp)
	{
		case 'a': 
			break; 

		case 'b':
			break;

		case 'c':

			this->ProgramStat = false; 
			
			break;

		default:

			break;
	}

}

bool Game::get_programStat()
{
	return this->ProgramStat; 
}

void Game::GameP()
{
	Menu(); 
	LoadGameSettings(); 
}

void Game::LoadLogMenu()
{
	std::cout << "h"; 
}

void Game::LoadGameSettings()
{
	std::string input; 
	char        input2;

	std::cout 

		<< "\n\n Enter the Name for this  Game \n"
		<< ":> "; 

	std::cin >> input; 
	this->gamename = input; 

	std::cout << "\n Game Name: " << input << "\n"; 

	std::cout << "Player 1 will play as a Black Pawn and Player 2 will Play as a White Pawn \n"; 

	std::cout
	<< "\nEnter Player 1's Name: \n"
	<< ":> ";

	std::cin >> input; 
	this->Player1 = new Player(input, GT::BPAWN); 

	std::cout
		<< "\nEnter Player 2's Name: \n"
		<< ":> ";

	std::cin >> input; 
	this->Player2 = new Player(input, GT::WPAWN);

	std::cout
		<<"\n Player 1: "<<Player1->get_name()<<" is playing as Black Pawn"
		<<"\n Player 2: "<<Player2->get_name()<<"  is playing as White Pawn\n";

	do
	{
		std::cout << "\nPress (y) to continue or press (n) to back out \n"; 
		std::cin >> input2; 
	} 
	while (input2 != 'y' && input2 != 'n'); 

	switch (input2)
	{
		case 'y':

			Load_Game(); 

		break;

		case 'n':

			std::cout << "Reverting back to menu\n";

			delete this->Player1; 
			delete this->Player2; 
			this->gamename = " ";

			Menu(); 

		break;

		default:
		break;
	}

}

void Game::Load_Game()
{
	this->board = new Board; 
	this->GameStat = true; 
	this->Movement = new Move(board); 

	board->DrawBoard(); 

	this->currentPlayer = Player1; 

	std::cout << "For Inputs Reffer to the Characters A - H on the X axis & 0 - 7 for Y axis\n For character Input use 'R' for right movement and 'L for left movement K for bottom right and B for bottom left \n if you wish to surrender just press S r";

	for (;;)
	{

		std::string Player_Input; 
		char        side; 

		if (!GameStat)
		{
			break; 
		}

		std::cout << "Player " << currentPlayer->get_name() << " Make your Move!\n"; 

		currentPlayer->UpdateInputs(this->board); 

		if (currentPlayer->Remaining_Pawns() == 0) 
		{
			GameStat = false; 
			break; 
		}
		
		do
		{

			std::cout << "Possible Inputs: \n"; currentPlayer->Display_PossibleInputs(); std::cout << " \n";
			std::cin >> Player_Input; std::cin >> side;

			if (Player_Input == "S")
			{
				GameStat = false; 
				break; 
			}

		} while (!Validate_PlayerInput(Player_Input, side, this->currentPlayer));

		board->DrawBoard();
		swap_turns();
		
	}
}

void Game::swap_turns()
{
	if (this->currentPlayer == Player1)
	{
		this->currentPlayer = Player2; 
	}
	else
	{
		this->currentPlayer = Player1; 
	}
}

bool Game::Validate_PlayerInput(const GT::Inputs& input, char side, Player* player)
{
	InputHandler* IH = new InputHandler; 

	IH->ParseInputs(input); 
		if
		(
			Movement->Validate_Input (IH->get_y(), IH->get_x())          &&
			Movement->CheckPlayerPawn(player, IH->get_y(), IH->get_x())  &&
			Movement->Validate_Next  (IH->get_y(), IH->get_x(), side)
		)
		{
			Movement->MovPlayer(IH->get_y(), IH->get_x(), player, side);
			return true; 
		}
		else
		{
			std::cout << "Please re-enter your input bad input detected \n";
			return false;
		}
}


