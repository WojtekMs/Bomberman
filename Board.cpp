#include "Board.hpp"

Board::Board(int height, int width)
:height_(height), width_(width) {
    for (int row = 0; row < width_; ++row) {
        for (int col = 0; col < height_; ++col) {
            if(col == 0 || col == height_ - 1) {
                board_[row][col].isWall = true;
            } else if (row == 0 || row == width_ - 1) {
                board_[row][col].isWall = true;
            } else {
                board_[row][col].isWall = false;
            }
        }
    }
}
