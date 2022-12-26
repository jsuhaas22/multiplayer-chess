#include "Square.hpp"

Square::Square(unsigned short rank, unsigned short file, sf::Color color, const sf::Vector2f &size) :
    sf::RectangleShape(size),
    m_rank(rank), 
    m_file(file), 
    m_color(color)
{
    setFillColor(m_color);
}

Piece* Square::piece()
{
    return m_piece;
}

sf::Color Square::color()
{
    return m_color;
}

void Square::setPiece(Piece *piece)
{
    m_piece = piece;
}