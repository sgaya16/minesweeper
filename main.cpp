#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

int main() {



    sf::RenderWindow window(sf::VideoMode(800, 600),"Hello SFML");

    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("images/tile_hidden.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite(texture);



    while(window.isOpen()){

        sf::Event event;

        while(window.pollEvent(event)) {

            if(event.type == sf::Event::Closed){
                window.close();

            }

            window.clear(sf::Color::Black);

            window.draw(sprite);

            window.display();

        }

    }

    return 0;

}