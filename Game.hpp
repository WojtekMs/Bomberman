#pragma once

#include "Board.hpp"
#include "Player.hpp"
#include "Game.hpp"

enum class GAME_STATE {
    WON,
    LOST
};

class Game {
    Player& player_;
    Board& board_;
    public:
    Game(Board& b, Player& p);
};
