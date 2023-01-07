#ifndef PIECE
#define PIECE

#include "../Square.hpp"
#include "../Board.hpp"
#include <SFML/Graphics.hpp>

class Piece : public sf::Sprite
{
public:
    enum Color {
        White,
        Black
    };
    enum Type {
        Pawn,
        Castle,
        Knight,
        Bishop,
        Queen,
        King
    };

    Piece(Square *square, Color color, Type type, std::string path, int pts);

    virtual void generateMoves(Board &board) = 0;
    virtual void move(Square *square); /* sets the square, mostly. exception: King, Castle and Pawn. addl op req'd. */
    void draw(sf::RenderWindow &window);
    void setSquare(Square *square); /* for King, Castle and Pawn to set m_square in their impl. of move() */
    void addInfluenceSq(Square *square);

    Square *square();
    Color color() const;
    Type type() const;
    int pts() const;
    bool isAlive() const;
    std::vector<Square*> moves();\
    bool squareExists(const short file, const short rank) const;

    std::vector<Square*> m_moves;
    std::vector<Square*> m_influences;

private:
    Square *m_square; /* square it is currently on */
    Color m_color;
    Type m_type;
    int m_pts; /* points it is worth */
    sf::Texture m_texture;
    bool m_isAlive;
};

#endif //PIECE