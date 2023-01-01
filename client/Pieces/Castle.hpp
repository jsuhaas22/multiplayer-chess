#ifndef CASTLE
#define CASTLE

#include "Piece.hpp"

class Castle : public Piece
{
public:
    Castle(Piece::Color color, Square *square);
    void generateMoves(Board &board);

private:
    bool m_hasMoved; /* if false, castling is possible */
};

#endif //CASTLE