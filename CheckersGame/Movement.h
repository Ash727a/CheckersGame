#ifndef MOVEMENT_H
#define MOVEMENT_H 

#include "Board.h" 
#include "Player.h"


class Move {

private:

	Board*   board;
	Player* Currentplayer;

public:

	Move						(); 
	Move						(Board*);
	virtual ~Move				();

	void MovPlayer				(const std::string& input, Player*, GT::Diagonal);
	bool Validate_Input			(const std::string&);
	bool Validate_Next			(const std::string&, const GT::Diagonal);
	 
};
#endif 