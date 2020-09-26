#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <thread>

#include "Board.hpp"
#include "Enemy.hpp"
#include "GameController.hpp"
#include "Player.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 608), "Bomberman");
    Board board(19, 25);
    Player player(board, 10, 10);
    Enemy enemy(board, 8, 8);
    Enemy enemy1(board, 7, 6);
    Enemy enemy2(board, 6, 3);
    Enemy enemy3(board, 5, 8);
    std::vector<Enemy*> vec{&enemy1, &enemy2, &enemy3, &enemy};
    GameController gc(board, player, vec);
    sf::Clock clock;
    bool animationBegins = false;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            gc.handleEvents(event);
        }
        gc.moveEnemies();
        window.clear();
        window.draw(board.getSprite());
        board.draw(window);
        if (player.isBombPlaced()) {
            player.drawBomb(window);
        }
        player.draw(player.getCurrentDirection(), window);
        enemy.draw(window);
        enemy1.draw(window);
        enemy2.draw(window);
        enemy3.draw(window);
        if (gc.checkIfBombBlow()) {
            gc.removeEnemies();
            clock.restart();
            animationBegins = true;
        }
        if (animationBegins) {
            player.drawExplosion(window);
            if (clock.getElapsedTime().asSeconds() > 0.7) {
                animationBegins = false;
            }
        }
        if (gc.getGameState() == GAME_STATE::LOST) {
            std::cerr << "GAME OVER!\n";
            sf::Texture gameover_;
            if (!gameover_.loadFromFile("game_over.png")) {
                std::cerr << "Error :CCCCCCCCCCC\n";
            }
            sf::Sprite sprite_;
            sprite_.setTexture(gameover_);
            window.draw(sprite_);
            //exit(0);
        }
        window.display();
    }

    return 0;
}
