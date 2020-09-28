#pragma once

#include "GameController.hpp"
#include "GameView.hpp"

class Game {
    GameController& ctrl_;
    GameView view_;
    public:
    Game(GameController& gc, GameView& gv);
    //should have draw function and handleEvents function
};
