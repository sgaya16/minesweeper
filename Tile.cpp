#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <random>
#include "Tile.h"
using namespace std;

Tile::Tile(sf::Texture *hiddenText, sf::Texture *revealedText, sf::Texture *flagText) {
    hiddenTile.setTexture(*hiddenText);
    revealedTile.setTexture(*revealedText);
    flag.setTexture(*flagText);
}

void Tile::TileIsMine() {
    isMine = true;
}

void Tile::SetFlag() {
    isFlag = true;
}

void Tile::RemoveFlag() {
    isFlag = false;
}

bool Tile::TileClicked(int clickType) {
    isClicked = true;

    if (isMine == true) {
        cout << "mine already exploded!" << endl;
        return false;
    }

    if (clickType == LEFT_CLICK) {
        phase = REVEALED_TILE;
    }
    else if (clickType == RIGHT_CLICK) {
        if (phase == FLAG) {
            phase = HIDDEN_TILE;
        }
        else {
            phase = FLAG;
        }
    }
    return true;
}

sf::Sprite* Tile::CurrentSprite() {
    if (phase == HIDDEN_TILE) {
        return &hiddenTile;
    }
    else if (phase == REVEALED_TILE) {
        return &revealedTile;
    }
    else {
        return &flag;
    }
}