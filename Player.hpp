#pragma once
#include <SFML/Graphics.hpp>

#include "Bomb.hpp"
#include "Movable.hpp"

class Board;

enum class Direction {
    LEFT,
    UP,
    DOWN,
    RIGHT
};
class Player :public Movable {
    int col_{5};
    int row_{5};
    Board& board_;
    bool isBombPlaced_{false};
    Direction currentDirection_{Direction::RIGHT};
    Bomb bomb_{-1, -1};

    sf::Texture textureLeft_;
    sf::Texture textureRight_;
    sf::Texture textureUp_;
    sf::Texture textureDown_;
    
    sf::Sprite spriteLeft_;
    sf::Sprite spriteRight_;
    sf::Sprite spriteUp_;
    sf::Sprite spriteDown_;

    public:
    Player(Board& board, int col, int row);
    void moveUp() override;
    void moveDown() override;
    void moveLeft() override;
    void moveRight() override;
    void placeBomb();
    int getCol() const { return col_; }
    int getRow() const { return row_; }
    bool isBombPlaced() const { return isBombPlaced_; }
    Direction getCurrentDirection() const { return currentDirection_; }
    const Bomb& getBomb() const { return bomb_; }
    void draw(Direction dir, sf::RenderWindow& win);
    void updateIsBombPlaced(sf::Time elapsedTime);
};
