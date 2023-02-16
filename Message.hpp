#ifndef MESSAGE
#define MESSAGE

#include <SFML/Network.hpp>

class Message
{
public:
    Message();
    Message(const std::pair<sf::Int16, sf::Int16> &dst, const std::pair<sf::Int16, sf::Int16> &src);

    /* m_type:
     * 1: moves
     * 2: other player has connected (and the game may begin)
     * 3: other player has disconnected (and the game thus ends)
     * 4: you have disconnected (and the game thus ends)
     */
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