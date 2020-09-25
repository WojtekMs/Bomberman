#pragma once

class Board;

class Player {
    int col_;
    int row_;
    Board& board_;
    public:
    Player(Board& board, int col, int row);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    int getCol() { return col_; }
    int getRow() { return row_; }
};
