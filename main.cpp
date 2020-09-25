#include <SFML/Graphics.hpp>
#include "Board.hpp"
#include <iostream>

void displayBoard(Board& b) {
    for(int row = 0; row < b.getHeight(); row++) {
        for (int col = 0; col < b.getWidth(); col++) {
            std::cout << "[ ";
            if (b.getField(col, row).isWall) {
                std::cout << "W";
            } else {
                std::cout << " ";
            }
            std::cout << " ]";
        }
        std::cout << '\n';
    }
}

int main()
{
    Board board(13, 11);
    displayBoard(board);
    
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
