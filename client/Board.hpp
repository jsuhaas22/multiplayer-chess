#ifndef BOARD
#define BOARD

#include "Square.hpp"

#include <SFML/Graphics.hpp>

class Board
{
    public:
    Board();

    private:
    Square m_board[8][8];
    sf::Vector2f startPos;
};

#endif