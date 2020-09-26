#pragma once

#include "Board.hpp"
#include "Player.hpp"
#include <SFML/Graphics.hpp>

enum class GAME_STATE {
    WON,
    LOST
};

class GameController {
    Player& player_;
    Board& board_;
    public:
    GameController(Board& b, Player& p);
    void handleEvents(sf::Event& event);
};
