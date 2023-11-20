#include <iostream>
#include "Game.h"


int main() 
{
	Game game; 

	while (game.get_programStat())
	{
		game.GameP(); 
	}
}