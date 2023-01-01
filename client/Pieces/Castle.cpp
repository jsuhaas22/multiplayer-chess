#include "Castle.hpp"

Castle::Castle(Piece::Color color, Square *square) :
    Piece(square, color, Type::Castle, color == Color::White ? "Pieces/Resources/WhiteCastle.png" : "Pieces/Resources/BlackCastle.png", 5)
{
    m_hasMoved = false;
}

void Castle::generateMoves(Board &board)
{
    m_moves.clear();

    short file = square()->file();
    short rank = square()->rank();
    short i;

    /* left check */
    for (i = file - 1; i >= 0 && board.m_board[i][rank]->isEmpty(); --i) {
        m_moves.push_back(board.m_board[i][rank]);
    }
    if (i >= 0 && board.m_board[i][rank]->piece()->color() != color()) {
        m_moves.push_back(board.m_board[i][rank]);
    }

    /* right check */
    for (i = file + 1; i < 8 && board.m_board[i][rank]->isEmpty(); ++i) {
        m_moves.push_back(board.m_board[i][rank]);
    }
    if (i < 8 && board.m_board[i][rank]->piece()->color() != color()) {
        m_moves.push_back(board.m_board[i][rank]);
    }

    /* backward check */
    for (i = rank - 1; i >= 0 && board.m_board[file][i]->isEmpty(); --i) {
        m_moves.push_back(board.m_board[file][i]);
    }
    if (i >= 0 && board.m_board[file][i]->piece()->color() != color()) {
        m_moves.push_back(board.m_board[file][i]);
    }

    /* forward check */
    for (i = rank + 1; i < 8 && board.m_board[file][i]->isEmpty(); ++i) {
        m_moves.push_back(board.m_board[file][i]);
    }
    if (i < 8 && board.m_board[file][i]->piece()->color() != color()) {
        m_moves.push_back(board.m_board[file][i]);
    }
}