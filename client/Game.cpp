#include "Game.hpp"

void Game::gameLoop(sf::RenderWindow &window)
{
    while (window.isOpen()) {
        sf::Event evt;
        while (window.pollEvent(evt)) {
            if (evt.type == sf::Event::MouseButtonPressed) {
                m_board.handleMouseEvt(sf::Vector2f(evt.mouseButton.x, evt.mouseButton.y));
            } else if (evt.type == sf::Event::Closed) {
                return;
            }
        }
        window.clear();
        m_board.draw(window);
        window.display();
    }
}