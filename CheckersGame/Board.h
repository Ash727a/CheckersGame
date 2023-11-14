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

};
#endif

