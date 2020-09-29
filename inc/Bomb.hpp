#pragma once
#include <SFML/Graphics.hpp>

class Bomb {
    int col_{-5};
    int row_{-5};
    int firePower_{2};
    int timeToBlow_{3};

    public:
    Bomb() = default;
    Bomb(int col, int row);
    int getCol() const { return col_; }
    int getRow() const { return row_; }
    int getFirePower() const { return firePower_; }
    int getTimeToBlow() const { return timeToBlow_; }
    
};
