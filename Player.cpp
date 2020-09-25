#include "Player.hpp"
#include "Board.hpp"

Player::Player(Board& board, int col, int row):
board_(board),
col_(col),
row_(row) {
    
}

void Player::moveUp() {
    if (board_.getField(row_ - 1, col_).isWall) {
        return;
    }
    row_--;
}
