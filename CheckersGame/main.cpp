#include <iostream>
#include "Game.h"

#include "Logs.h" 


/*

*/
int main() 
{
	Game game;

	while (game.get_programStat())
	{
		game.GameP();
	}
}