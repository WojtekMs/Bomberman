#pragma once

#include "GameController.hpp"
#include "GameView.hpp"

class Game {
    GameController& ctrl_;
    GameView& view_;
    sf::RenderWindow& window_;
    public:
    Game(GameController& gc, GameView& gv, sf::RenderWindow& win);
    void run();
};
