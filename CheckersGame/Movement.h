#ifndef MOVEMENT_H
#define MOVEMENT_H 

#include "Board.h" 
#include "Player.h"

class Move {

private:

	Board*   board;
	Player* Currentplayer;

public:

	Move			(Board*);
	virtual ~Move   ();

	void Movement   (GT::Coord,GT::Coord, Player*, GT::Diagonal);
	 
};
#endif 