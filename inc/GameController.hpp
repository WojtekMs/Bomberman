#pragma once

#include "Board.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include <SFML/Graphics.hpp>

enum class GAME_STATE {
    WON,
    LOST,
    IN_PROGRESS,
};

class GameController {
    Player& player_;
    Board& board_;
    std::vector<Enemy*> enemies_;
    // Enemy& enemy_;
    sf::Clock bombClock_;
    sf::Clock enemyMoveClock_;
    bool isClockResetted_{false};
    GAME_STATE currentGameState{GAME_STATE::IN_PROGRESS};
    public:
    GameController(Board& b, Player& p, std::vector<Enemy*>& e);
    void handleEvents(sf::Event& event);
    bool checkIfBombBlow();
    void moveEnemies();
    void removeEnemies();
    bool playerIsInBombRange();
    void updateGameState();
    GAME_STATE getGameState() { return currentGameState; }
};
