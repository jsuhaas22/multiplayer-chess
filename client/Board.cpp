#include "Board.hpp"

#include <SFML/Graphics.hpp>

Board::Board()
{
    startPos = sf::Vector2f(678, 258);

    int x = startPos.x, y = startPos.y;
    for (int i = 7; i >= 0; --i) {
        for (int j = 7; j >= 0; --j) {
            x += 50;
            m_board[i][j].setPosition(sf::Vector2f(x, y));
            m_board[i][j].setRankFile(i, j);
            m_board[i][j].setColor((i + j) % 2 ? sf::Color::Black : sf::Color::White);
        }
        y += 50;
        x = startPos.x;
    }
}

void Board::draw(sf::RenderWindow &window)
{
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            m_board[i][j].draw(window);
        }
    }
}