#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

struct Tile {

    //functions:
    Tile() {};
    Tile(sf::Texture *hidden, sf::Texture *revealed, sf::Texture *flag, sf::Texture *mine);
    void TileIsMine();
    bool TileClicked(int clickType);
    sf::Sprite* CurrentSprite();
    void draw(float x, float y, sf::RenderWindow *window, bool debugMode);


    //variables:
    sf::Sprite hiddenTile;
    sf::Sprite revealedTile;
    sf::Sprite flag;
    sf::Sprite mine;
    vector<Tile *> adjacentTiles;
    int phase = 0;
    const int HIDDEN_TILE = 0;
    const int REVEALED_TILE = 1;
    const int FLAG = 2;
    const int MINE = 3;
    const int LEFT_CLICK = 0; const int RIGHT_CLICK = 1;
    bool isClicked = false;
    bool isMine = false;
    bool isFlag = false;
    bool isEmpty = false;


};

