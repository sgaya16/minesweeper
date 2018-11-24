#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <random>
#include "Board.h"
#include <SFML/Graphics.hpp>
using namespace std;

mt19937 mto(time(0));

//Randomization function
int Random(int min, int max) {
    uniform_int_distribution<int> dist(min, max);
    return dist(mto);
}

//board constructor
Board::Board(int height, int width, int numMines) {
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

    this->boardHeight = height;
    this->boardWidth = width;
    this->mineCount = numMines;
    debugButton.setTexture(textures["debug"]);
    debugButton.setPosition(16.5 * tileWidth, 16 * tileWidth);

    happyButton.setTexture(textures["happyFace"]);
    happyButton.setPosition(11.5 * tileWidth, 16 * tileWidth);

    winButton.setTexture(textures["winFace"]);
    loseButton.setTexture(textures["loseFace"]);

    test1.setTexture(textures["test1"]);
    test1.setPosition(18.5 * tileWidth, 16 * tileWidth);

    test2.setTexture(textures["test2"]);
    test2.setPosition(20.5 * tileWidth, 16 * tileWidth);

    for (int i = 0; i < boardHeight; i++) {
        tiles.push_back(vector<Tile>());
        for (int j = 0; j < boardWidth; j++) {
            tiles[i].push_back(Tile(&textures["hiddenTile"], &textures["revealedTile"], &textures["flag"], &textures["mine"]));
        }
    }

    for (int i = 0; i < 50; i++) {
        int x = Random(0, 15); int y = Random(0, 24);
        if (tiles[x][y].isMine) {
            i--;
        }
        else {
            tiles[x][y].TileIsMine();
        }
    }

    cout << "board constructed!" << endl;
}


//gets adjacent tiles for each individual tile
void Board::findAdjacentTiles() {

    for (int i = 0; i < boardHeight; i++) {
        for (int j = 0; j < boardWidth; j++) {
            if (i == 0 && j == 0) {
                tiles[i][j].adjacentTiles.push_back(&(tiles[i][j + 1])); //right tile
                tiles[i][j].adjacentTiles.push_back(&(tiles[i + 1][j + 1])); //bottom-right tile
                tiles[i][j].adjacentTiles.push_back(&(tiles[i + 1][j])); //bottom tile
            }
            else if (i == 0 && j == boardWidth - 1) {
                tiles[i][j].adjacentTiles.push_back(&(tiles[i][j - 1])); //left tile
                tiles[i][j].adjacentTiles.push_back(&(tiles[i + 1][j - 1])); //bottom-left tile
                tiles[i][j].adjacentTiles.push_back(&(tiles[i + 1][j])); //bottom tile
            }
            else if (i == boardHeight - 1 && j == 0) {
                tiles[i][j].adjacentTiles.push_back(&(tiles[i - 1][j])); //top tile
                tiles[i][j].adjacentTiles.push_back(&(tiles[i - 1][j + 1])); //top-right tile
                tiles[i][j].adjacentTiles.push_back(&(tiles[i][j + 1])); //right tile
            }
            else if (i == boardHeight - 1 && j == boardWidth - 1) {
                tiles[i][j].adjacentTiles.push_back(&(tiles[i - 1][j]));  //top tile
                tiles[i][j].adjacentTiles.push_back(&(tiles[i - 1][j - 1])); //top-left tile
                tiles[i][j].adjacentTiles.push_back(&(tiles[i][j - 1])); //left tile
            }
            else if (i == 0 && (j > 0 && j < boardWidth - 1)) {
                tiles[i][j].adjacentTiles.push_back(&(tiles[i][j - 1])); //left tile
                tiles[i][j].adjacentTiles.push_back(&(tiles[i + 1][j - 1])); //bottom-left tile
                tiles[i][j].adjacentTiles.push_back(&(tiles[i + 1][j])); //bottom tile
                tiles[i][j].adjacentTiles.push_back(&(tiles[i + 1][j + 1])); //bottom-right tile
                tiles[i][j].adjacentTiles.push_back(&(tiles[i][j + 1])); //right tile
            }
            else if (i == boardHeight - 1 && (j > 0 && j < boardWidth - 1)) {
                tiles[i][j].adjacentTiles.push_back(&(tiles[i][j - 1])); //left tile
                tiles[i][j].adjacentTiles.push_back(&(tiles[i - 1][j - 1])); //top-left tile
                tiles[i][j].adjacentTiles.push_back(&(tiles[i - 1][j])); //top tile
                tiles[i][j].adjacentTiles.push_back(&(tiles[i - 1][j + 1])); //top-right tile
                tiles[i][j].adjacentTiles.push_back(&(tiles[i][j + 1])); //right tile
            }
            else if ((i > 0 && i < boardHeight - 1) && j == 0) {
                tiles[i][j].adjacentTiles.push_back(&(tiles[i - 1][j])); //top tile
                tiles[i][j].adjacentTiles.push_back(&(tiles[i - 1][j + 1])); //top-right tile
                tiles[i][j].adjacentTiles.push_back(&(tiles[i][j + 1])); //right tile
                tiles[i][j].adjacentTiles.push_back(&(tiles[i + 1][j + 1])); //bottom-right tile
                tiles[i][j].adjacentTiles.push_back(&(tiles[i + 1][j])); //bottom tile
            }
            else if ((i > 0 && i < boardHeight - 1) && j == boardWidth - 1) {
                tiles[i][j].adjacentTiles.push_back(&(tiles[i - 1][j]));  //top tile
                tiles[i][j].adjacentTiles.push_back(&(tiles[i - 1][j - 1])); //top-left tile
                tiles[i][j].adjacentTiles.push_back(&(tiles[i][j - 1]));  //left tile
                tiles[i][j].adjacentTiles.push_back(&(tiles[i + 1][j - 1])); //bottom-left tile
                tiles[i][j].adjacentTiles.push_back(&(tiles[i + 1][j])); //bottom tile
            }
            else {
                tiles[i][j].adjacentTiles.push_back(&(tiles[i - 1][j - 1])); //top-left tile
                tiles[i][j].adjacentTiles.push_back(&(tiles[i - 1][j])); //top tile
                tiles[i][j].adjacentTiles.push_back(&(tiles[i - 1][j + 1])); //top-right tile
                tiles[i][j].adjacentTiles.push_back(&(tiles[i][j + 1])); //right tile
                tiles[i][j].adjacentTiles.push_back(&(tiles[i + 1][j + 1])); //bottom-right tile
                tiles[i][j].adjacentTiles.push_back(&(tiles[i + 1][j])); //bottom tile
                tiles[i][j].adjacentTiles.push_back(&(tiles[i + 1][j - 1])); //bottom-left tile
                tiles[i][j].adjacentTiles.push_back(&(tiles[i][j - 1])); //left tile
            }
        }
    }

}

bool Board::BoardClick(sf::Vector2f mousePos, int clickType) {

    for (int i = 0; i < boardHeight; i++) {
        for (int j = 0; j < boardWidth; j++) {
            if (tiles[i][j].CurrentSprite()->getGlobalBounds().contains(mousePos)) {
                tiles[i][j].TileClicked(clickType);
            }
        }
    }
    if (clickType == LEFT_CLICK) {
        if (debugButton.getGlobalBounds().contains(mousePos)) {
            debugMode = !debugMode;
        }
        else if (test1.getGlobalBounds().contains(mousePos)) {
            cout << "test 1 clicked" << endl;
        }
        else if ((test2.getGlobalBounds().contains(mousePos))) {
            cout << "test 2 clicked" << endl;
        }
    }
}


void Board::DrawAllTiles(sf::RenderWindow *window) {
    for (int i = 0; i < boardHeight; i++) {
        for (int j = 0; j < boardWidth; j++) {
            float y = i * tileWidth * 1.0f;
            float x = j * tileWidth * 1.0f;
            tiles[i][j].draw(x,y, window, debugMode);
        }
    }
    window->draw(happyButton);
    window->draw(debugButton);
    window->draw(test1);
    window->draw(test2);
}
