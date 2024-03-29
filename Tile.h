#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <random>
#include <queue>
#include <unordered_set>
using namespace std;

struct Tile {

    //functions:
    Tile() {};
    Tile(sf::Texture *hidden, sf::Texture *revealed, sf::Texture *flag, sf::Texture *mine, sf::Texture *num1,
         sf::Texture *num2, sf::Texture *num3, sf::Texture *num4, sf::Texture *num5, sf::Texture *num6,
         sf::Texture *num7, sf::Texture *num8);
    void TileIsMine();
    void GetAdjacentMine();
    bool TileClicked(int clickType);
    sf::Sprite* CurrentSprite();
    void Draw(float x, float y, sf::RenderWindow *window, bool debugMode, bool gameOver);

    //variables:
    sf::Sprite hiddenTile;
    sf::Sprite revealedTile;
    sf::Sprite flag;
    sf::Sprite mine;
    sf::Sprite numOne; sf::Sprite numTwo; sf::Sprite numThree; sf::Sprite numFour;
    sf::Sprite numFive; sf::Sprite numSix; sf::Sprite numSeven; sf::Sprite numEight;
    vector<Tile *> adjacentTiles;
    int phase = 0;
    const int HIDDEN_TILE = 0;
    const int REVEALED_TILE = 1;
    const int FLAG = 2;
    const int MINE = 3;
    const int GAME_WON = 4;
    const int LEFT_CLICK = 0; const int RIGHT_CLICK = 1;
    bool isClicked = false;
    bool isMine = false;
    bool isFlag = false;
    int adjMines = 0;

};

