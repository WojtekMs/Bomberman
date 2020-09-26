#include "Player.hpp"
#include "Board.hpp"

#include <iostream>

Player::Player(Board& board, int col, int row)
    : Movable(board, col, row) {
    textureUp_.loadFromFile("img/playerUp.PNG");
    spriteUp_.setTexture(textureUp_);
    textureDown_.loadFromFile("img/playerDown.PNG");
    spriteDown_.setTexture(textureDown_);
    textureLeft_.loadFromFile("img/playerLeft.PNG");
    spriteLeft_.setTexture(textureLeft_);
    textureRight_.loadFromFile("img/playerRight.PNG");
    spriteRight_.setTexture(textureRight_);
}

void Player::placeBomb() {
    if (isBombPlaced_) {
        return;
    }
    bomb_ = Bomb(Movable::getCol(), Movable::getRow());
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
    ptr->setPosition(Movable::getCol() * 32, Movable::getRow() * 32);
    win.draw(*ptr);
}

void Player::updateIsBombPlaced(sf::Time elapsedTime) {
    if (elapsedTime.asSeconds() >= bomb_.getTimeToBlow()) {
        isBombPlaced_ = false;
    }
}
