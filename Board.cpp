#include "Board.hpp"
#include <iostream>

void Board::draw(int height, int width) {
    for (int row = 0; row < height_; ++row) {
        for (int col = 0; col < width_; ++col) {
            if(col == 0 || col == width_ - 1) {
                board_[row][col].isWall = true;
            } else if (row == 0 || row == height_ - 1) {
                board_[row][col].isWall = true;
            } else {
                board_[row][col].isWall = false;
            }
        }
    }
}

Board::Board(int height, int width)
:height_(height), width_(width) {
    draw(height_, width_);
    if (!texture_.loadFromFile("img/map.png")) {
        std::cerr << "Error :CCCCCCCCCCC\n";
    }
    map_.setTexture(texture_);
}

sf::Sprite Board::getSprite() const {
    return map_;
}
