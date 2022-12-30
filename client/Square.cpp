#include "Square.hpp"

Square::Square() : sf::RectangleShape(sf::Vector2f(0, 0))
{
    m_rank = m_file = 9; /* signifies it is not set yet */
    m_color = sf::Color::White;
    setSize(sf::Vector2f(50, 50));
}

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

void Square::setRankFile(unsigned short rank, unsigned short file)
{
    m_rank = rank;
    m_file = file;
}

void Square::draw(sf::RenderWindow &window)
{
    window.draw(*this);
}

void Square::setColor(sf::Color color)
{
    m_color = color;
    setFillColor(m_color);
}