#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include <string>
#include "Board.h"
#include "Tile.h"
using namespace std;

int main() {

    sf::RenderWindow window(sf::VideoMode(800, 600),"Minesweeper");

    sf::Vector2i mousePos; sf::Vector2f mouseFloat;

    Board mineSweeper(16, 25, 50);

    while(window.isOpen()){

        sf::Event event;

        while(window.pollEvent(event)) {

            //if the window is closed
            if(event.type == sf::Event::Closed){
                window.close();

            }
            else if (event.type == sf::Event::MouseButtonPressed) {
                //if the left mouse button is clicked
                if (event.mouseButton.button == sf::Mouse::Left) {
                    cout << "left button clicked" << endl;
                    mousePos = sf::Mouse::getPosition(window);
                    mouseFloat = sf::Vector2f(mousePos);
                    mineSweeper.BoardClick(mouseFloat, 0);
                }
                //if the right mouse button is clicked
                else if (event.mouseButton.button == sf::Mouse::Right) {
                    cout << "right button clicked" << endl;
                    mousePos = sf::Mouse::getPosition(window);
                    mouseFloat = sf::Vector2f(mousePos);
                    mineSweeper.BoardClick(mouseFloat, 1);
                }
            }

            window.clear(sf::Color::White);
            mineSweeper.DrawAllTiles(&window);


            window.display();

        }

    }
    return 0;
}