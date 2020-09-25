#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "Board.hpp"
#include "Player.hpp"

void displayBoard(Board& b, Player& p) {
    for (int row = 0; row < b.getHeight(); row++) {
        for (int col = 0; col < b.getWidth(); col++) {
            std::cout << "[ ";
            if (b.getField(col, row).isWall) {
                std::cout << "W";
            } else if (p.getCol() == col && p.getRow() == row) {
                std::cout << "P";
            } else {
                std::cout << " ";
            }
            std::cout << " ]";
        }
        std::cout << '\n';
    }
}

int main() {
    std::string dash(60, '-');
    Board board(13, 11);
    Player player(board, 5, 10);
    displayBoard(board, player);
    std::cout << dash << '\n';
    player.moveDown();
    std::cout << player.getRow();
    displayBoard(board, player);
    std::cout << dash << '\n';
    player.moveDown();
    std::cout << player.getRow();
    player.moveDown();
    std::cout << player.getRow();
    displayBoard(board, player);
    std::cout << dash << '\n';

    // sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    // sf::CircleShape shape(100.f);
    // shape.setFillColor(sf::Color::Green);

    // while (window.isOpen())
    // {
    //     sf::Event event;
    //     while (window.pollEvent(event))
    //     {
    //         if (event.type == sf::Event::Closed)
    //             window.close();
    //     }

    //     window.clear();
    //     window.draw(shape);
    //     window.display();
    // }

    // return 0;
}
