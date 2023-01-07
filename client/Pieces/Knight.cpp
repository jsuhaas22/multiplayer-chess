#include "Knight.hpp"
#include "../Helper.hpp"

Knight::Knight(Piece::Color color, Square *square) :
    Piece(square, color, Piece::Knight, color == Piece::White ? "Pieces/Resources/WhiteKnight.png" : "Pieces/Resources/BlackKnight.png", 3)
{
}

void Knight::generateMoves(Board &board)
{
    m_moves.clear();

    short file = square()->file();
    short rank = square()->rank();

    if (isInBounds(file - 2, rank - 1)) {
        board.m_board[file - 2][rank - 1]->addPiece(this);
        if (isMoveValid(file - 2, rank - 1, board)) {
            m_moves.push_back(board.m_board[file - 2][rank - 1]);
        }
    }
    if (isInBounds(file - 2, rank + 1)) {
        board.m_board[file - 2][rank + 1]->addPiece(this);
        if (isMoveValid(file - 2, rank + 1, board)) {
            m_moves.push_back(board.m_board[file - 2][rank + 1]);
        }
    }
    if (isInBounds(file + 2, rank - 1)) {
        board.m_board[file + 2][rank - 1]->addPiece(this);
        if (isMoveValid(file + 2, rank - 1, board)) {
            m_moves.push_back(board.m_board[file + 2][rank - 1]);
        }
    }
    if (isInBounds(file + 2, rank + 1)) {
        board.m_board[file + 2][rank + 1]->addPiece(this);
        if (isMoveValid(file + 2, rank + 1, board)) {
            m_moves.push_back(board.m_board[file + 2][rank + 1]);
        }
    }
    if (isInBounds(file - 1, rank - 2)) {
        board.m_board[file - 1][rank - 2]->addPiece(this);
        if (isMoveValid(file - 1, rank - 2, board)) {
            m_moves.push_back(board.m_board[file - 1][rank - 2]);
        }
    }
    if (isInBounds(file + 1, rank - 2)) {
        board.m_board[file + 1][rank - 2]->addPiece(this);
        if (isMoveValid(file + 1, rank - 2, board)) {
            m_moves.push_back(board.m_board[file + 1][rank - 2]);
        }
    }
    if (isInBounds(file - 1, rank + 2)) {
        board.m_board[file - 1][rank + 2]->addPiece(this);
        if (isMoveValid(file - 1, rank + 2, board)) {
            m_moves.push_back(board.m_board[file - 1][rank + 2]);
        }
    }
    if (isInBounds(file + 1, rank + 2)) {
        board.m_board[file + 1][rank + 2]->addPiece(this);
        if (isMoveValid(file + 1, rank + 2, board)) {
            m_moves.push_back(board.m_board[file + 1][rank + 2]);
        }
    }
}

bool Knight::isMoveValid(short dstFile, short dstRank, Board &board) const
{
    return (board.m_board[dstFile][dstRank]->isEmpty() || board.m_board[dstFile][dstRank]->piece()->color() != color()); 
}