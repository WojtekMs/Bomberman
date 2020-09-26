#pragma once
#include <SFML/Graphics.hpp>

#include "Bomb.hpp"
#include "Movable.hpp"

class Board;


class Player :public Movable {
    bool isBombPlaced_{false};
    Bomb bomb_;

    sf::Texture textureLeft_;
    sf::Texture textureRight_;
    sf::Texture textureUp_;
    sf::Texture textureDown_;
    
    sf::Sprite spriteLeft_;
    sf::Sprite spriteRight_;
    sf::Sprite spriteUp_;
    sf::Sprite spriteDown_;

    sf::Texture textureBomb_;
    sf::Sprite spriteBomb_;

    public:
    Player(Board& board, int col, int row);
    void placeBomb();
    bool isBombPlaced() const { return isBombPlaced_; }

    Bomb& getBomb()  { return bomb_; }

    void draw(Direction dir, sf::RenderWindow& win);
    void updateIsBombPlaced(sf::Time elapsedTime);
    void drawBomb(sf::RenderWindow& win);
};
