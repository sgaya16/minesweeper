#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <map>
#include <random>
#include <string>
#include "Tile.h"
using namespace std;


struct Board {

    //functions:
    Board() {};
    Board(int height, int width, int numMines);
    void DrawAllTiles(sf::RenderWindow* window);
    void RestartGame();
    void GameOver();
    void UpdateNumberOfMines();
    void findAdjacentTiles();
    bool BoardClick(sf::Vector2f mousePos, int clickType);

    //variables:
    vector<vector<Tile>> tiles;
    sf::Sprite happyButton;
    sf::Sprite loseButton;
    sf::Sprite winButton;
    sf::Sprite debugButton;
    const int LEFT_CLICK = 0;
    const int RIGHT_CLICK = 1;
    sf::Sprite test1; sf::Sprite test2;
    bool debugMode = false;
    int tileWidth = 32;
    int boardWidth = 0; int boardHeight = 0;
    int mineCount = 0;

    map<string, sf::Texture> textures;

};







