#ifndef PAWN
#define PAWN

#include "Piece.hpp"

class Pawn : public Piece
{
public:
    Pawn(Piece::Color color, Square *square);

    void generateMoves(Board &board);

private:
    unsigned short m_noOfMoves; /* helps decide if en passant is allowed and if 2 squares can be jumped */
};

#endif //PAWN