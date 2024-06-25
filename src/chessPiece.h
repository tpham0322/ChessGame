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
    chessPiece(const string& color, int startX, int startY);
    virtual ~chessPiece();

    string getColorType() const;
    void setColorType(const string& color);
    void getPos(int& outX, int& outY) const;
    virtual void move(int newX, int newY) = 0;  // Pure virtual function for movement
};

class pawn : public chessPiece {
public:
    pawn(const string& color, int startX, int startY);
    ~pawn() override;
    void move(int newX, int newY) override;
};

class king : public chessPiece {
public:
    king(const string& color, int startX, int startY);
    ~king() override;
    void move(int newX, int newY) override;
};

class queen : public chessPiece {
public:
    queen(const string& color, int startX, int startY);
    ~queen() override;
    void move(int newX, int newY) override;
};

class bishop : public chessPiece {
public:
    bishop(const string& color, int startX, int startY);
    ~bishop() override;
    void move(int newX, int newY) override;
};

class knight : public chessPiece {
public:
    knight(const string& color, int startX, int startY);
    ~knight() override;
    void move(int newX, int newY) override;
};

class rook : public chessPiece {
public:
    rook(const string& color, int startX, int startY);
    ~rook() override;
    void move(int newX, int newY) override;
};

#endif // CHESSPIECE_H
