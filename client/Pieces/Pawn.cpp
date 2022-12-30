#include "Pawn.hpp"

Pawn::Pawn(Piece::Color color, Square *square) :
    Piece(square, color, Type::Pawn, color == Piece::White ? "Resources/WhitePawn.png" : "Resources/BlackPawn.png", 1)
{
}

void Pawn::generateMoves(Board &board)
{
    //TODO: add en passant moves
    m_moves.clear();

    unsigned short rank = square()->rank();
    unsigned short file = square()->file();
    short dir = color() == Piece::White ? 1 : -1;

    if (!board.m_board[rank][file + 1 * dir]->piece()) {
        m_moves.push_back(board.m_board[rank][file + 1 * dir]);
        if (!m_noOfMoves && !board.m_board[rank][file + 2 * dir]->piece()) {
            m_moves.push_back(board.m_board[rank][file + 2 * dir]);
        }
    }

    Square *sq;
    if (rank) {
        sq = board.m_board[rank - 1][file + 1 * dir];
        if (sq->piece() && sq->piece()->color() != color()) {
            m_moves.push_back(sq);
        }
    }
    if (rank < 8) {
        sq = board.m_board[rank + 1][file + 1 * dir];
        if (sq->piece() && sq->piece()->color() != color()) {
            m_moves.push_back(sq);
        }
    }
}