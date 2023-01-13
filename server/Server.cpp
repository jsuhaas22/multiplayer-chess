#include "Server.hpp"
#include <iostream>
Server::Server()
{
}

void Server::runServer()
{
    /* bind socket to port. if error, return */
    if (m_listener.listen(m_port) != sf::Socket::Done) {
        return;
    }

    sf::TcpSocket *client;

    /* infinite loop accepting connections */
    while (true) {
        client = new sf::TcpSocket();
        /* if a client requests connection, accept and add it*/
        if (m_listener.accept(*client) == sf::Socket::Done) {
            m_clients.push_back(client);
            std::cout << client->getRemoteAddress() << " connected" << std::endl;
        }

        /* if more than 2 players have connected, accept no more requests. FOR NOW ONLY. */
        if (m_clients.size() == 2) {
            break;
        }
    }

    std::cout << "Exiting" << std::endl;
}