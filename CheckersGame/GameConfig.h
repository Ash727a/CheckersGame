#ifndef GAMECONFIG_H 
#define GAMECONFIG_H

#include <iostream>
#include <map>
#include <set>
#include <list>

namespace GT
{
	// Cell states 
	enum CellState { EMPTY, BPAWN, WPAWN };
	enum Error     {INVALIDMOVE , BADINPUT};


	// Game typedefs 
	typedef uint8_t                                               Score;
	typedef std::string                                           Player;
	typedef int                                                   Coord;
	typedef std::map<std::pair<Coord, Coord>, GT::CellState>      Grid;
	typedef bool                                                  PlayerState;
	typedef char                                                  Diagonal; 
	typedef std::pair<Coord, Coord>                               Pair; 
	typedef char                                                  Character; 
	typedef std::string											  Inputs; 
	typedef std::set<std::pair<char, char>>						  InputHolder;
	typedef bool												  Check; 
 

	// Board configurations would not suggest touching these lol 
	const uint8_t   BoardSize    = 0x8;
	const uint8_t   CharIndx     = 0x41;
	const uint8_t   BoardOffset  = 0x2;
	const uint8_t   DeadSpace1   = 0x4;
	const uint8_t   DeadSpace2   = 0x5;
	const uint8_t   SideLimit    = 0x3;
	const Character bpawn	     = 0x4f;
	const Character wpawn        = 0x58;

	// movement offsets
	const uint8_t   yOffset      = 0x41; 
	const uint8_t   xOffset      = 0x30;
	const Diagonal  Left         = 0x4c; 
	const Diagonal  Right        = 0x52;


};

#endif 
