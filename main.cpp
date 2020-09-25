#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Bomberman");

    sf::Texture texture;
    if(!texture.loadFromFile("map.png")) {
        std::cerr << ":C\n";
    }

    sf::Sprite sprite(texture);
    sprite.setScale(0.75f, 0.75f);
    sf::Vector2u size = texture.getSize();

    sprite.setOrigin(size.x / 2, size.y / 2);
    window.clear();
    window.draw(sprite);
    window.display();
    

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        
        // window.clear();
        // window.draw(sprite);
        // window.display();
        
    }

    return 0;
}
