#ifndef MOVEMENT_H
#define MOVEMENT_H 

#include "Board.h" 
#include "Player.h"

class Move {

private:

	Board*   board;
	Player* Currentplayer;

public:

	Move(); 
	Move			  (Board*);
	virtual ~Move     ();

	void Movement     (GT::Coord,GT::Coord, Player*, GT::Diagonal);
	bool Proc_Input   (const std::string&, const GT::CellState);
	 
};
#endif 