#include "Square.hpp"

#include <SFML/Graphics.hpp>

#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Chess");
    Square s(0, 0, sf::Color::White, sf::Vector2f(50, 50));
    s.setPosition(sf::Vector2f(5.0, 5.0));
    while (window.isOpen()) {
        sf::Event evt;
        while (window.pollEvent(evt)) {
            if (evt.type == sf::Event::Closed) {
                window.close();
            } else if (evt.type == sf::Event::MouseButtonPressed) {
                std::cout << 0 << 0 << std::endl;
                window.close();
            }
        }
        window.clear();
        window.draw(s);
        window.display();
    }
    return 0;
}