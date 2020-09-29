#pragma once

#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>

#include "Board.hpp"
#include "Enemy.hpp"
#include "GameController.hpp"
#include "GameView.hpp"
#include "Player.hpp"

class Game
{
    Board board_;
    Player player_;
    std::vector<std::shared_ptr<Enemy>> enemies_;
    GameController ctrl_;
    GameView view_;
    sf::RenderWindow window_;

   public:
    Game();
    void run();
};
