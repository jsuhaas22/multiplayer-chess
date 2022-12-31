#include "Board.hpp"
#include "Pieces/Pawn.hpp"
#include "Pieces/Castle.hpp"

#include <SFML/Graphics.hpp>

Board::Board()
{
    startPos = sf::Vector2f(678, 258);

    int x = startPos.x, y = startPos.y;
    for (int i = 7; i >= 0; --i) {
        for (int j = 7; j >= 0; --j) {
            x += 50;
            m_board[i][j] = new Square(i, j, (i + j) % 2 ? sf::Color(60, 179, 113) : sf::Color::White, sf::Vector2f(50, 50), sf::Vector2f(x, y));
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
        p = new Pawn(Piece::White, m_board[1][i], m_board[1][i]->pos());
        m_board[1][i]->setPiece(p);
        p = new Pawn(Piece::Black, m_board[6][i], m_board[6][i]->pos());
        m_board[6][i]->setPiece(p);
    }

    /* castles */
    p = new Castle(Piece::Black, m_board[7][7], m_board[7][7]->pos());
    m_board[7][7]->setPiece(p);
    p = new Castle(Piece::Black, m_board[7][0], m_board[7][0]->pos());
    m_board[7][0]->setPiece(p);
    p = new Castle(Piece::White, m_board[0][0], m_board[0][0]->pos());
    m_board[0][0]->setPiece(p);
    p = new Castle(Piece::White, m_board[0][7], m_board[0][7]->pos());
    m_board[0][7]->setPiece(p);
}

void Board::draw(sf::RenderWindow &window)
{
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            m_board[i][j]->draw(window);
        }
    }
}