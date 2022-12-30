#include "Board.hpp"
#include "Pieces/Pawn.hpp"

#include <SFML/Graphics.hpp>

Board::Board()
{
    startPos = sf::Vector2f(678, 258);

    int x = startPos.x, y = startPos.y;
    for (int i = 7; i >= 0; --i) {
        for (int j = 7; j >= 0; --j) {
            x += 50;
            m_board[i][j] = new Square(i, j, (i + j) % 2 ? sf::Color::Black : sf::Color::White, sf::Vector2f(50, 50), sf::Vector2f(x, y));
        }
        y += 50;
        x = startPos.x;
    }

    populateBoard();
}

void Board::populateBoard()
{
    /* pawns */
    for (int i = 0; i < 8; ++i) {
        Piece *p = new Pawn(Piece::White, m_board[1][i], m_board[1][i]->pos());
        m_board[1][i]->setPiece(p);
        p = new Pawn(Piece::Black, m_board[6][i], m_board[6][i]->pos());
        m_board[6][i]->setPiece(p);
    }
}

void Board::draw(sf::RenderWindow &window)
{
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            m_board[i][j]->draw(window);
        }
    }
}