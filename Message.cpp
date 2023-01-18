#include "Message.hpp"

Message::Message()
{
}

Message::Message(const std::pair<sf::Int16, sf::Int16> &dst, const std::pair<sf::Int16, sf::Int16> &src) :
    m_dst(dst),
    m_src(src)
{
}

sf::Packet& operator <<(sf::Packet &packet, const Message &msg)
{
    return packet << msg.m_dst.first << msg.m_dst.second << msg.m_src.first << msg.m_src.second;
}

sf::Packet& operator >>(sf::Packet &packet, Message &msg)
{
    return packet >> msg.m_dst.first >> msg.m_dst.second >> msg.m_src.first >> msg.m_src.second;
}