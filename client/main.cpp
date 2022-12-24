#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 860), "Chess");
    while (window.isOpen()) {
        sf::Event evt;
        while (window.pollEvent(evt)) {
            if (evt.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();
        window.display();
    }
    return 0;
}