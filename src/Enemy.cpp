#include "Enemy.hpp"
#include "Player.hpp"

Enemy::Enemy(Board& board, int col, int row) : Movable(board, col, row) {
}

void Enemy::move(sf::Time elapsedTime, Player& player) {
    totalElapsedTime += elapsedTime.asSeconds();
    if (totalElapsedTime > 0.4) {
        if (Movable::getCol() > player.getCol()) {
            Movable::moveLeft();
        } else
        if (Movable::getCol() < player.getCol()) {
            Movable::moveRight();
        } else
        if (Movable::getRow() > player.getRow()) {
            Movable::moveUp();
        } else
        if (Movable::getRow() < player.getRow()) {
            Movable::moveDown();
        }
        switch(std::rand() % 4) {
            case 0:
            Movable::moveRight();
            break;
            case 1:
            Movable::moveUp();
            break;
            case 2:
            Movable::moveDown();
            break;
            case 3:
            Movable::moveLeft();
            break;
        }
        totalElapsedTime = 0;
    }
}

void Enemy::setPosition(int col, int row) {
    col_ = col;
    row_ = row;
}
