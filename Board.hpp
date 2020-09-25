#pragma once
#include <SFML/Graphics.hpp>


struct Field {
    bool isWall;
};

class Board {
private:    
    int height_;
    int width_;
    Field board_[50][50];
    sf::Texture texture_;
    sf::Sprite map_;

    void draw(int height, int width);

public:
    Board(int height, int width);
    int getHeight() { return height_; }
    int getWidth() { return width_; }
    Field getField(int col, int row) { return board_[row][col]; }
    sf::Sprite getSprite() const;

};
