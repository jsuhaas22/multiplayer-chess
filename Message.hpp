#ifndef MESSAGE
#define MESSAGE

#include <SFML/Network.hpp>

class Message
{
public:
    Message();
    Message(const std::pair<sf::Int16, sf::Int16> &dst, const std::pair<sf::Int16, sf::Int16> &src);

    short m_type;
    std::string m_content;
    std::pair<sf::Int16, sf::Int16> m_dst;
    std::pair<sf::Int16, sf::Int16> m_src;

    void fillMessage(const short type, const std::string &content);
    void fillMessage(const short type, const std::pair<short, short> &src, const std::pair
    <short, short> &dst);
    void fillMessage(const short type, const std::string &content, 
    const std::pair<short, short> &src, const std::pair <short, short> &dst);

    bool fillPacket(sf::Packet &packet);
    bool extractPacket(sf::Packet &packet);
};

#endif //MESSAGE