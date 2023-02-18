#ifndef GAME
#define GAME

#include "Board.hpp"
#include "Player.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

class Game
{
public:
    Game();
    void gameLoop(sf::RenderWindow &window);
    void sendMoves(const std::pair<short, short> &dst, const std::pair<short, short> &src);

    Piece::Color color() const;

private:
    void connectToServer();
    
    Piece::Color m_color; /* this client's color */
    Board m_board;
    bool m_isTurn; /* true if it is the client's turn to play */
    bool m_hasGameBegun;
    sf::TcpSocket m_socket;
};

#endif //GAME