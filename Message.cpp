#include "Message.hpp"

Message::Message()
{
}

Message::Message(const std::pair<sf::Int16, sf::Int16> &dst, const std::pair<sf::Int16, sf::Int16> &src) :
    m_dst(dst),
    m_src(src)
{
}

void Message::fillMessage(const short type, const std::string &content)
{
    m_type = type;
    m_content = content;
    m_src = m_dst = std::pair(-1, -1);
}

void Message::fillMessage(const short type, const std::pair<short, short> &src, const std::pair<short, short> &dst)
{
    m_type = type;
    m_content = "";
    m_src = src;
    m_dst = dst;
}

void Message::fillMessage(const short type, const std::string &content, const std::pair<short, short> &src, const std::pair<short, short> &dst)
{
    m_type = type;
    m_content = content;
    m_src = src;
    m_dst = dst;
}

bool Message::fillPacket(sf::Packet &packet)
{
    return packet << m_type << m_content << m_src.first << m_src.second << m_dst.first << m_dst.second;
}

bool Message::extractPacket(sf::Packet &packet)
{
    return packet >> m_type >> m_content >> m_src.first >> m_src.second >> m_dst.first >> m_dst.second;
}