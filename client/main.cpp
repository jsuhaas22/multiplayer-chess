#include "Board.hpp"

#include <SFML/Graphics.hpp>

#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Chess");
    Board b;
    while (window.isOpen()) {
        sf::Event evt;
        while (window.pollEvent(evt)) {
            if (evt.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();
        b.draw(window);
        window.display();
    }
    return 0;
}