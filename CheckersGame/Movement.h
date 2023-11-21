#ifndef MOVEMENT_H
#define MOVEMENT_H 

#include "Board.h" 
#include "Player.h"


class Move {

	private:

		Board*   board;

	public:

		Move						(Board*);
		virtual ~Move				();

		void MovPlayer				(GT::Coord,GT::Coord, Player*, GT::Diagonal);
		bool Validate_Input			(GT::Coord , GT::Coord ); 

		bool Validate_Next			(GT::Coord, GT::Coord, const GT::Diagonal); 
		bool CheckPlayerPawn		(Player*, GT::Coord, GT::Coord); 	 
};
#endif 