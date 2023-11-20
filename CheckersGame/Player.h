#ifndef PLAYER_H
#define PLAYER_H

#include "GameConfig.h"
#include "Board.h"
#include <set>

class Player {
	private:

		GT::Player       Name;
		GT::Score        Wins;
		GT::Score		 CapturedPawns;
		GT::PlayerState  isPlaying;
		GT::CellState    PawnColor;
		GT::InputHolder  PossibleInputs; 

	public:

		Player (); 
		Player(const GT::Player&, const GT::CellState);
		virtual ~Player();

		GT::Score     get_score			() const;
		GT::Score     get_CapturedPawns () const;
		GT::Player    get_name			() const;
		GT::CellState get_PawnColor		() const;
		GT::Pawnss    Remaining_Pawns   () const;

		void UpdatePlayerState			(GT::PlayerState);
		void UpdatePlayerWins			();
		void UpdatePlayerPawns			();
		void UpdateInputs				(Board*); 
		void Display_PossibleInputs     (); 
		
};

#endif