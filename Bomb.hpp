#pragma once

class Bomb {
    int col_{-1};
    int row_{-1};
    int firePower_{2};
    int timeToBlow_{3};

    public:
    Bomb(int col, int row);
    int getCol() const { return col_; }
    int getRow() const { return row_; }
    int getFirePower() const { return firePower_; }
    int getTimeToBlow() const { return timeToBlow_; }
    void blow();
};
