#include "Player.hpp"

#include "Board.hpp"

Player::Player(Board& board, int col, int row) : Movable(board, col, row) {}
void Player::placeBomb()
{
    bomb_ = Bomb(Movable::getCol(), Movable::getRow());
}

Bomb& Player::getBomb()
{
    return bomb_;
}
