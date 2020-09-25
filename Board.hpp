#pragma once

struct Field {
    bool isWall;
};

class Board {
    
    int height_;
    int width_;
    Field board_[50][50];
    public:
    Board(int height, int width);
    int getHeight() { return height_; }
    int getWidth() { return width_; }
    Field getField(int col, int row) { return board_[row][col]; }

};
