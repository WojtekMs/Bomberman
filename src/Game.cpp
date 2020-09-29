#include "Game.hpp"



Game::Game() :
    board_(19, 25),
    player_(board_, 11, 10),
    enemies_({std::make_shared<Enemy>(board_, 1, 1),
              std::make_shared<Enemy>(board_, 23, 1),
              std::make_shared<Enemy>(board_, 1, 17),
              std::make_shared<Enemy>(board_, 23, 17)}),
    ctrl_(board_, player_, enemies_),
    view_(board_, player_, enemies_),
    window_(sf::VideoMode(800, 608), "Bomberman")
{
}

void Game::run()
{
    while (window_.isOpen()) {
        sf::Event event;
        while (window_.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window_.close();
            }
            ctrl_.handleEvents(event);
        }
        ctrl_.updateGame();
        window_.clear();
        if (ctrl_.getGameState() == GAME_STATE::LOST) {
            view_.drawGameOver(window_);
            window_.display();
            continue;
        }
        view_.drawBoard(window_);
        if (ctrl_.isBombPlaced()) {
            view_.drawBomb(window_);
        }
        view_.drawPlayer(window_);
        view_.drawEnemies(window_);
        if (ctrl_.isExplosion()) {
            ctrl_.removeEnemies();
            view_.drawExplosion(window_);
        }
        window_.display();
    }
}
