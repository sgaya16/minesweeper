#include <iostream>
#include "Board.h"
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
    textures["debug"].loadFromFile("images/debug.png");
    textures["test1"].loadFromFile("images/test_1.png");
    textures["test2"].loadFromFile("images/test_2.png");

    textures["digit0"].loadFromFile("images/digits.png", sf::IntRect(0, 0, 21, 32));
    textures["digit1"].loadFromFile("images/digits.png", sf::IntRect(21, 0, 21, 32));
    textures["digit2"].loadFromFile("images/digits.png", sf::IntRect(42, 0, 21, 32));
    textures["digit3"].loadFromFile("images/digits.png", sf::IntRect(63, 0, 21, 32));
    textures["digit4"].loadFromFile("images/digits.png", sf::IntRect(84, 0, 21, 32));
    textures["digit5"].loadFromFile("images/digits.png", sf::IntRect(105, 0, 21, 32));
    textures["digit6"].loadFromFile("images/digits.png", sf::IntRect(126, 0, 21, 32));
    textures["digit7"].loadFromFile("images/digits.png", sf::IntRect(147, 0, 21, 32));
    textures["digit8"].loadFromFile("images/digits.png", sf::IntRect(168, 0, 21, 32));
    textures["digit9"].loadFromFile("images/digits.png", sf::IntRect(189, 0, 21, 32));

    this->boardHeight = height;
    this->boardWidth = width;
    this->mineCount = numMines;

    place1.setTexture(textures["digit0"]);
    place1.setPosition(0, 16 * tileWidth);

    place2.setTexture(textures["digit5"]);
    place2.setPosition(21, 16 * tileWidth);

    place3.setTexture(textures["digit0"]);
    place3.setPosition(42, 16 * tileWidth);

    debugButton.setTexture(textures["debug"]);
    debugButton.setPosition(16.5 * tileWidth, 16 * tileWidth);

    happyButton.setTexture(textures["happyFace"]);
    happyButton.setPosition(11.5 * tileWidth, 16 * tileWidth);

    winButton.setTexture(textures["winFace"]);
    winButton.setPosition(11.5 * tileWidth, 16 * tileWidth);

    loseButton.setTexture(textures["loseFace"]);
    loseButton.setPosition(11.5 * tileWidth, 16 * tileWidth);

    test1.setTexture(textures["test1"]);
    test1.setPosition(18.5 * tileWidth, 16 * tileWidth);

    test2.setTexture(textures["test2"]);
    test2.setPosition(20.5 * tileWidth, 16 * tileWidth);

    for (int i = 0; i < boardHeight; i++) {
        tiles.push_back(vector<Tile>());
        for (int j = 0; j < boardWidth; j++) {
            tiles[i].push_back(Tile(&textures["hiddenTile"], &textures["revealedTile"],
                                    &textures["flag"], &textures["mine"], &textures["number1"], &textures["number2"],
                                    &textures["number3"], &textures["number4"], &textures["number5"],
                                    &textures["number6"], &textures["number7"],  &textures["number8"]));
        }
    }
    AddAdjacentTiles();

    SetBoard();

    cout << "board constructed!" << endl;
}

void Board::SetBoard() {
    for (int i = 0; i < 50; i++) {
        int x = Random(0, 15); int y = Random(0, 24);
        if (tiles[x][y].isMine) {
            i--;
        }
        else {
            tiles[x][y].TileIsMine();
        }
    }
}

void Board::LoadTestOne() {
    ifstream testOne("boards/testboard.brd");
    string substr;
    int row = 0; int column = 0;
    testOneMines = 0;

    if (!testOne.good()) {
        cout << "unable to load test 1" << endl;
    }


    while (getline(testOne, substr)) {
        for (column = 0; column < 25; column++) {
            if (substr[column] == '1') {
                tiles[row][column].TileIsMine();
                testOneMines++;
            }
        }
        row++;
    }
    mineCount = testOneMines;

    UpdateMineCount();

    testOne.close();
}

void Board::LoadTestTwo() {
    ifstream testTwo("boards/testboard2.brd");
    string substr;
    int row = 0; int column = 0;
    testTwoMines = 0;

    if (!testTwo.good()) {
        cout << "unable to load test 1" << endl;
    }


    while (getline(testTwo, substr)) {
        for (column = 0; column < 25; column++) {
            if (substr[column] == '1') {
                tiles[row][column].TileIsMine();
                testTwoMines++;
            }
        }
        row++;
    }
    mineCount = testTwoMines;

    UpdateMineCount();

    testTwo.close();
}

void Board::UpdateMineCount() {
    int currentFlagCount = 0;

    for (int i = 0; i < boardHeight; i++) {
        for (int j = 0; j < boardWidth; j++) {
            if (tiles[i][j].isFlag == true) {
               currentFlagCount++;
            }
        }
    }

    int updatedMineCount = mineCount - currentFlagCount;
    currentMineCount = updatedMineCount;

    int placeThree = updatedMineCount % 10;
    updatedMineCount /= 10;
    int placeTwo = updatedMineCount % 10;
    updatedMineCount /= 10;
    int placeOne = updatedMineCount % 10;
    string placeThreeString = "digit" + to_string(placeThree);
    string placeTwoString = "digit" + to_string(placeTwo);
    string placeOneString = "digit" + to_string(placeOne);

    place3.setTexture(textures[placeThreeString]);
    place2.setTexture(textures[placeTwoString]);
    place1.setTexture(textures[placeOneString]);
}


//gets adjacent tiles for each individual tile
void Board::AddAdjacentTiles() {

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

void Board::RestartGame() {
    CleanAllTiles();
    SetBoard();
    mineCount = 50;
    gameOver = false;
    gameWon = false;
}

void Board::CleanAllTiles() {
    for (int i = 0; i < boardHeight; i++) {
        for (int j = 0; j < boardWidth; j++) {
            tiles[i][j].phase = 0;
            tiles[i][j].isMine = false;
            tiles[i][j].isClicked = false;
            tiles[i][j].isFlag = false;
        }
    }
}

bool Board::CheckAllTiles() {
    for (int i = 0; i < boardHeight; i++) {
        for (int j = 0; j < boardWidth; j++) {
            if (!tiles[i][j].isMine && !tiles[i][j].isClicked) {
                return false;
            }
        }
    }
    return true;
}

bool Board::BoardClick(sf::Vector2f mousePos, int clickType) {

    if (gameOver == false && !gameWon == true) {
        for (int i = 0; i < boardHeight; i++) {
            for (int j = 0; j < boardWidth; j++) {
                if (tiles[i][j].CurrentSprite()->getGlobalBounds().contains(mousePos)) {
                    if (tiles[i][j].TileClicked(clickType) == false) {
                        gameOver = true;
                    }
                }
            }
        }
    }

    if (clickType == LEFT_CLICK) {
        if (gameOver == false && gameWon == false) {
            if (debugButton.getGlobalBounds().contains(mousePos)) {
                debugMode = !debugMode;
                cout << "debug button clicked" << endl;
            }
            else if (test1.getGlobalBounds().contains(mousePos)) {
                CleanAllTiles();
                LoadTestOne();
                cout << "test 1 clicked" << endl;
            }
            else if ((test2.getGlobalBounds().contains(mousePos))) {
                CleanAllTiles();
                LoadTestTwo();
                cout << "test 2 clicked" << endl;
            }
            else if (CheckAllTiles() == true) {
                gameWon = true;
                for (int i = 0; i < boardHeight; i++) {
                    for (int j = 0; j < boardWidth; j++) {
                        if (tiles[i][j].isMine) {
                            tiles[i][j].phase = 4;
                        }
                    }
                }
            }
        }
        if (happyButton.getGlobalBounds().contains(mousePos)) {
            RestartGame();
            cout << "game restarted" << endl;
        }
    }
    return true;
}


void Board::DrawAllTiles(sf::RenderWindow *window) {

    for (int i = 0; i < boardHeight; i++) {
        for (int j = 0; j < boardWidth; j++) {
            float y = i * tileWidth * 1.0f;
            float x = j * tileWidth * 1.0f;
            tiles[i][j].Draw(x, y, window, debugMode, gameOver);
        }
    }
    UpdateMineCount();


    if (gameOver == true) {
        window->draw(loseButton);
    }
    else if (gameWon == true) {
        window->draw(winButton);
    }
    else {
        window->draw(happyButton);
    }

    window->draw(place1);
    window->draw(place2);
    window->draw(place3);
    window->draw(debugButton);
    window->draw(test1);
    window->draw(test2);
}
