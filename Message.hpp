#ifndef MESSAGE
#define MESSAGE

#include <SFML/Network.hpp>

class Message
{
public:
    Message(const std::pair<sf::Int16, sf::Int16> &dst, const std::pair<sf::Int16, sf::Int16> &src);
    
    friend sf::Packet operator <<(sf::Packet &packet, const Message &msg);
    friend sf::Packet operator >>(sf::Packet &packet, Message &msg);

private:
    std::pair<sf::Int16, sf::Int16> m_dst;
    std::pair<sf::Int16, sf::Int16> m_src;
};

#endif //MESSAGE