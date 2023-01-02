#ifndef GAME
#define GAME

#include "Board.hpp"
#include "Player.hpp"
#include <SFML/Graphics.hpp>

class Game
{
public:
    Game();
    void gameLoop(sf::RenderWindow &window);

    Player *pwhite();
    Player *pblack();

private:
    Player *m_pwhite;
    Player *m_pblack;
    Board m_board;
};

#endif //GAME