#include <string>
#include <iostream>

using namespace std;


class chessPiece
{
private:
    string colorType;

protected:
    int x;
    int y;

public:

    string getColorType()
    {
        return colorType;
    }
    string setColorType(const string color)
    {
        colorType = color;
    }

    void getPos(int &outX, int &outY)
    {
        outX = x;
        outY = y;
    }

    chessPiece(/* args */);
    ~chessPiece();
};

chessPiece::chessPiece(/* args */)
{
}

chessPiece::~chessPiece()
{
}


class pawn : public chessPiece
{
    public:
    pawn(const std::string& color, int startX, int startY);
    ~pawn();

    void moveUp();
    void moveDown();
};

class king : public chessPiece
{
    public:
    king(const std::string& color, int startX, int startY);
    ~king();

    void moveKing();
};

class queen : public chessPiece
{
    public:
    queen(const std::string& color, int startX, int startY);
    ~queen();

    void moveQueen();
};

class bishop : public chessPiece
{
    public:
    bishop(const std::string& color, int startX, int startY);
    ~bishop();

    void moveBishop();
};

class knight : public chessPiece
{
    public:
    knight(const std::string& color, int startX, int startY);
    ~knight();

    void moveKnight();
};

class rook : public chessPiece
{
    public:
    rook(const std::string& color, int startX, int startY);
    ~rook();

    void moveRook();
};
