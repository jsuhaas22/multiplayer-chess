#ifndef BOARD
#define BOARD

#include "Square.hpp"

#include <SFML/Graphics.hpp>

class Game;

class Board
{
public:
    Board();
    void draw(sf::RenderWindow &window);
    void handleMouseEvt(const sf::Vector2f &pos);
    void setGame(Game *game);
    
    Square *m_board[8][8];
private:
    void populateBoard();
    std::pair<short, short> posToIndices(const sf::Vector2f &pos);
    void highlightSquares();
    void dehighlightSquares();
    void dehighlight(Square *square);
    void generateMoves(const std::pair<short, short> &indices);

    sf::Vector2f m_startPos;
    Square *m_highlightedSquare;
    std::vector<Square*> m_highlightedSquares;
    Game *m_game;
};

#endif