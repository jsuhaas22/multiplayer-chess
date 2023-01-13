#ifndef SERVER
#define SERVER

#include <SFML/Network.hpp>

class Server
{
public:
    Server();
    void runServer();

private:
    sf::TcpListener m_listener;
    std::vector<sf::TcpSocket*> m_clients;

    const int m_port = 9034;
};

#endif //SERVER