#include "Square.hpp"
#include "Pieces/Piece.hpp"

Square::Square() : sf::RectangleShape(sf::Vector2f(0, 0))
{
    m_rank = m_file = 9; /* signifies it is not set yet */
    m_color = sf::Color::White;
    setSize(sf::Vector2f(50, 50));
}

Square::Square(short rank, short file, sf::Color color, const sf::Vector2f &size, const sf::Vector2f pos) :
    sf::RectangleShape(size),
    m_rank(rank), 
    m_file(file), 
    m_color(color),
    m_pos(pos),
    m_piece(nullptr)
{
    setFillColor(m_color);
    setPosition(m_pos);
}

Piece* Square::piece()
{
    return m_piece;
}

sf::Color Square::color()
{
    return m_color;
}

sf::Vector2f Square::pos() const
{
    return m_pos;
}

short Square::rank() const
{
    return m_rank;
}

short Square::file() const
{
    return m_file;
}

std::pair<short, short> Square::position() const
{
    return std::pair<short, short>(m_file, m_rank);
}

bool Square::isEmpty() const
{
    return m_piece == nullptr;
}

bool Square::isHighlighted() const
{
    return m_color != getFillColor();
}

void Square::setPiece(Piece *piece)
{
    m_piece = piece;
}

void Square::setRankFile(short rank, short file)
{
    m_rank = rank;
    m_file = file;
}

void Square::draw(sf::RenderWindow &window)
{
    window.draw(*this);
    if (m_piece) {
        m_piece->draw(window);
    }
}

void Square::setColor(sf::Color color)
{
    m_color = color;
    setFillColor(m_color);
}

void Square::delPiece()
{
    delete m_piece;
    m_piece = nullptr;
}

void Square::addPiece(Piece *p)
{
    for (int i = 0; i < m_pieces.size(); ++i) {
        if (m_pieces[i] == p) {
            return;
        }
    }
    m_pieces.push_back(p);
    p->addInfluenceSq(this);
}