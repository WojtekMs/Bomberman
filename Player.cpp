#include "Player.hpp"
#include "Board.hpp"

Player::Player(Board& board, int col, int row)
    : board_(board),
      col_(col),
      row_(row) {
}

void Player::moveUp() {
    if (board_.getField(col_, row_ - 1).isWall) {
        return;
    }
    row_--;
}

void Player::moveDown() {
    if (board_.getField(col_, row_ + 1).isWall) {
        return;
    }
    row_++;
}

void Player::moveLeft() {
    if (board_.getField(col_ - 1, row_).isWall) {
        return;
    }
    col_--;
}

void Player::moveRight() {
    if (board_.getField(col_ + 1, row_).isWall) {
        return;
    }
    col_++;
}

void Player::placeBomb() {
    
}
