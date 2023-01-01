#include "King.hpp"

King::King(Piece::Color color, Square *square) :
    Piece(square, color, Type::King, color == Color::White ? "Pieces/Resources/WhiteKing.png" : "Pieces/Resources/BlackKing.png", 10)
{
    m_hasMoved = false;
}

void King::generateMoves(Board &board)
{
    m_moves.clear();

    short file = square()->file();
    short rank = square()->rank();

    if (isMoveValid(file - 1, rank - 1, board)) {
        m_moves.push_back(board.m_board[file - 1][rank - 1]);
    }
    if (isMoveValid(file, rank - 1, board)) {
        m_moves.push_back(board.m_board[file][rank - 1]);
    }
    if (isMoveValid(file + 1, rank - 1, board)) {
        m_moves.push_back(board.m_board[file + 1][rank - 1]);
    }
    if (isMoveValid(file + 1, rank, board)) {
        m_moves.push_back(board.m_board[file + 1][rank]);
    }
    if (isMoveValid(file + 1, rank + 1, board)) {
        m_moves.push_back(board.m_board[file + 1][rank + 1]);
    }
    if (isMoveValid(file, rank + 1, board)) {
        m_moves.push_back(board.m_board[file + 1][rank]);
    }
    if (isMoveValid(file - 1, rank + 1, board)) {
        m_moves.push_back(board.m_board[file - 1][rank + 1]);
    }
    if (isMoveValid(file - 1, rank, board)) {
        m_moves.push_back(board.m_board[file - 1][rank]);
    }
}

bool King::isMoveValid(short file, short rank, Board &board) const
{
    return (file >= 0 && file < 8 && rank >= 0 && rank < 8)
        && (board.m_board[file][rank]->isEmpty() || board.m_board[file][rank]->piece()->color() != color());
}