#include "board.h"

board::board(int rows, int cols)
    : rows(rows), cols(cols) {
    grid.resize(rows, vector<shared_ptr<chessPiece>>(cols, nullptr));
}

board::~board() {
    clearBoard();
}

void board::initializeBoard() {
    // Initialize the board with the initial positions of the chess pieces
    for (int i = 0; i < cols; ++i) {
        grid[1][i] = make_shared<pawn>("White", 1, i);
        grid[6][i] = make_shared<pawn>("Black", 6, i);
    }
    
    grid[0][4] = make_shared<king>("White", 0, 4);
    grid[7][3] = make_shared<king>("Black", 7, 5);

    grid[0][3] = make_shared<queen>("White", 0, 3);
    grid[7][4] = make_shared<queen>("Black", 7, 3);

    grid[0][1] = make_shared<knight>("White", 0, 1);
    grid[0][6] = make_shared<knight>("White", 0, 6);
    grid[7][1] = make_shared<knight>("Black", 7, 1);
    grid[7][6] = make_shared<knight>("Black", 7, 6);

    grid[0][0] = make_shared<rook>("White", 0, 0);
    grid[0][7] = make_shared<rook>("White", 0, 7);
    grid[7][0] = make_shared<rook>("Black", 7, 0);
    grid[7][7] = make_shared<rook>("Black", 7, 7);


}

bool board::movePiece(int startX, int startY, int endX, int endY) {
    if (startX < 0 || startX >= rows || startY < 0 || startY >= cols ||
        endX < 0 || endX >= rows || endY < 0 || endY >= cols) {
        return false;
    }

    auto piece = grid[startX][startY];
    if (!piece) {
        return false;
    }

    if (piece->isValidMove(endX, endY, grid)) {
        piece->move(endX, endY);
        grid[endX][endY] = piece;
        grid[startX][startY] = nullptr;
        return true;
    }

    return false;
}

shared_ptr<chessPiece> board::getPieceAt(int x, int y) const {
    if (x < 0 || x >= rows || y < 0 || y >= cols) {
        return nullptr;
    }
    return grid[x][y];
}

void board::setPieceAt(int x, int y, shared_ptr<chessPiece> piece) {
    if (x >= 0 && x < rows && y >= 0 && y < cols) {
        grid[x][y] = piece;
    }
}

void board::printBoard() const {
    for (const auto& row : grid) {
        for (const auto& piece : row) {
            if (piece) {
                cout << piece->getPieceChar() << " ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
}

void board::clearBoard() {
    for (auto& row : grid) {
        for (auto& piece : row) {
            piece.reset();
        }
    }
}
