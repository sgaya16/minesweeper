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
Board::Board(int height, int width, int numMines, sf::Texture *hidden, sf::Texture *revealed, sf::Texture *flag) {
    this->boardHeight = height;
    this->boardWidth = width;
    this->mineCount = numMines;

    for (int i = 0; i < boardHeight; i++) {
        tiles.push_back(vector<Tile>());
        for (int j = 0; j < boardWidth; j++) {
            tiles[i].push_back(Tile(hidden, revealed, flag));
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


}

void Board::DrawAllTiles(sf::RenderWindow *window) {
    for (int i = 0; i < boardHeight; i++) {
        for (int j = 0; j < boardWidth; j++) {
            float y = i * tileWidth * 1.0f;
            float x = j * tileWidth * 1.0f;
            tiles[i][j].CurrentSprite()->setPosition(x, y);
            window->draw(*tiles[i][j].CurrentSprite());

        }

    }


}
