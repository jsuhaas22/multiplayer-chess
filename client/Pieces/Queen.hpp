#ifndef QUEEN
#define QUEEN

#include "Piece.hpp"

class Queen : public Piece
{
public:
    Queen(Piece::Color color, Square *square, const sf::Vector2f &pos);
    void generateMoves(Board &board);

private:
    void generateLineMoves(Board &board, short file, short rank);
    void generateDiagonalMoves(Board &board, short file, short rank);
};

#endif //QUEEN