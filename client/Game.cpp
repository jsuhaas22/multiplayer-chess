#include "Game.hpp"
#include "../Message.hpp"
#include <SFML/Network.hpp>
#include <iostream>

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
            sf::Packet packet;
            if (evt.type == sf::Event::MouseButtonPressed && m_isTurn) {
                m_board.handleMouseEvt(sf::Vector2f(evt.mouseButton.x, evt.mouseButton.y));
            } else if (m_socket.receive(packet) == sf::Socket::Done) {
                Message m;
                packet >> m;
                m_board.playMove(m);
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
    if (m_socket.connect(sf::IpAddress::LocalHost, 9034) != sf::Socket::Done) {
        // TODO: add a dialog here later
        std::cout << "Couldn't connect to server. Exiting." << std::endl;
        exit(1);
    }
    m_socket.setBlocking(false);
}

void Game::sendMoves(const std::pair<short, short> &dst, const std::pair<short, short> &src)
{
    sf::Packet packet;
    packet << Message(dst, src);
    m_socket.send(packet);
}