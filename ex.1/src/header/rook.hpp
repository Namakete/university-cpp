// Given the coordinates of the rook standing on the square of the
// chessboard (row number and column number). Write a loop (or loops)
// for displaying the coordinates of all cells under attack. Rook
// moves on any number of fields horizontally or vertically.

namespace chess {
    /*
     * example: 
     * 
     * DESK_SIZE = 5x5 
     * x = 2
     * y = 3
     *  
     *   1 2 3 4 5
     * 1 o x o o o  
     * 2 o x o o o  
     * 3 x x x x x
     * 4 o x o o o
     * 5 o x o o o
     *
     */

    void rook(int DESK_SIZE, int x = 0, int y = 0);
}
