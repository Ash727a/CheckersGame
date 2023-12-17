#ifndef GAMECONFIG_H 
#define GAMECONFIG_H

#include <iostream>
#include <map>
#include <set>
#include <list>


#define kill delete 

namespace GT
{


	// Cell states 
	enum CellState { EMPTY, BPAWN, WPAWN };
	enum Error     {INVALIDMOVE , BADINPUT, FILERRR,NOTFOUND};


	// Game typedefs 
	typedef uint8_t                                               Score;
	typedef std::string                                           Player;
	typedef int                                                   Coord;
	typedef std::map<std::pair<Coord, Coord>, GT::CellState>      Grid; // associative array 
	typedef bool                                                  PlayerState;
	typedef char                                                  Diagonal; 
	typedef std::pair<Coord, Coord>                               Pair; 
	typedef char                                                  Character; 
	typedef std::string											  Inputs; 
	typedef std::set<std::pair<char, char>>						  InputHolder; // can be replaced with  avl 
	typedef bool												  Check; 
	typedef int													  Pawnss; 
	typedef std::string											  GameName; 
	typedef bool                                                  GameStatus;
                                       

	
	struct GameInput {

		GT::Inputs   PawnLocation;
		GT::Diagonal Diag;
		GT::Player   Currentplayer;

	};

	typedef std::list<GameInput>								  GameInputs; 
	typedef std::string											  Filename; 
 

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
	const Diagonal  BottomRight  = 0x4B; 
	const Diagonal  BottomLeft   = 0x42;
	const Score     totalScore   = 0x0C; 


	const Filename GameLog   = "GameLogs";
	const Filename ScoreLog  = "ScoreLogs"; 
	const Filename GameNames = "GameNameLog"; 


};

#endif 
