#ifndef PLAYER
#define PLAYER

#include "Pieces/Piece.hpp"
#include <string>

class Player
{
public:
    Player(const std::string &name, const Piece::Color color);
    
    short pts() const;
    void updatePts(const short increment);

private:
    std::string m_name;
    short m_pts;
    Piece::Color m_color;
};

#endif //PLAYER