#ifndef MESSAGE
#define MESSAGE

#include <SFML/Network.hpp>

class Message
{
public:
    Message();
    Message(const std::pair<sf::Int16, sf::Int16> &dst, const std::pair<sf::Int16, sf::Int16> &src);
    std::pair<sf::Int16, sf::Int16> m_dst;
    std::pair<sf::Int16, sf::Int16> m_src;    
};

sf::Packet& operator <<(sf::Packet &packet, const Message &msg);
sf::Packet& operator >>(sf::Packet &packet, Message &msg);

#endif //MESSAGE