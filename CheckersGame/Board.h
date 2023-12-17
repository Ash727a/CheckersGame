#ifndef BOARD_H
#define BOARD_H 

#include <map>
#include <iostream> 

#include "GameConfig.h"



class Board {

    private:

        GT::Grid grid;

    public:

        Board                        ();
        virtual ~Board               ();

        void initialize_Board        ();
        void UpdateInput             (GT::Coord, GT::Coord, enum GT::CellState);
        void DrawBoard               ();
        GT::CellState get_CellState  (GT::Coord , GT::Coord ) const; 
        void top_board               (); 
        void mid_board               (uint8_t ctr);
        void bottom_board            (uint8_t ctr);

};
#endif

