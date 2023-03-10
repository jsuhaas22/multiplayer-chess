#include "Server.hpp"
#include "../Message.hpp"
#include <iostream>

Server::Server()
{
    m_listener.setBlocking(false);
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
        client->setBlocking(false);
        /* if a client requests connection, accept and add it*/
        if (m_listener.accept(*client) == sf::Socket::Done) {
            m_clients.push_back(client);
            std::cout << client->getRemoteAddress() << " connected" << std::endl;
        }

        /* if more than 2 players have connected, accept no more requests. FOR NOW ONLY. */
        if (m_clients.size() == 2) {
            Message m;
            m.fillMessage(2, "start");
            break;
        }
    }

    while (true) {
        for (int i = 0; i < m_clients.size(); ++i) {
            sf::Packet packet;
            if (m_clients[i]->receive(packet) == sf::Socket::Done) {
                Message m;
                if (m.extractPacket(packet)) {
                    std::cout << m.m_dst.first << m.m_dst.second << std::endl << m.m_src.first << m.m_src.second << std::endl;
                }
                for (int j = 0; j < m_clients.size(); ++j) {
                    if (j == i) continue;
                    m_clients[j]->send(packet);
                }
            }
        }
    }

    std::cout << "Exiting" << std::endl;
}