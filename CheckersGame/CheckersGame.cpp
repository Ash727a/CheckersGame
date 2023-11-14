#include <iostream>

#include "Board.h"
#include "Player.h"
#include "Movement.h"

int main(void)
{
	// some testing lol
	Board* b = new Board; 
	Player* idiot = new Player("Idiot1", GT::BPAWN); 
	Player* idiot2 = new Player("Idiot2", GT::WPAWN); 

	b->DrawBoard(); 

	Move move(b);

	move.Movement(2, 0, idiot, GT::Left); 
	move.Movement(5, 1, idiot2, GT::Left);

	b->DrawBoard();

	move.Movement(4, 0, idiot2, GT::Right);

	b->DrawBoard();

	move.Movement(3, 1, idiot2, GT::Right);

	b->DrawBoard();

	delete b; 
	delete idiot; 
	delete idiot2; 


}

