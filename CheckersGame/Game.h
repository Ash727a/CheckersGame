#ifndef GAME_H
#define GAME_H 

#include "Board.h"
#include "Player.h"
#include "Movement.h" 
#include "InputHandler.h"

class Game {

	private: 
		 
		bool    ProgramStat; 

		GT::GameName   gamename; 
		GT::GameStatus GameStat; 

		Player* currentPlayer;
		Player* Player1; 
		Player* Player2; 
		Board *  board; 

		Move  * Movement;

	public: 

		Game							(); 
		~Game							(); 
		void Menu						(); 
		void GameP						(); 
		bool get_programStat			(); 
		void LoadGameSettings			();
		void LoadLogMenu				();
		void Load_Game					(); 
		void swap_turns					(); 
		bool Validate_PlayerInput		(const GT::Inputs&, char, Player*);



};

#endif // !GAME_H



