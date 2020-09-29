#pragma once
#include <SFML/Graphics.hpp>

#include "Bomb.hpp"
#include "Movable.hpp"

class Board;


class Player :public Movable {
    Bomb bomb_;

    public:
    Player(Board& board, int col, int row);
    void placeBomb();
    Bomb& getBomb()  { return bomb_; }
};
