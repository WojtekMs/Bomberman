#include "GameView.hpp"

#include "Board.hpp"
#include "Enemy.hpp"
#include "Player.hpp"

#include <iostream>

GameView::GameView(Board& b, Player& p, std::vector<Enemy*>& e) :
    board_(b), player_(p), enemies_(e), pathToTextures("img/")
{
    loadEnemyTexture();
    loadPlayerTextures();
    loadExplosionTextures();
    textureBomb_.loadFromFile(pathToTextures + "bomb.png");
    gameOverTexture_.loadFromFile(pathToTextures + "game_over.png");

    setPlayerSprites();
    spriteBomb_.setTexture(textureBomb_);
    spriteExplosionHorizontal_.setTexture(textureExplosionHorizontal_);
    spriteExplosionVertical_.setTexture(textureExplosionVertical_);
    enemySprite_.setTexture(enemyTexture_);
    gameOverSprite_.setTexture(gameOverTexture_);
}

void GameView::loadEnemyTexture()
{
    auto enemyTextureName = "monkey.png";
    if (!enemyTexture_.loadFromFile(pathToTextures + enemyTextureName)) {
        std::cerr << "texture " << enemyTextureName << " could not be loaded!\n";
        exit(0);
    }
}

void GameView::loadPlayerTextures()
{
    auto playerUp{"playerUp.PNG"};
    auto playerDown{"playerDown.PNG"};
    auto playerLeft{"playerLeft.PNG"};
    auto playerRight{"playerRight.PNG"};

    textureUp_.loadFromFile(pathToTextures + playerUp);
    textureDown_.loadFromFile(pathToTextures + playerDown);
    textureLeft_.loadFromFile(pathToTextures + playerLeft);
    textureRight_.loadFromFile(pathToTextures + playerRight);
}

void GameView::loadExplosionTextures()
{
    textureExplosionVertical_.loadFromFile(pathToTextures + "boom_pionowo.png");
    textureExplosionHorizontal_.loadFromFile(pathToTextures + "boom_poziomo.png");
}

void GameView::setPlayerSprites()
{
    spriteUp_.setTexture(textureUp_);
    spriteDown_.setTexture(textureDown_);
    spriteLeft_.setTexture(textureLeft_);
    spriteRight_.setTexture(textureRight_);
}

void GameView::drawBoard(sf::RenderWindow& win)
{
    auto wall = board_.getWallSprite();
    auto wallSize = 32;
    win.draw(board_.getMapSprite());
    for (int row = 0; row < board_.getHeight(); ++row) {
        for (int col = 0; col < board_.getWidth(); ++col) {
            if (board_.getField(col, row).isWall) {
                wall.setScale(0.5f, 0.5f);
                wall.setPosition(col * wallSize, row * wallSize);
                win.draw(wall);
            }
        }
    }
}

void GameView::drawEnemies(sf::RenderWindow& win)
{
    auto enemySize = 32;
    for (auto enemy : enemies_) {
        enemy->getSprite().setPosition(enemy->getCol() * enemySize, enemy->getRow() * enemySize);
        win.draw(enemy->getSprite());
    }
}

void GameView::drawBomb(sf::RenderWindow& win)
{
    auto spriteBomb = player_.getBombSprite();
    auto bombSize = 32;
    spriteBomb.setScale(0.65f, 0.65f);
    spriteBomb.setPosition(player_.getBomb().getCol() * bombSize, player_.getBomb().getRow() * bombSize);
    win.draw(spriteBomb);
}

void GameView::drawPlayer(sf::RenderWindow& win)
{
    auto playerSprite = getPlayerSprite();
    auto playerSize = 32;
    playerSprite.setScale(0.65f, 0.65f);
    playerSprite.setPosition(player_.getCol() * playerSize, player_.getRow() * playerSize);
    win.draw(playerSprite);
}

sf::Sprite& GameView::getPlayerSprite()
{
    switch (player_.getCurrentDirection()) {
        case Direction::UP:
            return spriteUp_;
            break;
        case Direction::DOWN:
            return spriteDown_;
            break;
        case Direction::LEFT:
            return spriteLeft_;
            break;
        case Direction::RIGHT:
            return spriteRight_;
    }
}

void GameView::drawGameOver(sf::RenderWindow& win)
{
    win.draw(gameOverSprite_);
}

void GameView::drawExplosion(sf::RenderWindow& win)
{
    auto explosionSize = 32;
    auto explosionHorizontalOffset = player_.getBomb().getCol() - 2.5;
    auto explosionVeritcalOffset = player_.getBomb().getRow() - 2.5;
    spriteExplosionHorizontal_.setScale(0.65f, 0.65f);
    spriteExplosionHorizontal_.setPosition(explosionHorizontalOffset * explosionSize, player_.getBomb().getRow() * explosionSize);
    spriteExplosionVertical_.setScale(0.65f, 0.65f);
    spriteExplosionVertical_.setPosition(player_.getBomb().getCol() * explosionSize, explosionVeritcalOffset * explosionSize);
    win.draw(spriteExplosionHorizontal_);
    win.draw(spriteExplosionVertical_);
}
