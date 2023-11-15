#include <iostream>

#include "Movement.h"
#include "Board.h"



int main(void)
{
	Board* board = new Board; 

	Move m(board); 

	board->DrawBoard(); // some testing of game logic its a mess it will be revamped 

	if (m.Validate_Input("A2") && m.Validate_Next("A2", GT::Right)) std::cout << "Good!\n";
	else std::cout << "bad"; 

	if (m.Validate_Input("D5") && m.Validate_Next("D5", GT::Right)) std::cout << "Good!\n";
	else std::cout << "bad";
	//else std::cout << "Bad!\n"; 

}

