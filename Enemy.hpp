#pragma once
#include "Movable.hpp"

class Enemy :public Movable {
    float totalElapsedTime{0};
    public:
    Enemy(Board& board, int col, int row);
    void move(sf::Time elapsedTime);

};
