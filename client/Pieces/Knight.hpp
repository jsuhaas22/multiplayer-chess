#ifndef KNIGHT
#define KNIGHT

#include "Piece.hpp"

class Knight : public Piece
{
public:
    Knight(Piece::Color color, Square *square);
    void generateMoves(Board &board);

private:
    bool isMoveValid(short dstFile, short dstRank, Board &board) const;
};

#endif //KNIGHT