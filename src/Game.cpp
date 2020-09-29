#include "Game.hpp"

Game::Game(GameController& gc, GameView& gv, sf::RenderWindow& win) 
:ctrl_(gc), view_(gv), window_(win) {

}

void Game::run() {
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
