// Given the coordinates of the bishop standing on the square of 
// the chessboard (row number and column number). Write a loop (or loops) 
// for displaying the coordinates of all cells under attack. Bishop 
// moves to any number of squares diagonally.

#include "../header/include.hpp"

namespace chess {
    /*
     * example: 
     * 
     * DESK_SIZE = 5x5 
     * x = 2
     * y = 3
     *  
     *   1 2 3 4 5
     * 1 o o o x o  
     * 2 x o x o o  
     * 3 o x o o o
     * 4 x o x o o
     * 5 o o o x o
     *
     */

    void bishop(int DESK_SIZE, int x = 0, int y = 0);
}
