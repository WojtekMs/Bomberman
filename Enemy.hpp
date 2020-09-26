#pragma once
#include "Movable.hpp"

class Player;
class Enemy :public Movable {
    float totalElapsedTime{0};
    sf::Texture enemyTexture_;
    sf::Sprite enemySprite_;
    public:
    Enemy(Board& board, int col, int row);
    void move(sf::Time elapsedTime, Player& player);
    void draw(sf::RenderWindow& win);

};
