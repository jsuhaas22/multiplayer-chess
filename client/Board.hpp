#ifndef BOARD
#define BOARD

#include "Square.hpp"

#include <SFML/Graphics.hpp>

class Board
{
public:
    Board();
    void draw(sf::RenderWindow &window);
    void handleMouseEvt(const sf::Vector2f &pos);
    
    Square *m_board[8][8];
private:
    void populateBoard();
    std::pair<short, short> posToIndices(const sf::Vector2f &pos);
    sf::Vector2f m_startPos;
};

#endif