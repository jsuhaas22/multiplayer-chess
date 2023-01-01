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
    void draw(sf::RenderWindow &window);

    Square *square();
    Color color() const;
    Type type() const;
    int pts() const;
    bool isAlive() const;
    std::vector<Square*> moves();

    std::vector<Square*> m_moves;

private:
    Square *m_square; /* square it is currently on */
    Color m_color;
    Type m_type;
    int m_pts; /* points it is worth */
    sf::Texture m_texture;
    bool m_isAlive;
};

#endif //PIECE