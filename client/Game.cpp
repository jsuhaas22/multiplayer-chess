#include "Game.hpp"
#include "../Message.hpp"
#include <SFML/Network.hpp>

Game::Game(const Piece::Color &color) :
    m_color(color),
    m_isTurn(color == Piece::White)
{
    m_board.setGame(this);
    connectToServer();
}

void Game::gameLoop(sf::RenderWindow &window)
{
    while (window.isOpen()) {
        sf::Event evt;
        while (window.pollEvent(evt)) {
            if (evt.type == sf::Event::MouseButtonPressed && m_isTurn) {
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

Piece::Color Game::color() const
{
    return m_color;
}

void Game::connectToServer()
{
    m_socket.connect(sf::IpAddress::LocalHost, 9034);
}

void Game::sendMoves(const std::pair<short, short> &dst, const std::pair<short, short> &src)
{
    sf::Packet packet;
    packet << Message(dst, src);
    m_socket.send(packet);
}