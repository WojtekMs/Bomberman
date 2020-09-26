#include "GameController.hpp"
#include <iostream>
#include <cmath>

GameController::GameController(Board& board, Player& player, std::vector<Enemy*>& enemy) : board_(board), player_(player), enemies_(enemy) {
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
                bombClock_ = sf::Clock();
                isClockResetted_ = true;
            }
            
            //after 3 sekundy
            //bum
        }
    }
}

bool GameController::checkIfBombBlow() {
    if (!player_.isBombPlaced()) {
        return false;
    }
    auto elapsedTime = bombClock_.getElapsedTime();
    player_.updateIsBombPlaced(elapsedTime);
    if (elapsedTime.asSeconds() >= player_.getBomb().getTimeToBlow()) {
        std::cout << "BOOM!\n";
        isClockResetted_ = false;
        return true;
    }
    return false;

}

void GameController::removeEnemies() {
        auto bomb =  player_.getBomb();

          for (auto enemy : enemies_) {
            if (enemy->getRow() == bomb.getRow()) {
                if(std::abs(enemy->getCol() - bomb.getCol()) <= bomb.getFirePower()) {
                    enemy->setPosition(-1, -1);
                }
            }
            if (enemy->getCol() == bomb.getCol()) {
                if(std::abs(enemy->getRow() - bomb.getRow()) <= bomb.getFirePower()) {
                    enemy->setPosition(-1, -1);
                }
            }
        }

    
}

GAME_STATE GameController::getGameState() {
        auto bomb =  player_.getBomb();

        if (player_.getCol() == bomb.getCol() && std::abs(player_.getRow() - bomb.getRow()) <= bomb.getFirePower()) {
            return GAME_STATE::LOST;
        }
        if (player_.getRow() == bomb.getRow() && std::abs(player_.getCol() - bomb.getCol()) <= bomb.getFirePower()) {
            return GAME_STATE::LOST;
        }
        if (std::any_of(enemies_.cbegin(), enemies_.cend(), [this](Enemy* enemy)
        {
            return enemy->getCol() == player_.getCol() && enemy->getRow() == player_.getRow();
        })) {
            return GAME_STATE::LOST;
        }
}



void GameController::moveEnemies() {
    auto time = enemyMoveClock_.restart();
    for (auto enemy : enemies_) {
        enemy->move(time, player_);
    }
}
