#ifndef VISUALS_H
#define VISUALS_H

#include <iostream>
#include "GameConfig.h"



namespace VIS {

	// board stuff here 
	void top_board()
	{
		std::cout << "\n\n\t\t\tCheckers\t\t\t\t\t\n\n";
		for (int j = 0; j < GT::BoardSize; j++) std::cout << "     " << static_cast<char>(GT::CharIndx + j); // ascii
		std::cout << "\n___________________________________________________\n";
	}

	void mid_board(uint8_t ctr)
	{
		if (ctr % GT::BoardSize == 0) std::cout << ctr / GT::BoardSize << " ";
	}

	void bottom_board(uint8_t ctr)
	{
		if (ctr % GT::BoardSize == 0)  std::cout << "|\n  |_____|_____|_____|_____|_____|_____|_____|_____|\n";
	}

};

#endif 
