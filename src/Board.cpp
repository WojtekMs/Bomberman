#include "Board.hpp"
#include <iostream>

void Board::init(int height, int width) {
    for (int row = 0; row < height_; ++row) {
        for (int col = 0; col < width_; ++col) {
            if(col == 0 || col == width_ - 1) {
                board_[row][col].isWall = true;
            } else if (row == 0 || row == height_ - 1) {
                board_[row][col].isWall = true;
            } else if (row % 2 == 0 && col % 2 == 0) {
                board_[row][col].isWall = true;
            } else {
                board_[row][col].isWall = false;
            }
        }
    }
}

Board::Board(int height, int width)
:height_(height), width_(width) {
    init(height_, width_);
    if (!texture_map.loadFromFile("img/map.png")) {
        std::cerr << "Error :CCCCCCCCCCC\n";
    }
    map_.setTexture(texture_map);

    if (!texture_wall.loadFromFile("img/wall.png")) {
        std::cerr << "Error :CCCCCCCCCCC\n";
    }
    wall_.setTexture(texture_wall);
}

sf::Sprite Board::getSprite() const {
    return map_;
}

sf::Sprite Board::getWall() const {
    return wall_;
}

void Board::draw(sf::RenderWindow& win) {
    win.draw(map_);
    for (int row = 0; row < height_; ++row) {
        for (int col = 0; col < width_; ++col) {
            if(board_[row][col].isWall) {
                wall_.setScale(0.5f, 0.5f);
                wall_.setPosition(col * 32, row * 32);
                win.draw(wall_);
            }
        }
    }
}
