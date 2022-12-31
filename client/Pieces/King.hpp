#ifndef KING
#define KING

#include "Piece.hpp"

class King : public Piece
{
public:
    King(Piece::Color color, Square *square, const sf::Vector2f &pos);
    void generateMoves(Board &board);

private:
    bool isMoveValid(const short file, const short rank, Board &board) const;
    bool m_hasMoved; /* helps decide if castling is legal */
};

#endif //KING