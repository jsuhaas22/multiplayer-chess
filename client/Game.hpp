#ifndef GAME
#define GAME

#include "Board.hpp"
#include "Player.hpp"
#include <SFML/Graphics.hpp>

class Game
{
public:
    Game(const Piece::Color &color);
    void gameLoop(sf::RenderWindow &window);

    Piece::Color color() const;

private:
    void connectToServer();
    
    Piece::Color m_color; /* this client's color */
    Board m_board;
    bool m_isTurn; /* true if it is the client's turn to play */
};

#endif //GAME