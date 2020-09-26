#pragma once

#include "Board.hpp"

enum class Direction { LEFT, UP, DOWN, RIGHT };
class Movable {
    protected:
    int col_{5};
    int row_{5};
    Board& board_;
    Direction currentDirection_{Direction::RIGHT};

   public:
    Movable(Board& board, int col, int row, Direction dir = Direction::RIGHT);
    virtual void moveUp();
    virtual void moveDown();
    virtual void moveLeft();
    virtual void moveRight();
    virtual ~Movable() = default;
    Direction getCurrentDirection() const { return currentDirection_; }
    int getCol() const { return col_; }
    int getRow() const { return row_; }

};
