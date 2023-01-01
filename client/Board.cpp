#include "Board.hpp"
#include "Pieces/Pawn.hpp"
#include "Pieces/Castle.hpp"
#include "Pieces/Knight.hpp"
#include "Pieces/Bishop.hpp"
#include "Pieces/Queen.hpp"
#include "Pieces/King.hpp"

#include <SFML/Graphics.hpp>

Board::Board()
{
    m_startPos = sf::Vector2f(678, 258);

    int x = m_startPos.x, y = m_startPos.y;
    for (int i = 7; i >= 0; --i) {
        for (int j = 0; j < 8; ++j) {     
            m_board[j][i] = new Square(i, j, (i + j) % 2 ? sf::Color(60, 179, 113) : sf::Color::White, sf::Vector2f(50, 50), sf::Vector2f(x, y));
            x += 50;
        }
        y += 50;
        x = m_startPos.x;
    }
    
    m_highlightedSquare = nullptr;
    populateBoard();
}

void Board::populateBoard()
{
    /* pawns */
    for (int i = 0; i < 8; ++i) {
        new Pawn(Piece::White, m_board[i][1]);
        new Pawn(Piece::Black, m_board[i][6]);
    }

    /* castles */
    new Castle(Piece::Black, m_board[7][7]);
    new Castle(Piece::Black, m_board[0][7]);
    new Castle(Piece::White, m_board[0][0]);
    new Castle(Piece::White, m_board[7][0]);

    /* knights */
    new Knight(Piece::Black, m_board[1][7]);
    new Knight(Piece::Black, m_board[6][7]);
    new Knight(Piece::White, m_board[1][0]);
    new Knight(Piece::White, m_board[6][0]);

    /* bishops */
    new Bishop(Piece::Black, m_board[2][7]);
    new Bishop(Piece::Black, m_board[5][7]);
    new Bishop(Piece::White, m_board[2][0]);
    new Bishop(Piece::White, m_board[5][0]);

    /* queens */
    new Queen(Piece::Black, m_board[4][7]);
    new Queen(Piece::White, m_board[4][0]);

    /* kings */
    new King(Piece::Black, m_board[3][7]);
    new King(Piece::White, m_board[3][0]);
}

void Board::draw(sf::RenderWindow &window)
{
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            m_board[i][j]->draw(window);
        }
    }
}

void Board::handleMouseEvt(const sf::Vector2f &pos)
{
    std::pair<short, short> indices = posToIndices(pos);
    dehighlightSquares();
    if (indices.first != -1 && indices.second != -1 && !m_board[indices.first][indices.second]->isEmpty()) {
        m_highlightedSquare = m_board[indices.first][indices.second];
        m_highlightedSquare->piece()->generateMoves(*this);
        m_highlightedSquares = m_highlightedSquare->piece()->moves();
        highlightSquares();
    }
}

std::pair<short, short> Board::posToIndices(const sf::Vector2f &pos)
{
    const float x = pos.x;
    const float y = pos.y;
    const float sqSize = 50;

    /* if it wasn't the board's area that was clicked, return values to signify it */
    if (x < m_startPos.x || x > m_startPos.x + 8 * sqSize || y < m_startPos.y || y > m_startPos.y + 8 * sqSize) {
        return std::pair<short, short>(-1, -1);
    }

    short rank = 7 - (int)((y - m_startPos.y) / sqSize);
    short file = (x - m_startPos.x) / sqSize;
    return std::pair<short, short>(file, rank);
}

void Board::highlightSquares()
{
    if (m_highlightedSquare) {
        m_highlightedSquare->setFillColor(sf::Color::Cyan);
    }
    for (int i = 0; i < m_highlightedSquares.size(); ++i) {
        m_highlightedSquares[i]->setFillColor(sf::Color::Yellow);
    }
}

void Board::dehighlightSquares()
{
    dehighlight(m_highlightedSquare);
    for (int i = 0; i < m_highlightedSquares.size(); ++i) {
        dehighlight(m_highlightedSquares[i]);
    }
    m_highlightedSquares.clear();
}

void Board::dehighlight(Square *square)
{
    if (square) {
        square->setFillColor(square->color());
    }
}