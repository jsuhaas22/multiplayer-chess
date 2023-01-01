#include "Bishop.hpp"

Bishop::Bishop(Piece::Color color, Square *square) :
    Piece(square, color, Type::Bishop, color == Color::White ? "Pieces/Resources/WhiteBishop.png" : "Pieces/Resources/BlackBishop.png", 4)
{
}

void Bishop::generateMoves(Board &board)
{
    m_moves.clear();

    short file = square()->file();
    short rank = square()->rank();
    short i, j;

    /* diagonally left backward */
    for (i = file - 1, j = rank - 1; i >= 0 && j >= 0 && board.m_board[i][j]->isEmpty(); --i, --j) {
        m_moves.push_back(board.m_board[i][j]);
    }
    if (i >= 0 && j >= 0 && board.m_board[i][j]->piece()->color() != color()) {
        m_moves.push_back(board.m_board[i][j]);
    }

    /* diagonally right backward */
    for (i = file + 1, j = rank - 1; i < 8 && j >= 0 && board.m_board[i][j]->isEmpty(); ++i, --j) {
        m_moves.push_back(board.m_board[i][j]);
    }
    if (i < 8 && j >= 0 && board.m_board[i][j]->piece()->color() != color()) {
        m_moves.push_back(board.m_board[i][j]);
    }

    /* diagonally left forward */
    for (i = file - 1, j = rank + 1; i >= 0 && j < 8 && board.m_board[i][j]->isEmpty(); --i, ++j) {
        m_moves.push_back(board.m_board[i][j]);
    }
    if (i >= 0 && j < 8 && board.m_board[i][j]->piece()->color() != color()) {
        m_moves.push_back(board.m_board[i][j]);
    }

    /* diagonally right forward */
    for (i = file + 1, j = rank + 1; i < 8 && j < 8 && board.m_board[i][j]->isEmpty(); ++i, ++j) {
        m_moves.push_back(board.m_board[i][j]);
    }
    if (i < 8 && j < 8 && board.m_board[i][j]->piece()->color() != color()) {
        m_moves.push_back(board.m_board[i][j]);
    }
}