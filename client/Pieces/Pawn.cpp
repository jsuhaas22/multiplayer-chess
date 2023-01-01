#include "Pawn.hpp"

Pawn::Pawn(Piece::Color color, Square *square) :
    Piece(square, color, Type::Pawn, color == Piece::White ? "Pieces/Resources/WhitePawn.png" : "Pieces/Resources/BlackPawn.png", 1)
{
    m_noOfMoves = 0;
}

void Pawn::generateMoves(Board &board)
{
    //TODO: add en passant moves
    m_moves.clear();

    unsigned short rank = square()->rank();
    unsigned short file = square()->file();

    if (board.m_board[file][rank + 1]->isEmpty()) {
        m_moves.push_back(board.m_board[file][rank + 1]);
        if (!m_noOfMoves && board.m_board[file][rank + 2]->isEmpty()) {
            m_moves.push_back(board.m_board[file][rank + 2]);
        }
    }

    if (isMoveValid(file - 1, rank + 1, board)) {
        m_moves.push_back(board.m_board[file - 1][rank + 1]);
    }

    if (isMoveValid(file + 1, rank + 1, board)) {
        m_moves.push_back(board.m_board[file + 1][rank + 1]);
    }
}

bool Pawn::isMoveValid(short file, short rank, Board &board) const
{
    return file >= 0 && file < 8 && rank >= 0 && rank < 8
        && !board.m_board[file][rank]->isEmpty() && board.m_board[file][rank]->piece()->color() != color();
}