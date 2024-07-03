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


bool pawn::isValidMove(int newX, int newY, const vector<vector<shared_ptr<chessPiece>>>& grid) const {
    if (getColorType() == "White") {
        // Move forward one or two squares if initial position
        if (newY == y && ((newX == x + 1 && !grid[newX][newY]) || (x == 1 && newX == x + 2 && !grid[newX][newY] && !grid[x + 1][newY]))) {
            return true;
        }
    } else if (getColorType() == "Black") {
        // Move forward one or two squares if initial position
        if (newY == y && ((newX == x - 1 && !grid[newX][newY]) || (x == 6 && newX == x - 2 && !grid[newX][newY] && !grid[x - 1][newY]))) {
            return true;
        }
    }
    return false;
}

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

char pawn::getPieceChar() const {
    return getColorType() == "White" ? 'P' : 'p';
}


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


bool queen::isValidMove(int newX, int newY, const vector<vector<shared_ptr<chessPiece>>>& grid) const {
    int dx = abs(newX - x);
    int dy = abs(newY - y);

    if ((dx == dy) || (newX == x) || (newY == y)) {
        // Check if path is clear
        int xDir = (newX - x) != 0 ? (newX - x) / dx : 0;
        int yDir = (newY - y) != 0 ? (newY - y) / dy : 0;

        int checkX = x + xDir;
        int checkY = y + yDir;

        while (checkX != newX || checkY != newY) {
            if (grid[checkX][checkY]) {
                return false;
            }
            checkX += xDir;
            checkY += yDir;
        }
        return true;
    }
    return false;
}


void queen::move(int newX, int newY) {

    x = newX;
    y = newY;
}

char queen::getPieceChar() const {
    return getColorType() == "White" ? 'Q' : 'q';
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

bool knight::isValidMove(int newX, int newY, const vector<vector<shared_ptr<chessPiece>>>& grid) const {
    int dx = abs(newX - x);
    int dy = abs(newY - y);

    // Knights move in an "L" shape: 2 squares in one direction and 1 in the other
    return (dx == 2 && dy == 1) || (dx == 1 && dy == 2);
}

void knight::move(int newX, int newY) {
    x = newX;
    y = newY;
}

char knight::getPieceChar() const {
    return getColorType() == "White" ? 'K' : 'k';
}

// Implementation for rook
rook::rook(const string& color, int startX, int startY)
    : chessPiece(color, startX, startY) {}

rook::~rook() {}

bool rook::isValidMove(int newX, int newY, const vector<vector<shared_ptr<chessPiece>>>& grid) const {
    if(x != newX && y != newY) {
        return false;
    }

    int xDir = (newX - x) == 0 ? 0 : (newX - x) / abs(newX - x);
    int yDir = (newY - y) == 0 ? 0 : (newY - y) / abs(newY - y);

    int checkX = x + xDir;
    int checkY = y + yDir;

    while (checkX != newX || checkY != newY) {
        if (grid[checkX][checkY]) {
            return false;
        }
        checkX += xDir;
        checkY += yDir;
    }
    return true;

}

void rook::move(int newX, int newY) {
    // Implement rook-specific movement logic
    if (newX == x || newY == y) {
        x = newX;
        y = newY;
    } else {
        cout << "Invalid move for rook" << endl;
    }
}

char rook::getPieceChar() const {
    return getColorType() == "White" ? 'R' : 'r';
}
