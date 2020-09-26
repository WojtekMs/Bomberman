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

constexpr int height_ = 13;
constexpr int width_  = 11;

int main()
{
    // Board board(13, 11);
    // displayBoard(board);
    
    sf::RenderWindow window(sf::VideoMode(800, 608), "Bomberman");
    Board board(19, 25);
    //displayBoard(board);

    

    window.display();
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(board.getSprite());
        board.draw(window);
        window.display();
    
    }

    return 0;
}
