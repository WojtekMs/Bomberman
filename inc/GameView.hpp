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

    std::string pathToTextures{"../img/"};

    sf::Texture textureMap_;
    sf::Texture textureWall_;
    sf::Texture enemyTexture_;
    sf::Texture textureLeft_;
    sf::Texture textureRight_;
    sf::Texture textureUp_;
    sf::Texture textureDown_;
    sf::Texture textureBomb_;
    sf::Texture textureExplosionHorizontal_;
    sf::Texture textureExplosionVertical_;
    sf::Texture textureGameOver_;

    sf::Sprite spriteMap_;
    sf::Sprite spriteWall_;
    sf::Sprite spriteEnemy_;
    sf::Sprite spriteLeft_;
    sf::Sprite spriteRight_;
    sf::Sprite spriteUp_;
    sf::Sprite spriteDown_;
    sf::Sprite spriteBomb_;
    sf::Sprite spriteExplosionHorizontal_;
    sf::Sprite spriteExplosionVertical_;
    sf::Sprite spriteGameOver_;

    void loadEnemyTexture();
    void loadPlayerTextures();
    void loadExplosionTextures();
    void setPlayerSprites();
    sf::Sprite& getPlayerSprite();
    public:
    GameView(Board& b, Player& p, std::vector<Enemy*>& e);

    void drawBoard(sf::RenderWindow& win);
    void drawEnemies(sf::RenderWindow& win);
    void drawBomb(sf::RenderWindow& win);
    void drawPlayer(sf::RenderWindow& win);
    void drawExplosion(sf::RenderWindow& win);
    void drawGameOver(sf::RenderWindow& win);


};
