#include "Board.hpp"
#include "Pieces/Pawn.hpp"
#include "Pieces/Castle.hpp"
#include "Pieces/Knight.hpp"
#include "Pieces/Bishop.hpp"
#include "Pieces/Queen.hpp"
#include "Pieces/King.hpp"

#include <SFML/Graphics.hpp>

Board::Board()
{
    startPos = sf::Vector2f(678, 258);

    int x = startPos.x, y = startPos.y;
    for (int i = 7; i >= 0; --i) {
        for (int j = 0; j < 8; ++j) {
            x += 50;
            m_board[j][i] = new Square(j, i, (i + j) % 2 ? sf::Color(60, 179, 113) : sf::Color::White, sf::Vector2f(50, 50), sf::Vector2f(x, y));
        }
        y += 50;
        x = startPos.x;
    }

    populateBoard();
}

void Board::populateBoard()
{
    Piece *p;

    /* pawns */
    for (int i = 0; i < 8; ++i) {
        p = new Pawn(Piece::White, m_board[i][1], m_board[i][1]->pos());
        m_board[i][1]->setPiece(p);
        p = new Pawn(Piece::Black, m_board[i][6], m_board[i][6]->pos());
        m_board[i][6]->setPiece(p);
    }

    /* castles */
    p = new Castle(Piece::Black, m_board[7][7], m_board[7][7]->pos());
    m_board[7][7]->setPiece(p);
    p = new Castle(Piece::Black, m_board[0][7], m_board[0][7]->pos());
    m_board[0][7]->setPiece(p);
    p = new Castle(Piece::White, m_board[0][0], m_board[0][0]->pos());
    m_board[0][0]->setPiece(p);
    p = new Castle(Piece::White, m_board[7][0], m_board[7][0]->pos());
    m_board[7][0]->setPiece(p);

    /* knights */
    p = new Knight(Piece::Black, m_board[1][7], m_board[1][7]->pos());
    m_board[1][7]->setPiece(p);
    p = new Knight(Piece::Black, m_board[6][7], m_board[6][7]->pos());
    m_board[6][7]->setPiece(p);
    p = new Knight(Piece::White, m_board[1][0], m_board[1][0]->pos());
    m_board[1][0]->setPiece(p);
    p = new Knight(Piece::White, m_board[6][0], m_board[6][0]->pos());
    m_board[6][0]->setPiece(p);

    /* bishops */
    p = new Bishop(Piece::Black, m_board[2][7], m_board[2][7]->pos());
    m_board[2][7]->setPiece(p);
    p = new Bishop(Piece::Black, m_board[5][7], m_board[5][7]->pos());
    m_board[5][7]->setPiece(p);
    p = new Bishop(Piece::White, m_board[2][0], m_board[2][0]->pos());
    m_board[2][0]->setPiece(p);
    p = new Bishop(Piece::White, m_board[5][0], m_board[5][0]->pos());
    m_board[5][0]->setPiece(p);

    /* queens */
    p = new Queen(Piece::Black, m_board[4][7], m_board[4][7]->pos());
    m_board[4][7]->setPiece(p);
    p = new Queen(Piece::White, m_board[4][0], m_board[4][0]->pos());
    m_board[4][0]->setPiece(p);

    /* kings */
    p = new King(Piece::Black, m_board[3][7], m_board[3][7]->pos());
    m_board[3][7]->setPiece(p);
    p = new King(Piece::White, m_board[3][0], m_board[3][0]->pos());
    m_board[3][0]->setPiece(p);
}

void Board::draw(sf::RenderWindow &window)
{
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            m_board[i][j]->draw(window);
        }
    }
}