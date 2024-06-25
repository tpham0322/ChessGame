#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <string>
#include <iostream>

using namespace std;

class chessPiece {
private:
    string colorType;

protected:
    int x;
    int y;

public:
    chessPiece(const string& color, int startX, int startY)
        : colorType(color), x(startX), y(startY) {}

    virtual ~chessPiece() {}

    string getColorType() const {
        return colorType;
    }

    void setColorType(const string& color) {
        colorType = color;
    }

    void getPos(int& outX, int& outY) const {
        outX = x;
        outY = y;
    }

    virtual void move(int newX, int newY) = 0;  // Pure virtual function for movement
};

class pawn : public chessPiece {
public:
    pawn(const string& color, int startX, int startY)
        : chessPiece(color, startX, startY) {}

    ~pawn() override {}

    void move(int newX, int newY) override {
        // Implement pawn-specific movement logic
        x = newX;
        y = newY;
    }
};

class king : public chessPiece {
public:
    king(const string& color, int startX, int startY)
        : chessPiece(color, startX, startY) {}

    ~king() override {}

    void move(int newX, int newY) override {
        // Implement king-specific movement logic
        x = newX;
        y = newY;
    }
};

class queen : public chessPiece {
public:
    queen(const string& color, int startX, int startY)
        : chessPiece(color, startX, startY) {}

    ~queen() override {}

    void move(int newX, int newY) override {
        // Implement queen-specific movement logic
        x = newX;
        y = newY;
    }
};

class bishop : public chessPiece {
public:
    bishop(const string& color, int startX, int startY)
        : chessPiece(color, startX, startY) {}

    ~bishop() override {}

    void move(int newX, int newY) override {
        // Implement bishop-specific movement logic
        x = newX;
        y = newY;
    }
};

class knight : public chessPiece {
public:
    knight(const string& color, int startX, int startY)
        : chessPiece(color, startX, startY) {}

    ~knight() override {}

    void move(int newX, int newY) override {
        // Implement knight-specific movement logic
        x = newX;
        y = newY;
    }
};

class rook : public chessPiece {
public:
    rook(const string& color, int startX, int startY)
        : chessPiece(color, startX, startY) {}

    ~rook() override {}

    void move(int newX, int newY) override {
        // Implement rook-specific movement logic
        x = newX;
        y = newY;
    }
};

#endif // CHESSPIECE_H
