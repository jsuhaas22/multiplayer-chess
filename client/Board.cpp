#include "Board.hpp"

#include <SFML/Graphics.hpp>

Board::Board()
{
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            m_board[i][j].setRankFile(i, j);
            m_board[i][j].setColor((i + j) % 2 ? sf::Color::Black : sf::Color::White);
        }
    }
}