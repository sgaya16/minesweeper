#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <random>
#include <queue>
#include <unordered_set>
#include "Tile.h"
using namespace std;

Tile::Tile(sf::Texture *hiddenText, sf::Texture *revealedText, sf::Texture *flagText, sf::Texture *mine,
           sf::Texture *num1, sf::Texture *num2, sf::Texture *num3, sf::Texture *num4, sf::Texture *num5,
           sf::Texture *num6, sf::Texture *num7, sf::Texture *num8)
{

    hiddenTile.setTexture(*hiddenText);
    revealedTile.setTexture(*revealedText);
    flag.setTexture(*flagText);
    this->mine.setTexture(*mine);
    this->numOne.setTexture(*num1);
    this->numTwo.setTexture(*num2);
    this->numThree.setTexture(*num3);
    this->numFour.setTexture(*num4);
    this->numFive.setTexture(*num5);
    this->numSix.setTexture(*num6);
    this->numSeven.setTexture(*num7);
    this->numEight.setTexture(*num8);
}

void Tile::TileIsMine() {
    isMine = true;
}

void Tile::GetAdjacentMine() {
    queue <Tile *> Queue;
    //unordered_set <Tile *> visited;

    Queue.push(this);

    while (!Queue.empty()) {
        Tile *currTile = Queue.front();
        //visited.insert(currTile);
        Queue.pop();
        int mineCount = 0;

        for (Tile *adjTile : currTile->adjacentTiles) {
            if (adjTile->isMine) {
                mineCount++;
            }
        }
        currTile->adjMines = mineCount;

        if (mineCount == 0) {

            for (Tile *adjTile : currTile->adjacentTiles) {
                //const bool contains = visited.find(adjTile) != visited.end();
                if (!adjTile -> isMine && !adjTile -> isClicked) {
                    Queue.push(adjTile);
                }
            }
        }

        if (!currTile->isMine) {
            currTile->phase = REVEALED_TILE;
            currTile -> isClicked = true;
        }

        //Queue.pop();
    }
}

bool Tile::TileClicked(int clickType) {
    isClicked = true;

    if (clickType == LEFT_CLICK) {
        if (isFlag == true) {
            return true;
        }
        else if (isMine == true) {
            phase = MINE;
            cout << "mine exploded!" << endl;
            cout << "you lost!" << endl;
            return false;
        }
        else {
            phase = REVEALED_TILE;
            GetAdjacentMine();
        }
    }
    else if (clickType == RIGHT_CLICK) {
        if (phase == FLAG) {
            phase = HIDDEN_TILE;
            isFlag = false;
        }
        else {
            phase = FLAG;
            isFlag = true;
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

void Tile::Draw(float x, float y, sf::RenderWindow *window, bool debugMode, bool gameOver) {
    if (phase == GAME_WON) {
        revealedTile.setPosition(x, y);
        window->draw(revealedTile);
        mine.setPosition(x, y);
        window->draw(mine);
        flag.setPosition(x, y);
        window->draw(flag);
    }
    else if (debugMode == true && isMine == true && isClicked == false) {
           revealedTile.setPosition(x, y);
           window->draw(revealedTile);
           mine.setPosition(x, y);
           window->draw(mine);
    }
    else if (gameOver == true && isMine == true) {
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

               if (adjMines > 0) {
                    if (adjMines == 1) {
                        numOne.setPosition(x, y);
                        window->draw(numOne);
                    }
                    else if (adjMines == 2) {
                        numTwo.setPosition(x, y);
                        window->draw(numTwo);
                    }
                    else if (adjMines == 3) {
                        numThree.setPosition(x, y);
                        window->draw(numThree);
                    }
                    else if (adjMines == 4) {
                        numFour.setPosition(x, y);
                        window->draw(numFour);
                    }
                    else if (adjMines == 5) {
                        numFive.setPosition(x, y);
                        window->draw(numFive);
                    }
                    else if (adjMines == 6) {
                        numSix.setPosition(x, y);
                        window->draw(numSix);
                    }
                    else if (adjMines == 7) {
                        numSeven.setPosition(x, y);
                        window->draw(numSeven);
                    }
                    else if (adjMines == 8) {
                        numEight.setPosition(x, y);
                        window->draw(numEight);
                    }
               }
           }
           else {
               hiddenTile.setPosition(x, y);
               window->draw(hiddenTile);
               flag.setPosition(x, y);
               window->draw(flag);
           }
    }
}