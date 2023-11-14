#include "Board.h"

#include "GameConfig.h"
#include "Visuals.h"
Board::Board()
{
    initialize_Board(); // sets default values in place 
}

Board::~Board()
{

}

// inits the cell states for the grid 
void Board::initialize_Board()
{
    for (int i = 1; i <= GT::BoardSize; i++)
    {
        for (int j = 1; j <= GT::BoardSize; j++)
        {
            if (i == GT::DeadSpace1 || i == GT::DeadSpace2) grid[{i - 1, j - 1}] = GT::EMPTY;

            else if (i % GT::BoardOffset == j % GT::BoardOffset) grid[{i - 1, j - 1}] = (i <= GT::SideLimit) ? GT::BPAWN : GT::WPAWN;

            else grid[{i - 1, j - 1}] = GT::EMPTY;
        }
    }
}


// update the board based on coordinates called from an arbritary class 
void Board::UpdateInput(GT::Coord y, GT::Coord x, enum GT::CellState Stone)
{
    this->grid[{y, x}] = Stone;
}

// outputs the board tc reduced from O(n^2) to O(n) tc
void Board::DrawBoard()
{
    VIS::top_board(); 

    uint8_t ctr = 0;

    for (auto i = grid.begin(); i != grid.end(); i++)
    {
        VIS::mid_board(ctr); 

        switch (i->second)
        {
            case GT::BPAWN: std::cout     << "|  "<<GT::bpawn<<"  "; break;
            case GT::WPAWN: std::cout     << "|  "<<GT::wpawn<< "  "; break;
            case GT::EMPTY: std::cout     << "|     "; break;
            default: break;
        }

        ctr++;
        VIS::bottom_board(ctr);
    }

}


GT::CellState Board::get_CellState(GT::Coord y, GT::Coord x) const
{
    GT::Pair pair = std::make_pair(y, x); 

    for (auto i = grid.begin(); i != grid.end(); i++) 
    {
        if (i->first == pair) return i->second; 
    }

    return GT::EMPTY; 
}