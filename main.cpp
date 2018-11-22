#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include <string>
#include "Board.h"
#include "Tile.h"
using namespace std;

int main() {

    sf::RenderWindow window(sf::VideoMode(800, 600),"Minesweeper");

    map<string, sf::Texture> textures; sf::Vector2i mousePos; sf::Vector2f mouseFloat;
    sf::Texture texture; Tile tileObject; Board boardObject;

    textures["hiddenTile"].loadFromFile("images/tile_hidden.png");
    textures["revealedTile"].loadFromFile("images/tile_revealed.png");
    textures["number1"].loadFromFile("images/number_1.png");
    textures["number2"].loadFromFile("images/number_2.png");
    textures["number3"].loadFromFile("images/number_3.png");
    textures["number4"].loadFromFile("images/number_4.png");
    textures["number5"].loadFromFile("images/number_5.png");
    textures["number6"].loadFromFile("images/number_6.png");
    textures["number7"].loadFromFile("images/number_7.png");
    textures["number8"].loadFromFile("images/number_8.png");
    textures["flag"].loadFromFile("images/flag.png");
    textures["mine"].loadFromFile("images/mine.png");
    textures["winFace"].loadFromFile("images/face_win.png");
    textures["happyFace"].loadFromFile("images/face_happy.png");
    textures["loseFace"].loadFromFile("images/face_lose.png");
    textures["digits"].loadFromFile("images/digits.png");
    textures["debug"].loadFromFile("images/debug.png");
    textures["test1"].loadFromFile("images/test_1.png");
    textures["test2"].loadFromFile("images/test_2.png");

    Board mineSweeper(16, 25, 50, &textures["hiddenTile"], &textures["revealedTile"], &textures["flag"]);


    while(window.isOpen()){

        sf::Event event;

        while(window.pollEvent(event)) {

            //if the window is closed
            if(event.type == sf::Event::Closed){
                window.close();

            }
            //if the left mouse button is clicked
            else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    cout << "left button pressed" << endl;
                    mousePos = sf::Mouse::getPosition(window);
                    mouseFloat = sf::Vector2f(mousePos);
                    if (tileObject.hiddenTile.getGlobalBounds().contains(mouseFloat)) {
                        tileObject.TileClicked(1);
                    }

                }
            }

            window.clear();
            mineSweeper.DrawAllTiles(&window);


            window.display();

        }

    }

    return 0;

}