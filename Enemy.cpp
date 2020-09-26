#include "Enemy.hpp"
#include <iostream>

Enemy::Enemy(Board& board, int col, int row) :Movable(board, col, row) {

}

void Enemy::move(sf::Time elapsedTime) {
    totalElapsedTime += elapsedTime.asSeconds();
    std::cout << Movable::getCol() << ", " << Movable::getRow() << '\n';
    if (totalElapsedTime > 0.5) {
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
