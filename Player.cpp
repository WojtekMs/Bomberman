#include "Player.hpp"
#include "Board.hpp"

#include <iostream>

Player::Player(Board& board, int col, int row)
    : board_(board), col_(col), row_(row) {
    textureUp_.loadFromFile("img/playerUp.PNG");
    spriteUp_.setTexture(textureUp_);
    textureDown_.loadFromFile("img/playerDown.PNG");
    spriteDown_.setTexture(textureDown_);
    textureLeft_.loadFromFile("img/playerLeft.PNG");
    spriteLeft_.setTexture(textureLeft_);
    textureRight_.loadFromFile("img/playerRight.PNG");
    spriteRight_.setTexture(textureRight_);
}

void Player::moveUp() {
    if (board_.getField(col_, row_ - 1).isWall) {
        return;
    }
    row_--;
    currentDirection_ = Direction::UP;
}

void Player::moveDown() {
    std::cout << row_ << '\n';
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
    std::cout << col_ << '\n';
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

void Player::draw(Direction dir, sf::RenderWindow& win) {
    sf::Sprite* ptr = nullptr;
    switch (dir) {
    case Direction::UP:
        ptr = &spriteUp_;
        break;
    case Direction::DOWN:
        ptr = &spriteDown_;
        break;
    case Direction::LEFT:
        ptr = &spriteLeft_;
        break;
    case Direction::RIGHT:
        ptr = &spriteRight_;
    }
    ptr->setPosition(col_ * 32, row_ * 32);
    win.draw(*ptr);
}

void Player::updateIsBombPlaced(sf::Time elapsedTime) {
    if (elapsedTime.asSeconds() >= bomb_.getTimeToBlow()) {
        isBombPlaced_ = false;
    }
}
