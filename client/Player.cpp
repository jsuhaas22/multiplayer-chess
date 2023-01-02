#include "Player.hpp"

Player::Player(const std::string &name, const Piece::Color color) :
    m_name(name),
    m_pts(0),
    m_color(color)
{
}

short Player::pts() const
{
    return m_pts;
}

void Player::updatePts(const short increment)
{
    m_pts += increment;
}