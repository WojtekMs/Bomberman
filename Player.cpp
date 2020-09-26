#include "Player.hpp"
#include "Board.hpp"

Player::Player(Board& board, int col, int row) : board_(board), col_(col), row_(row) {
}

void Player::moveUp() {
    if (board_.getField(col_, row_ - 1).isWall) {
        return;
    }
    row_--;
    currentDirection_ = Direction::UP;
}

void Player::moveDown() {
    if (board_.getField(col_, row_ + 1).isWall) {
        return;
    }
    row_++;
    currentDirection_ = Direction::DOWN;
}

void Player::moveLeft() {
    if (board_.getField(col_ - 1, row_).isWall) {
        return;
    }
    col_--;
    currentDirection_ = Direction::LEFT;
}

void Player::moveRight() {
    if (board_.getField(col_ + 1, row_).isWall) {
        return;
    }
    col_++;
    currentDirection_ = Direction::RIGHT;
}

void Player::placeBomb() {
    if (isBombPlaced_) {
        return;
    }
    bomb_ = Bomb(col_, row_);
    isBombPlaced_ = true;
}

void Player::updateIsBombPlaced(sf::Time elapsedTime) {
    if (elapsedTime.asSeconds() >= bomb_.getTimeToBlow()) {
        isBombPlaced_ = false;
    }
}
