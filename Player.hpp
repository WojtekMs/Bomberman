#pragma once

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
};
