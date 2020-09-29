#include "GameView.hpp"

#include "Board.hpp"
#include "Enemy.hpp"
#include "Player.hpp"

#include <iostream>

GameView::GameView(Board& b, Player& p, std::vector<Enemy*>& e) :
    board_(b), player_(p), enemies_(e), pathToTextures("img/")
{
    loadEnemyTexture();
}

void GameView::loadEnemyTexture()
{
    auto enemyTextureName = "monkey.png";
    if (!enemyTexture_.loadFromFile(pathToTextures + enemyTextureName)) {
        std::cerr << "texture " << enemyTextureName << " could not be loaded!\n";
        exit(0);
    }
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
    std::cout << player_.getBomb().getCol() << '\n';
    spriteBomb.setPosition(player_.getBomb().getCol() * bombSize, player_.getBomb().getRow() * bombSize);
    win.draw(spriteBomb);
}

void GameView::drawPlayer(sf::RenderWindow& win)
{
    auto playerSprite = player_.getPlayerSprite();
    auto playerSize = 32;
    playerSprite.setScale(0.65f, 0.65f);
    playerSprite.setPosition(player_.getCol() * playerSize, player_.getRow() * playerSize);
    win.draw(playerSprite);
}
