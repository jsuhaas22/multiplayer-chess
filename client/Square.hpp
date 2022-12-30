#ifndef SQUARE
#define SQUARE

#include <SFML/Graphics.hpp>

#include <vector>

class Piece;

class Square : public sf::RectangleShape
{
public:
    Square();
    Square(unsigned short rank, unsigned short file, sf::Color color, const sf::Vector2f &size, const sf::Vector2f pos);
    
    Piece* piece();
    sf::Color color();
    sf::Vector2f pos() const;
    unsigned short rank() const;
    unsigned short file() const;

    void setPiece(Piece *piece);
    void setRankFile(unsigned short rank, unsigned short file);
    void setColor(sf::Color color);

    void draw(sf::RenderWindow &window);

private:
    std::vector<Piece*> m_pieces; /* pieces that can strike at the square */
    Piece *m_piece; /* piece currently on it */
    sf::Color m_color; /* colour of the square */
    unsigned short m_rank;
    unsigned short m_file;
    sf::Vector2f m_pos;
};

#endif