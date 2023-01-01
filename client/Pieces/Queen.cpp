#include "Queen.hpp"

Queen::Queen(Piece::Color color, Square *square, const sf::Vector2f &pos) :
    Piece(square, color, Type::Queen, color == Color::White ? "Pieces/Resources/WhiteQueen.png" : "Pieces/Resources/BlackQueen.png", 8, pos)
{
}

void Queen::generateMoves(Board &board)
{
    m_moves.clear();

    short file = square()->file();
    short rank = square()->rank();
    generateLineMoves(board, file, rank);
    generateDiagonalMoves(board, file, rank);    
}

void Queen::generateLineMoves(Board &board, short file, short rank)
{
    short i, j;

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

void Queen::generateDiagonalMoves(Board &board, short rank, short file)
{
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