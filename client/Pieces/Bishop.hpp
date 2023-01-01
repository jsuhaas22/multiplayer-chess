#ifndef BISHOP
#define BISHOP

#include "Piece.hpp"

class Bishop : public Piece
{
public:
    Bishop(Piece::Color color, Square *square);
    void generateMoves(Board &board);
};

#endif //BISHOP