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