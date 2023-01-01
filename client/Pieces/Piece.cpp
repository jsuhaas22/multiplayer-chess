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
    setPosition(m_square->pos());
    setScale(0.05, 0.05);

    m_isAlive = true;
    m_square->setPiece(this);
}

void Piece::move(Square *square)
{
    setSquare(square);
}

void Piece::draw(sf::RenderWindow &window)
{
    window.draw(*this);
}

void Piece::setSquare(Square *square)
{
    m_square = square;
    m_square->setPiece(this);
    setPosition(m_square->pos());
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