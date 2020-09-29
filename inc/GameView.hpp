#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

class Board;
class Player;
class Enemy;

class GameView {
    Board& board_;
    Player& player_;
    std::vector<Enemy*> enemies_;

    std::string pathToTextures;

    sf::Texture enemyTexture_;
    sf::Texture textureLeft_;
    sf::Texture textureRight_;
    sf::Texture textureUp_;
    sf::Texture textureDown_;
    sf::Texture textureBomb_;
    sf::Texture textureExplosionHorizontal_;
    sf::Texture textureExplosionVertical_;
    sf::Texture gameOverTexture_;

    sf::Sprite enemySprite_;
    sf::Sprite spriteLeft_;
    sf::Sprite spriteRight_;
    sf::Sprite spriteUp_;
    sf::Sprite spriteDown_;
    sf::Sprite spriteBomb_;
    sf::Sprite spriteExplosionHorizontal_;
    sf::Sprite spriteExplosionVertical_;
    sf::Sprite gameOverSprite_;

    void loadEnemyTexture();
    void loadPlayerTextures();
    void loadExplosionTextures();
    void setPlayerSprites();
    sf::Sprite& getPlayerSprite();
    public:
    GameView(Board& b, Player& p, std::vector<Enemy*>& e);
    //here should be put all drawing functions ;)
    void drawBoard(sf::RenderWindow& win);
    void drawEnemies(sf::RenderWindow& win);
    void drawBomb(sf::RenderWindow& win);
    void drawPlayer(sf::RenderWindow& win);
    void drawExplosion(sf::RenderWindow& win);
    void drawGameOver(sf::RenderWindow& win);


};
