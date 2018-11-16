#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include <string>
#include "Board.h"
using namespace std;


struct Tile {

    //functions:
    Tile () {};

    sf::Sprite hiddenTile;
    sf::Sprite revealedTile;
    sf::Sprite flag;

};




int main() {

    sf::RenderWindow window(sf::VideoMode(800, 600),"Minesweeper");

    map<string, sf::Texture> textures;
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

    tileObject.hiddenTile.setTexture(textures["hiddenTile"]);
    tileObject.revealedTile.setTexture(textures["revealedTile"]);
    tileObject.flag.setTexture(textures["flag"]);

    for (int i = 0; i < 16; i++) {
        boardObject.hiddenTiles.push_back(vector<sf::Sprite>());
        for (int j = 0; j < 25; j++) {
            boardObject.hiddenTiles[i].push_back(tileObject.hiddenTile);
            tileObject.hiddenTile.move(32, 0);
        }
        tileObject.hiddenTile.setPosition(0, tileObject.hiddenTile.getPosition().y);
        tileObject.hiddenTile.move(0, 32);
    }

    /*
    //sf::Texture texture;

    if (!texture.loadFromFile("images/tile_hidden.png")) {
        throw EXIT_FAILURE;
    }
    sf::Sprite sprite(texture);

    vector<vector<sf::Sprite>> hiddenTiles;

    for (int i = 0; i < 16; i++) {
        hiddenTiles.push_back(vector<sf::Sprite>());
        for (int j = 0; j < 25; j++) {
            hiddenTiles[i].push_back(sprite);
            sprite.move(32, 0);
        }
        sprite.setPosition(0, sprite.getPosition().y);
        sprite.move(0, 32);
    }


    /*map<int, sf::Sprite> hiddenTiles;
    int movex = 0;
    int movey = 0;
    for (int i = 0; i < 400; i++) {
        hiddenTiles[i] = sprite;
        movey = sprite.getPosition().y;
        if (i % 16 == 0 && i != 0){
            movex += 32;
            movey = 0;
        }
        sprite.setPosition(movex, 32);
        sprite.move(0, 32);
        cout << "sprite added" << endl;
    }*/




    while(window.isOpen()){

        sf::Event event;

        while(window.pollEvent(event)) {

            if(event.type == sf::Event::Closed){
                window.close();

            }

            window.clear();

            for (int i = 0; i < 16; i++) {
                for (int j = 0; j < 25; j++) {
                    window.draw(boardObject.hiddenTiles[i][j]);
                }
            }


            /*for (int i = 0; i < 16; i++) {
                for (int j = 0; j < 25; j++) {
                    window.draw(hiddenTiles[i][j]);
                }
            }
             */

            window.display();

        }

    }

    return 0;

}