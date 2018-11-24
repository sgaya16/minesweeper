#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <random>
#include "Tile.h"
using namespace std;

Tile::Tile(sf::Texture *hiddenText, sf::Texture *revealedText, sf::Texture *flagText, sf::Texture *mine) {
    hiddenTile.setTexture(*hiddenText);
    revealedTile.setTexture(*revealedText);
    flag.setTexture(*flagText);
    this->mine.setTexture(*mine);
}

void Tile::TileIsMine() {
    isMine = true;
}

bool Tile::TileClicked(int clickType) {
    isClicked = true;

    if (clickType == LEFT_CLICK) {
        if (isMine == true) {
            phase = MINE;
            cout << "Mine exploded!" << endl;
            return false;
        }
        else {
            phase = REVEALED_TILE;
        }
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
    else if (phase == MINE) {
        return &mine;
    }
    else {
        return  &flag;
    }
}

void Tile::draw(float x, float y, sf::RenderWindow* window, bool debugMode) {
       if (debugMode == true && isMine == true && isClicked == false) {
           revealedTile.setPosition(x, y);
           window->draw(revealedTile);
           mine.setPosition(x, y);
           window->draw(mine);
       }
       else {
           if (phase == HIDDEN_TILE) {
               hiddenTile.setPosition(x, y);
               window->draw(hiddenTile);
           }
           else if (phase == REVEALED_TILE) {
               revealedTile.setPosition(x, y);
               window->draw(revealedTile);
           }
           else if (phase == MINE) {
               revealedTile.setPosition(x, y);
               window->draw(revealedTile);
               mine.setPosition(x, y);
               window->draw(mine);
           }
           else {
               hiddenTile.setPosition(x, y);
               window->draw(hiddenTile);
               flag.setPosition(x, y);
               window->draw(flag);
           }
       }

}