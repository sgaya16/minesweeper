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
    Board(int height, int width, int numMines, sf::Texture* hidden, sf::Texture* revealed, sf::Texture *flag);
    void DrawAllTiles(sf::RenderWindow* window);
    void RestartGame();
    void GameOver();
    void UpdateNumberOfMines();
    sf::Sprite SetTiles();
    void findAdjacentTiles();
    bool BoardClick(sf::Vector2f mousePos, int clickType);

    //variables:
    vector<vector<Tile>> tiles;
    sf::Sprite restartButton;
    sf::Sprite debugButton;
    sf::Sprite Test1; sf::Sprite test2;
    int tileWidth = 32;
    int boardWidth = 0; int boardHeight = 0;
    int mineCount = 0;

};







