#include "Piece.hpp"

Piece::Piece(Square *square, Piece::Color color, Piece::Type type, std::string path, int pts) :
    sf::Sprite(),
    m_square(square),
    m_color(color),
    m_type(type),
    m_pts(pts)
{
    m_texture.loadFromFile(path);
    setTexture(m_texture);

    m_isAlive = true;
}

Square* Piece::square()
{
    return m_square;
}

Piece::Color Piece::color() const
{
    return m_color;
}

Piece::Type Piece::type() const
{
    return m_type;
}

int Piece::pts() const
{
    return m_pts;
}

std::vector<Square*> Piece::moves()
{
    return m_moves;
}