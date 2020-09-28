#include "Player.hpp"
#include "Board.hpp"

#include <iostream>

Player::Player(Board& board, int col, int row)
    : Movable(board, col, row), bomb_(3, 3) {
    textureUp_.loadFromFile("img/playerUp.PNG");
    spriteUp_.setTexture(textureUp_);
    textureDown_.loadFromFile("img/playerDown.PNG");
    spriteDown_.setTexture(textureDown_);
    textureLeft_.loadFromFile("img/playerLeft.PNG");
    spriteLeft_.setTexture(textureLeft_);
    textureRight_.loadFromFile("img/playerRight.PNG");
    spriteRight_.setTexture(textureRight_);
    textureBomb_.loadFromFile("img/bomb.png");
    spriteBomb_.setTexture(textureBomb_);
    if(!textureExplosionHorizontal_.loadFromFile("img/boom_poziomo.png")) {
        std::cerr << "error";
        exit(0);
    };
    textureExplosionVertical_.loadFromFile("img/boom_pionowo.png");
    spriteExplosionHorizontal_.setTexture(textureExplosionHorizontal_);
    spriteExplosionVertical_.setTexture(textureExplosionVertical_);

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

void Player::drawBomb(sf::RenderWindow& win) {
    spriteBomb_.setScale(0.65f, 0.65f);
    spriteBomb_.setPosition(bomb_.getCol() * 32, bomb_.getRow() * 32);
    win.draw(spriteBomb_);
}

void Player::drawExplosion(sf::RenderWindow& win) {
    spriteExplosionHorizontal_.setScale(0.65f, 0.65f);
    spriteExplosionHorizontal_.setPosition((bomb_.getCol() - 2.5) * 32, bomb_.getRow() * 32);
    spriteExplosionVertical_.setScale(0.65f, 0.65f);
    spriteExplosionVertical_.setPosition(bomb_.getCol() * 32, (bomb_.getRow() - 2.5) * 32);
    win.draw(spriteExplosionHorizontal_);
    win.draw(spriteExplosionVertical_);
    
}
