#include "GameController.hpp"
#include <iostream>

GameController::GameController(Board& board, Player& player) : board_(board), player_(player) {
}

void GameController::handleEvents(sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::W) {
            player_.moveUp();
        }
        if (event.key.code == sf::Keyboard::A) {
            player_.moveLeft();
        }
        if (event.key.code == sf::Keyboard::S) {
            player_.moveDown();
        }
        if (event.key.code == sf::Keyboard::D) {
            player_.moveRight();
        }
        if (event.key.code == sf::Keyboard::Space) {
            player_.placeBomb();
            if (!isClockResetted_) {
                clock_ = sf::Clock();
                isClockResetted_ = true;
            }
            
            //after 3 sekundy
            //bum
        }
    }
}

void GameController::checkBombBlow() {
    if (!player_.isBombPlaced()) {
        return;
    }
    auto elapsedTime = clock_.getElapsedTime();
    player_.updateIsBombPlaced(elapsedTime);
    if (elapsedTime.asSeconds() >= player_.getBomb().getTimeToBlow()) {
        
        std::cout << "BOOM!\n";
        isClockResetted_ = false;
    }

}
