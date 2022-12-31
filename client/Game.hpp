#ifndef GAME
#define GAME

#include "Board.hpp"
#include <SFML/Graphics.hpp>

class Game
{
public:
    void gameLoop(sf::RenderWindow &window);

private:

    Board m_board;
};

#endif //GAME