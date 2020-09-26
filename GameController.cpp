#include "GameController.hpp"

GameController::GameController(Board& board, Player& player) :board_(board), player_(player) {

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
    }
}
