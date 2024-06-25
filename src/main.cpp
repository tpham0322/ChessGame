#include <iostream>
#include "board.h"

using namespace std;


void testPawnMove() {
    // Create a board with standard chess dimensions (8x8)
    board chessBoard(8, 8);

    // Initialize the board with pieces
    chessBoard.initializeBoard();

    // Move a white pawn forward one step to set up the invalid move test
    chessBoard.movePiece(1, 0, 2, 0);

    // Test moving the white pawn from (2, 0) to (4, 0)
    if (chessBoard.movePiece(2, 0, 4, 0)) {
        cout << "Moved white pawn from (2, 0) to (4, 0) - Invalid Move" << endl;
    } else {
        cout << "Failed to move white pawn from (2, 0) to (4, 0) - Correct Behavior" << endl;
    }
    chessBoard.printBoard();
}


int main() {
    testPawnMove();

    return 0;
}