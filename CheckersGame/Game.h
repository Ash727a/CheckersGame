#ifndef GAME_H
#define GAME_H 

#include "Board.h"
#include "Player.h"
#include "Movement.h" 
#include "InputHandler.h"
#include "Logs.h"

class Game {

	private: 
		 
		bool    ProgramStat; 

		GT::GameName   gamename; 
		GT::GameStatus GameStat; 

		Player* currentPlayer;
		Player* Player1; 
		Player* Player2; 
		Board*  board; 
		Move*  Movement;
		Logs   Logger; 

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
		void Show_Winners				(); 
		void Destroy_All				(); 
		void load_logs                  (); 



};

#endif // !GAME_H



