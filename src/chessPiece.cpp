#include "chessPiece.h"

// Implementation for chessPiece
chessPiece::chessPiece(const string& color, int startX, int startY)
    : colorType(color), x(startX), y(startY) {}

chessPiece::~chessPiece() {}

string chessPiece::getColorType() const {
    return colorType;
}

void chessPiece::setColorType(const string& color) {
    colorType = color;
}

void chessPiece::getPos(int& outX, int& outY) const {
    outX = x;
    outY = y;
}

// Implementation for pawn
pawn::pawn(const string& color, int startX, int startY)
    : chessPiece(color, startX, startY) {}

pawn::~pawn() {}



void pawn::move(int newX, int newY) {
    if (getColorType() == "white") {
        if (newY == y && (newX == x + 1 || (x == 1 && newX == x + 2))) {
            // Move forward one or two squares if initial position
            x = newX;
            y = newY;
        } else {
            cout << "Invalid move for white pawn" << endl;
        }
    } else if (getColorType() == "black") {
        if (newY == y && (newX == x - 1 || (x == 6 && newX == x - 2))) {
            // Move forward one or two squares if initial position
            x = newX;
            y = newY;
        } else {
            cout << "Invalid move for black pawn" << endl;
        }
    } else {
        cout << "Invalid move for pawn" << endl;
    }
}

// Implementation for other chess pieces
// ...

// Implementation for king
king::king(const string& color, int startX, int startY)
    : chessPiece(color, startX, startY) {}

king::~king() {}

void king::move(int newX, int newY) {
    // Implement king-specific movement logic
    if (abs(newX - x) <= 1 && abs(newY - y) <= 1) {
        x = newX;
        y = newY;
    } else {
        cout << "Invalid move for king" << endl;
    }
}

// Implementation for queen
queen::queen(const string& color, int startX, int startY)
    : chessPiece(color, startX, startY) {}

queen::~queen() {}

void queen::move(int newX, int newY) {
    // Implement queen-specific movement logic
    if (abs(newX - x) == abs(newY - y) || newX == x || newY == y) {
        x = newX;
        y = newY;
    } else {
        cout << "Invalid move for queen" << endl;
    }
}

// Implementation for bishop
bishop::bishop(const string& color, int startX, int startY)
    : chessPiece(color, startX, startY) {}

bishop::~bishop() {}

void bishop::move(int newX, int newY) {
    // Implement bishop-specific movement logic
    if (abs(newX - x) == abs(newY - y)) {
        x = newX;
        y = newY;
    } else {
        cout << "Invalid move for bishop" << endl;
    }
}

// Implementation for knight
knight::knight(const string& color, int startX, int startY)
    : chessPiece(color, startX, startY) {}

knight::~knight() {}

void knight::move(int newX, int newY) {
    // Implement knight-specific movement logic
    if ((abs(newX - x) == 2 && abs(newY - y) == 1) || (abs(newX - x) == 1 && abs(newY - y) == 2)) {
        x = newX;
        y = newY;
    } else {
        cout << "Invalid move for knight" << endl;
    }
}

// Implementation for rook
rook::rook(const string& color, int startX, int startY)
    : chessPiece(color, startX, startY) {}

rook::~rook() {}

void rook::move(int newX, int newY) {
    // Implement rook-specific movement logic
    if (newX == x || newY == y) {
        x = newX;
        y = newY;
    } else {
        cout << "Invalid move for rook" << endl;
    }
}
