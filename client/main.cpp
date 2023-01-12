#include "Game.hpp"

#include <SFML/Graphics.hpp>

#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Chess");
    Game g(Piece::White);
    g.gameLoop(window);
    window.close();
    return 0;
}