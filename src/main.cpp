#include "Board.hpp"
#include "Enemy.hpp"
#include "Game.hpp"
#include "GameController.hpp"
#include "GameView.hpp"
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
    GameView gv(board, player, vec);
    Game game(gc, gv, window);
    game.run();
    

    return 0;
}
