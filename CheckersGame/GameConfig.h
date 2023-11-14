#ifndef GAMECONFIG_H 
#define GAMECONFIG_H

#include <iostream>
#include <map>

namespace GT
{
	// Cell states 
	enum CellState { BPAWN, WPAWN, EMPTY };
	enum Error     {INVALIDMOVE , BADINPUT};


	// Game typedefs  
	typedef uint8_t                                               Score;
	typedef std::string                                           Player;
	typedef uint8_t                                               Coord;
	typedef std::map<std::pair<Coord, Coord>, GT::CellState>      Grid;
	typedef bool                                                  PlayerState;
	typedef char                                                  Diagonal; 


	// Board configurations would not suggest touching these lol 
	const uint8_t  BoardSize   = 0x8;
	const uint8_t  CharIndx    = 0x41;
	const uint8_t  BoardOffset = 0x2;
	const uint8_t  DeadSpace1  = 0x4;
	const uint8_t  DeadSpace2  = 0x5;
	const uint8_t  SideLimit   = 0x3;

	const Diagonal Left  = 'L'; 
	const Diagonal Right = 'R';

};

#endif 
