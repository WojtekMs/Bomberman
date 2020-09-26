#include "Movable.hpp"

Movable::Movable(Board& board, int col, int row, Direction dir) : board_(board), col_(col), row_(row), currentDirection_(dir) {
}

void Movable::moveUp() {
    if (board_.getField(col_, row_ - 1).isWall) {
        return;
    }
    row_--;
    currentDirection_ = Direction::UP;
}

void Movable::moveDown() {
    if (board_.getField(col_, row_ + 1).isWall) {
        return;
    }
    row_++;
    currentDirection_ = Direction::DOWN;
}

void Movable::moveLeft() {
    if (board_.getField(col_ - 1, row_).isWall) {
        return;
    }
    col_--;
    currentDirection_ = Direction::LEFT;
}

void Movable::moveRight() {
    if (board_.getField(col_ + 1, row_).isWall) {
        return;
    }
    col_++;
    currentDirection_ = Direction::RIGHT;
}
