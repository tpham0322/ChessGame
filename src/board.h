#include <vector>
#include <memory>
#include "chessPiece.h"

using namespace std;

class board
{
private:
    vector<vector<shared_ptr<chessPiece>>> grid;
    int rows;
    int cols;
public:
    board(int rows, int cols);
    ~board();

    void initializeBoard();
    bool movePiece(int startX, int startY, int endX, int endY);
    shared_ptr<chessPiece> getPieceAt(int x, int y) const;
    void setPieceAt(int x, int y, shared_ptr<chessPiece> piece);
    void printBoard() const;
    void clearBoard();
};
