#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>
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
    void SetBoard();
    void DrawAllTiles(sf::RenderWindow* window);
    void CleanAllTiles();
    void RestartGame();
    void UpdateMineCount();
    void LoadTestOne();
    void LoadTestTwo();
    void AddAdjacentTiles();
    bool BoardClick(sf::Vector2f mousePos, int clickType);
    bool CheckAllTiles();

    //variables:
    vector<vector<Tile>> tiles;
    sf::Sprite happyButton;
    sf::Sprite loseButton;
    sf::Sprite winButton;
    sf::Sprite debugButton;
    sf::Sprite place1; sf::Sprite place2; sf::Sprite place3;
    const int LEFT_CLICK = 0;
    const int RIGHT_CLICK = 1;
    sf::Sprite test1; sf::Sprite test2;
    bool debugMode = false; bool gameOver = false; bool gameWon = false;
    int tileWidth = 32;
    int boardWidth = 0; int boardHeight = 0;
    int mineCount = 0; int currentMineCount = 0;
    int testOneMines = 0; int testTwoMines = 0;
    map<string, sf::Texture> textures;
};







