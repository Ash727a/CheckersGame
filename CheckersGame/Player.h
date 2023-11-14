#ifndef PLAYER_H
#define PLAYER_H

#include "GameConfig.h"

class Players {
	private:

		GT::Player       Name;
		GT::Score        Wins;
		GT::Score		 CapturedPawns;
		GT::PlayerState  isPlaying;
		GT::CellState    PawnColor;

	public:

		Players(const GT::Player&, const GT::CellState);
		virtual ~Players();

		GT::Score     get_score			() const;
		GT::Score     get_CapturedPawns () const;
		GT::Player    get_name			() const;
		GT::CellState get_PawnColor		() const;

		void UpdatePlayerState			(GT::PlayerState);
		void UpdatePlayerWins			();
		void UpdatePlayerPawns			(GT::Score);
};

#endif