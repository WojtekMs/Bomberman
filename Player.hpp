#pragma once

#include "Bomb.hpp"

class Board;

enum class Direction {
    LEFT,
    UP,
    DOWN,
    RIGHT
};
class Player {
    int col_{5};
    int row_{5};
    Board& board_;
    bool isBombPlaced_{false};
    Direction currentDirection_{Direction::RIGHT};
    Bomb bomb_{-1, -1};

    public:
    Player(Board& board, int col, int row);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void placeBomb();
    int getCol() const { return col_; }
    int getRow() const { return row_; }
    Direction getCurrentDirection() const { return currentDirection_; }
    const Bomb& getBomb() const { return bomb_; }
};
