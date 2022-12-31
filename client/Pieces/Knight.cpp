#include "Knight.hpp"

Knight::Knight(Piece::Color color, Square *square, const sf::Vector2f &pos) :
    Piece(square, color, Piece::Knight, color == Piece::White ? "Pieces/Resources/WhiteKnight.png" : "Pieces/Resources/BlackKnight.png", 3, pos)
{
}

void Knight::generateMoves(Board &board)
{
    m_moves.clear();

    short file = square()->file();
    short rank = square()->rank();

    if (isMoveValid(file - 2, rank - 1, board)) {
        m_moves.push_back(board.m_board[file - 2][rank - 1]);
    }
    if (isMoveValid(file - 2, rank + 1, board)) {
        m_moves.push_back(board.m_board[file - 2][rank + 1]);
    }
    if (isMoveValid(file + 2, rank - 1, board)) {
        m_moves.push_back(board.m_board[file + 2][rank - 1]);
    }
    if (isMoveValid(file + 2, rank + 1, board)) {
        m_moves.push_back(board.m_board[file + 2][rank + 1]);
    }
    if (isMoveValid(file - 1, rank - 2, board)) {
        m_moves.push_back(board.m_board[file - 1][rank - 2]);
    }
    if (isMoveValid(file + 1, rank - 2, board)) {
        m_moves.push_back(board.m_board[file + 1][rank - 2]);
    }
    if (isMoveValid(file - 1, rank + 2, board)) {
        m_moves.push_back(board.m_board[file - 1][rank + 2]);
    }
    if (isMoveValid(file + 1, rank + 2, board)) {
        m_moves.push_back(board.m_board[file + 1][rank + 2]);
    }
}

bool Knight::isMoveValid(short dstFile, short dstRank, Board &board) const
{
    return (dstFile >= 0 && dstFile < 8 && dstRank >= 0 && dstRank < 8)
            && (board.m_board[dstFile][dstRank]->isEmpty() || board.m_board[dstFile][dstRank]->piece()->color() != color()); 
}