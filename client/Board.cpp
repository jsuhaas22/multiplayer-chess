#include "Board.hpp"
#include "Game.hpp"
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
    m_game = nullptr;
    // populateBoard();
}

void Board::populateBoard()
{
    Piece::Color thisColor = m_game->color();
    Piece::Color oppColor = thisColor == Piece::White ? Piece::Black : Piece::White;

    /* pawns */
    for (int i = 0; i < 8; ++i) {
        new Pawn(thisColor, m_board[i][1]);
        new Pawn(oppColor, m_board[i][6]);
    }

    /* castles */
    new Castle(oppColor, m_board[7][7]);
    new Castle(oppColor, m_board[0][7]);
    new Castle(thisColor, m_board[0][0]);
    new Castle(thisColor, m_board[7][0]);

    /* knights */
    new Knight(oppColor, m_board[1][7]);
    new Knight(oppColor, m_board[6][7]);
    new Knight(thisColor, m_board[1][0]);
    new Knight(thisColor, m_board[6][0]);

    /* bishops */
    new Bishop(oppColor, m_board[2][7]);
    new Bishop(oppColor, m_board[5][7]);
    new Bishop(thisColor, m_board[2][0]);
    new Bishop(thisColor, m_board[5][0]);

    /* queens */
    new Queen(oppColor, m_board[4][7]);
    new Queen(thisColor, m_board[4][0]);

    /* kings */
    new King(oppColor, m_board[3][7]);
    new King(thisColor, m_board[3][0]);

    /* initialize legal moves for each piece */
    for (int i = 0; i < 8; ++i) {
        m_board[i][0]->piece()->generateMoves(*this);
        m_board[i][1]->piece()->generateMoves(*this);
        m_board[i][7]->piece()->generateMoves(*this);
        m_board[i][6]->piece()->generateMoves(*this);
    }
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

    /* click was outside the board area */
    if (indices.first == -1 && indices.second == -1) {
        return;
    }

    /* click was on a square with a piece when no piece is already selected */
    if (!m_highlightedSquare && !m_board[indices.first][indices.second]->isEmpty()) {
        if (m_board[indices.first][indices.second]->piece()->color() != m_game->color()) {
            return;
        }
        m_highlightedSquare = m_board[indices.first][indices.second];
        // m_highlightedSquare->piece()->generateMoves(*this);
        m_highlightedSquares = m_highlightedSquare->piece()->moves();
        highlightSquares();
        return;
    }
    
    /* click was on a square that is a potential destination for selected piece */
    if (m_highlightedSquare && m_board[indices.first][indices.second]->isHighlighted() && m_highlightedSquare != m_board[indices.first][indices.second]) {
        if (!m_board[indices.first][indices.second]->isEmpty() && m_board[indices.first][indices.second]->piece()->color() != m_highlightedSquare->piece()->color()) {
            // m_game->pwhite()->updatePts(m_board[indices.first][indices.second]->piece()->pts());
            m_board[indices.first][indices.second]->delPiece();
        }
        m_highlightedSquare->piece()->move(m_board[indices.first][indices.second]);
        m_highlightedSquare->setPiece(nullptr);
        generateMoves(indices);
        generateMoves(std::pair<short, short>(m_highlightedSquare->file(), m_highlightedSquare->rank()));
        m_game->sendMoves(indices, m_highlightedSquare->position());

    }
    dehighlightSquares();
    m_highlightedSquare = nullptr;
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

void Board::setGame(Game *game)
{
    m_game = game;
}

void Board::generateMoves(const std::pair<short, short> &indices)
{
    std::vector<int> toRemove;
    Square *sq = m_board[indices.first][indices.second];
    for (int i = 0; i < sq->m_pieces.size(); ++i) {
        sq->m_pieces[i]->generateMoves(*this);
        if (!sq->m_pieces[i]->squareExists(sq->file(), sq->rank())) {
            toRemove.push_back(i);
        }
    }
    for (int i = toRemove.size() - 1; i >= 0; --i) {
        sq->m_pieces.erase(sq->m_pieces.begin() + toRemove[i]);
    }
}

void Board::playMove(Message m)
{
    m_board[m.m_src.first][m.m_src.second]->piece()->move(m_board[m.m_dst.first][m.m_dst.second]);
    m_board[m.m_src.first][m.m_src.second]->setPiece(nullptr);
    generateMoves(m.m_src);
    generateMoves(m.m_dst);
}