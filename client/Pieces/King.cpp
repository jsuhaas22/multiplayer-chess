#include "King.hpp"
#include "../Helper.hpp"

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

    if (isInBounds(file - 1, rank - 1)) {
        board.m_board[file - 1][rank - 1]->addPiece(this);
        if (isMoveValid(file - 1, rank - 1, board)) {
            m_moves.push_back(board.m_board[file - 1][rank - 1]);
        }
    }
    if (isInBounds(file, rank - 1)) {
        board.m_board[file][rank - 1]->addPiece(this);
        if (isMoveValid(file, rank - 1, board)) {
            m_moves.push_back(board.m_board[file][rank - 1]);
        }
    }
    if (isInBounds(file + 1, rank - 1)) {
        board.m_board[file + 1][rank - 1]->addPiece(this);
        if (isMoveValid(file + 1, rank - 1, board)) {
            m_moves.push_back(board.m_board[file + 1][rank - 1]);
        }
    }
    if (isInBounds(file + 1, rank)) {
        board.m_board[file + 1][rank]->addPiece(this);
        if (isMoveValid(file + 1, rank, board)) {
            m_moves.push_back(board.m_board[file + 1][rank]);
        }
    }
    if (isInBounds(file + 1, rank + 1)) {
        board.m_board[file + 1][rank + 1]->addPiece(this);
        if (isMoveValid(file + 1, rank + 1, board)) {
            m_moves.push_back(board.m_board[file + 1][rank + 1]);
        }
    }
    if (isInBounds(file, rank + 1)) {
        board.m_board[file][rank + 1]->addPiece(this);
        if (isMoveValid(file, rank + 1, board)) {
            m_moves.push_back(board.m_board[file][rank + 1]);
        }
    }
    if (isInBounds(file - 1, rank + 1)) {
        board.m_board[file - 1][rank + 1]->addPiece(this);
        if (isMoveValid(file - 1, rank + 1, board)) {
            m_moves.push_back(board.m_board[file - 1][rank + 1]);
        }
    }
    if (isInBounds(file - 1, rank)) {
        board.m_board[file - 1][rank]->addPiece(this);
        if (isMoveValid(file - 1, rank, board)) {
            m_moves.push_back(board.m_board[file - 1][rank]);
        }
    }
}

bool King::isMoveValid(short file, short rank, Board &board) const
{
    return (board.m_board[file][rank]->isEmpty() || board.m_board[file][rank]->piece()->color() != color());
}

void King::move(Square *square)
{
    setSquare(square);
    m_hasMoved = true;
}