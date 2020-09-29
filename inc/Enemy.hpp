#pragma once
#include "Movable.hpp"

class Player;
class Enemy :public Movable {
    float totalElapsedTime{0};

    public:
    Enemy(Board& board, int col, int row);
    void move(sf::Time elapsedTime, Player& player);
    void setPosition(int col, int row);
};
