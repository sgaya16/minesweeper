#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

int main() {



    sf::RenderWindow window(sf::VideoMode(800, 600),"Minesweeper");

    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("images/tile_hidden.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite(texture);

    vector<vector<sf::Sprite>> hiddenTiles;

    for (int i = 0; i < 16 ; i++) {
        hiddenTiles.push_back(vector<sf::Sprite>());
        for (int j = 0; j < 25; j++){
            hiddenTiles[i].push_back(sprite);
            sprite.move(32,0);
        }
        sprite.setPosition(0,sprite.getPosition().y);
        sprite.move(0,32);
    }



    while(window.isOpen()){

        sf::Event event;

        while(window.pollEvent(event)) {

            if(event.type == sf::Event::Closed){
                window.close();

            }

            window.clear(sf::Color::Black);

            for (int i = 0; i < 16; i++) {
                for (int j = 0; j < 25; j++) {
                    window.draw(hiddenTiles[i][j]);
                }
            }

            window.display();

        }

    }

    return 0;

}