#ifndef SQUARE
#define SQUARE

#include <SFML/Graphics.hpp>

#include <vector>

class Piece;

class Square : public sf::RectangleShape
{
    public:
    Square();
    Square(unsigned short rank, unsigned short file, sf::Color color, const sf::Vector2f &size);
    
    Piece* piece();
    sf::Color color();

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
};

#endif