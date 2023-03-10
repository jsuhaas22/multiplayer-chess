#ifndef SQUARE
#define SQUARE

#include <SFML/Graphics.hpp>
#include <vector>

class Piece;

class Square : public sf::RectangleShape
{
public:
    Square();
    Square(short rank, short file, sf::Color color, const sf::Vector2f &size, const sf::Vector2f pos);
    
    Piece* piece();
    sf::Color color();
    sf::Vector2f pos() const;
    short rank() const;
    short file() const;
    std::pair<short, short> position() const;
    bool isEmpty() const;
    bool isHighlighted() const;

    void setPiece(Piece *piece);
    void setRankFile(short rank, short file);
    void setColor(sf::Color color);
    void delPiece();
    void addPiece(Piece *p);

    void draw(sf::RenderWindow &window);

    std::vector<Piece*> m_pieces; /* pieces that can strike at the square */

private:
    Piece *m_piece; /* piece currently on it */
    sf::Color m_color; /* colour of the square */
    short m_rank;
    short m_file;
    sf::Vector2f m_pos;
};

#endif