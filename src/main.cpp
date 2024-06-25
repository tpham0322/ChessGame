#include <iostream>
#include "board.h"

using namespace std;

int main() {
    // Create a board with standard chess dimensions (8x8)
    board chessBoard(8, 8);

    // Initialize the board with pieces
    chessBoard.initializeBoard();

    // Print the initial board
    cout << "Initial Board:" << endl;
    chessBoard.printBoard();

    // Move a piece (example: move a white pawn from (1, 0) to (2, 0))
    if (chessBoard.movePiece(1, 0, 2, 0)) {
        cout << "Moved pawn from (1, 0) to (2, 0):" << endl;
    } else {
        cout << "Failed to move pawn from (1, 0) to (2, 0):" << endl;
    }

    // Print the board after the move
    chessBoard.printBoard();

    return 0;
}