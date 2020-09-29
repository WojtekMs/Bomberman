#include "Board.hpp"
#include "Enemy.hpp"
#include "GameController.hpp"
#include "Player.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 608), "Bomberman");
    Board board(19, 25);
    Player player(board, 11, 10);
    Enemy enemy(board, 8, 8);
    Enemy enemy1(board, 7, 6);
    Enemy enemy2(board, 6, 3);
    Enemy enemy3(board, 5, 8);
    std::vector<Enemy*> vec{&enemy1, &enemy2, &enemy3, &enemy};
    GameController gc(board, player, vec);
    sf::Clock clock;
    bool clockReseted = false;
    bool animationBegins = true;
    sf::Texture gameover_;
    if (!gameover_.loadFromFile("img/game_over.png")) {
        std::cerr << "Error :CCCCCCCCCCC\n";
    }
    sf::Sprite gameOverSprite_;
    gameOverSprite_.setTexture(gameover_);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            gc.handleEvents(event);
        }
        gc.updateGame();
        window.clear();
        if (gc.getGameState() == GAME_STATE::LOST) {
            window.draw(gameOverSprite_);
            window.display();
            continue;
        }
        board.draw(window);
        if (gc.isBombPlaced()) {
            player.drawBomb(window);
        }
        player.draw(player.getCurrentDirection(), window);
        enemy.draw(window);
        enemy1.draw(window);
        enemy2.draw(window);
        enemy3.draw(window);
        if (gc.isExplosion()) {
            gc.removeEnemies();
            player.drawExplosion(window);
        }
        window.display();
    }

    return 0;
}
