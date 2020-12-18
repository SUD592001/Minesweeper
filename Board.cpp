#include "Board.h"

Board::Board(sf::RenderWindow* win) {
    window = win;
}


void Board::Initialize() {
    numberOfMines = 0;
    score = 0;
    success = false;
    CreateTiles();
    PlaceMines();
    numberOfFlags = numberOfMines;
    ConnectTiles();
    SetNumbers();
    resetButton.LoadToggle(368, 512, "face_happy");
    resetButton.SetWindow(window);
    test1.LoadToggle(560, 512, "test_1");
    test2.LoadToggle(624, 512, "test_2");
    test3.LoadToggle(688, 512, "test_3");
    test1.SetWindow(window);
    test2.SetWindow(window);
    test3.SetWindow(window);
    debug.LoadToggle(496, 512, "debug");
    debug.SetWindow(window);
    digits.flagNumber(0, 5, 0);
    flagCounter();
    digits.SetWindow(window);
    mouseClickTest1 = false;
    mouseClickTest2 = false;
    mouseClickTest3 = false;
    mineClicked = false;
    resetClicked = false;
}

void Board::Update() {
    CheckWin();
    if (mineClicked == true) {
        LoseGame();
        if (resetClicked == true) {
            ResetClick();
        }
    }
    else if (clickDebug == true) {
        DebugClick();
        if (resetClicked == true) {
            ResetClick();
        }
    }
    else if (resetClicked == true) {
        ResetClick();
    }
    else {
        DrawTiles();
    }

    if (mouseClickTest1 || mouseClickTest2 || mouseClickTest3) {
        ResetClick();
    }
    if (success == true) {
        WinGame();
        flagCounter();
        if (resetClicked == true) {
            ResetClick();
        }
    }
    resetButton.DrawToggle();
    test1.DrawToggle();
    test2.DrawToggle();
    test3.DrawToggle();
    debug.DrawToggle();
    digits.DrawNumbers();
}

void Board::CreateTiles() {
    for (int j = 0; j < 16; j++) {
        for (int i = 0; i < 25; i++) {
            tileArray[i][j].CreateHiddenTile(i * 32, j * 32);
            tileArray[i][j].SetWindow(window);
        }
    }
}

void Board::PlaceMines() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> xCoor(0, 24);
    std::uniform_int_distribution<int> yCoor(0, 15);

    if (!mouseClickTest1 && !mouseClickTest2 && !mouseClickTest3) {
        while (numberOfMines < 50) {
            for (int i = 0; i < 50; i++) {
                i--;
                sf::Vector2i mineCoordinate;
                mineCoordinate.x = xCoor(gen);
                mineCoordinate.y = yCoor(gen);
                if (!CheckDuplicateMine(mineCoordinate.x, mineCoordinate.y)) {
                    tileArray[mineCoordinate.x][mineCoordinate.y].SetHasMine(true);
                    tileArray[mineCoordinate.x][mineCoordinate.y].CreateMine(mineCoordinate.x, mineCoordinate.y);
                    mineLocations.push_back(mineCoordinate);
                    numberOfMines++;
                    i++;
                }
            }
        }
    }
    else if (mouseClickTest1 || mouseClickTest2 || mouseClickTest3) {
        PlaceTestMines();
    }
}

void Board::DrawTiles() {
    for (int j = 0; j < 16; j++) {
        for (int i = 0; i < 25; i++) {
            tileArray[i][j].DrawTile();
            if (tileArray[i][j].GetNumOn() == true) {
                tileArray[i][j].DrawNum();
            }
            if (tileArray[i][j].GetFlagOn() == true && tileArray[i][j].GetNumOn() != true && tileArray[i][j].GetRevealed() != true && mineClicked != true) {
                tileArray[i][j].CreateFlag(i * 32, j * 32);
                tileArray[i][j].DrawFlag();
            }
        }
    }
}

void Board::RevealMines() {
    for (int j = 0; j < 16; j++) {
        for (int i = 0; i < 25; i++) {
            if (clickDebug == true) {
                if (tileArray[i][j].GetHasMine()) {
                    tileArray[i][j].DrawMine();
                }
            }
            if (mineClicked == true) {
                if (tileArray[i][j].GetHasMine()) {
                    tileArray[i][j].CreateRevealedTile(i * 32, j * 32);
                    tileArray[i][j].DrawMine();
                }
            }
        }
    }
}

bool Board::CheckDuplicateMine(int x, int y) {
    bool hasMine = false;
    if (tileArray[x][y].GetHasMine()) {
        hasMine = tileArray[x][y].GetHasMine();
        return hasMine;
    }
    else {
        return hasMine;
    }
}

void Board::ClearBoard() {
    for (int j = 0; j < 16; j++) {
        for (int i = 0; i < 25; i++) {
            tileArray[i][j].SetHasMine(false);
            tileArray[i][j].SetNumOn(false);
            tileArray[i][j].SetNearbyMinesCount(0);
            tileArray[i][j].SetRevealed(false);
            tileArray[i][j].SetFlagOn(false);
            tileArray[i][j].SetFlagToggle(0);
        }
    }
}


void Board::ConnectTiles() {
    for (int j = 0; j < 16; j++) {
        for (int i = 0; i < 25; i++) {
            Tile* adjacentMines[8];
            if (i == 0 && j == 0) {
                adjacentMines[0] = nullptr;
                adjacentMines[1] = nullptr;
                adjacentMines[2] = nullptr;
                adjacentMines[3] = &tileArray[i + 1][j];
                adjacentMines[4] = &tileArray[i + 1][j + 1];
                adjacentMines[5] = &tileArray[i][j + 1];
                adjacentMines[6] = nullptr;
                adjacentMines[7] = nullptr;
            }
            else if (i == 0 && j == 15) {
                adjacentMines[0] = nullptr;
                adjacentMines[1] = &tileArray[i][j - 1];
                adjacentMines[2] = &tileArray[i + 1][j - 1];
                adjacentMines[3] = &tileArray[i + 1][j];
                adjacentMines[4] = nullptr;
                adjacentMines[5] = nullptr;
                adjacentMines[6] = nullptr;
                adjacentMines[7] = nullptr;
            }
            else if (i == 24 && j == 0) {
                adjacentMines[0] = nullptr;
                adjacentMines[1] = nullptr;
                adjacentMines[2] = nullptr;
                adjacentMines[3] = nullptr;
                adjacentMines[4] = nullptr;
                adjacentMines[5] = &tileArray[i][j + 1];
                adjacentMines[6] = &tileArray[i - 1][j + 1];
                adjacentMines[7] = &tileArray[i - 1][j];
            }
            else if (i == 24 && j == 15) {
                adjacentMines[0] = &tileArray[i - 1][j - 1];
                adjacentMines[1] = &tileArray[i][j - 1];
                adjacentMines[2] = nullptr;
                adjacentMines[3] = nullptr;
                adjacentMines[4] = nullptr;
                adjacentMines[5] = nullptr;
                adjacentMines[6] = nullptr;
                adjacentMines[7] = &tileArray[i - 1][j];
            }
            else if (i == 0 && j != 0 && j != 15) {
                adjacentMines[0] = nullptr;
                adjacentMines[1] = &tileArray[i][j - 1];
                adjacentMines[2] = &tileArray[i + 1][j - 1];
                adjacentMines[3] = &tileArray[i + 1][j];
                adjacentMines[4] = &tileArray[i + 1][j + 1];
                adjacentMines[5] = &tileArray[i][j + 1];
                adjacentMines[6] = nullptr;
                adjacentMines[7] = nullptr;
            }
            else if (i == 24 && j != 0 && j != 15) {
                adjacentMines[0] = &tileArray[i - 1][j - 1];
                adjacentMines[1] = &tileArray[i][j - 1];
                adjacentMines[2] = nullptr;
                adjacentMines[3] = nullptr;
                adjacentMines[4] = nullptr;
                adjacentMines[5] = &tileArray[i][j + 1];
                adjacentMines[6] = &tileArray[i - 1][j + 1];
                adjacentMines[7] = &tileArray[i - 1][j];
            }
            else if (j == 0 && i != 0 && i != 24) {
                adjacentMines[0] = nullptr;
                adjacentMines[1] = nullptr;
                adjacentMines[2] = nullptr;
                adjacentMines[3] = &tileArray[i + 1][j];
                adjacentMines[4] = &tileArray[i + 1][j + 1];
                adjacentMines[5] = &tileArray[i][j + 1];
                adjacentMines[6] = &tileArray[i - 1][j + 1];
                adjacentMines[7] = &tileArray[i - 1][j];
            }
            else if (j == 15 && i != 0 && i != 24) {
                adjacentMines[0] = &tileArray[i - 1][j - 1];
                adjacentMines[1] = &tileArray[i][j - 1];
                adjacentMines[2] = &tileArray[i + 1][j - 1];
                adjacentMines[3] = &tileArray[i + 1][j];
                adjacentMines[4] = nullptr;
                adjacentMines[5] = nullptr;
                adjacentMines[6] = nullptr;
                adjacentMines[7] = &tileArray[i - 1][j];
            }
            else {
                adjacentMines[0] = &tileArray[i - 1][j - 1];
                adjacentMines[1] = &tileArray[i][j - 1];
                adjacentMines[2] = &tileArray[i + 1][j - 1];
                adjacentMines[3] = &tileArray[i + 1][j];
                adjacentMines[4] = &tileArray[i + 1][j + 1];
                adjacentMines[5] = &tileArray[i][j + 1];
                adjacentMines[6] = &tileArray[i - 1][j + 1];
                adjacentMines[7] = &tileArray[i - 1][j];
            }
            tileArray[i][j].SetNeighbors(adjacentMines);
        }
    }
}


void Board::SetNumbers() {
    for (int j = 0; j < 16; j++) {
        for (int i = 0; i < 25; i++) {
            if (!tileArray[i][j].GetHasMine()) {
                tileArray[i][j].CountSurroudingMines();
                tileArray[i][j].CreateNum(i * 32, j * 32);
            }
        }
    }
}

void Board::flagCounter() {
    if (success == true) {
        numberOfFlags = 0;
    }
    string readNumber = to_string(numberOfFlags);
    string number1, number2, number3;
    if (numberOfFlags >= 10) {
        readNumber = "0" + readNumber;
        number1 = readNumber.substr(0, 1);
        number2 = readNumber.substr(1, 1);
        number3 = readNumber.substr(2, 1);
    }
    else if (numberOfFlags > 0 && numberOfFlags < 10) {
        readNumber = "00" + readNumber;
        number1 = readNumber.substr(0, 1);
        number2 = readNumber.substr(1, 1);
        number3 = readNumber.substr(2, 1);
    }
    else if (numberOfFlags == 0) {
        readNumber = "000";
        number1 = readNumber.substr(0, 1);
        number2 = readNumber.substr(1, 1);
        number3 = readNumber.substr(2, 1);
    }
    else if (numberOfFlags < 0 && numberOfFlags > -10) {
        readNumber = to_string(numberOfFlags * -1);
        readNumber = "100" + readNumber;

        number1 = readNumber.substr(0, 2);
        number2 = readNumber.substr(2, 1);
        number3 = readNumber.substr(3, 1);
    }
    else {
        readNumber = to_string(numberOfFlags * -1);
        readNumber = "10" + readNumber;

        number1 = readNumber.substr(0, 2);
        number2 = readNumber.substr(2, 1);
        number3 = readNumber.substr(3, 1);
    }

    int counter = stoi(number1);
    int counter2 = stoi(number2);
    int counter3 = stoi(number3);

    digits.flagNumber(counter, counter2, counter3);
}

void Board::CheckLeftClick(int x, int y) {
    if (y < 512) {
        TileClick(x, y);
    }
    else if (x > 368 && x < 432 && y > 512 && y < 576) {
        resetClicked = true;
    }
    else if (x > 496 && x < 560 && y > 512 && y < 576) {
        clickDebug = true;
        debugToggle++;
    }
    else if (x > 560 && x < 624 && y > 512 && y < 576) {
        LoadTestFile(1);
        mouseClickTest1 = true;
        mouseClickTest2 = false;
        mouseClickTest3 = false;
    }
    else if (x > 624 && x < 688 && y > 512 && y < 576) {
        LoadTestFile(2);
        mouseClickTest1 = false;
        mouseClickTest2 = true;
        mouseClickTest3 = false;
    }
    else if (x > 688 && x < 752 && y > 512 && y < 576) {
        LoadTestFile(3);
        mouseClickTest1 = false;
        mouseClickTest2 = false;
        mouseClickTest3 = true;
    }
}


void Board::TileClick(int x, int y) {
    sf::Vector2i temp;
    temp.x = x / 32;
    temp.y = y / 32;

    if (!tileArray[x / 32][y / 32].GetHasMine() && !mineClicked && !tileArray[x / 32][y / 32].GetFlagOn()) {
        tileArray[x / 32][y / 32].Reveal();
    }
    else if (tileArray[x / 32][y / 32].GetHasMine() && !tileArray[x / 32][y / 32].GetFlagOn() && success != true) {
        mineClicked = true;
    }
}

void Board::LoseGame() {
    DrawTiles();
    RevealMines();
    resetButton.LoadToggle(368, 512, "face_lose");
}

void Board::DebugClick() {
    if (debugToggle % 2 == 0) {
        DrawTiles();
        RevealMines();
    }
    else {
        DrawTiles();
    }
}

void Board::ResetClick() {
    ClearBoard();
    Initialize();
}

void Board::PlaceFlag(int x, int y) {
    int flagToggle = tileArray[x / 32][y / 32].GetFlagToggle();
    if (y < 512 && mineClicked != true && success != true) {
        if (flagToggle % 2 == 0 && !tileArray[x / 32][y / 32].GetRevealed()) {
            tileArray[x / 32][y / 32].SetFlagOn(true);
            numberOfFlags--;
        }
        else if (!tileArray[x / 32][y / 32].GetRevealed()) {
            tileArray[x / 32][y / 32].SetFlagOn(false);
            numberOfFlags++;
        }
        else {

        }
    }
    flagCounter();
}

void Board::HideFlags() {
    for (int j = 0; j < 16; j++) {
        for (int i = 0; i < 25; i++) {
            tileArray[i][j].SetFlagOn(false);
            tileArray[i][j].SetFlagToggle(0);
        }
    }
}

void Board::CheckWin() {
    bool win = true;
    for (int j = 0; j < 16; j++) {
        for (int i = 0; i < 25; i++) {
            if (tileArray[i][j].GetHasMine() == true) {

            }
            else if (tileArray[i][j].GetRevealed() != true) {
                win = false;
            }
            else {

            }
        }
    }
    success = win;
}

void Board::WinGame() {
    resetButton.LoadToggle(368, 512, "face_win");
    DrawAllFlags();
}

void Board::LoadTestFile(int x) {
    if (x == 1) {
        test1.OpenFile(x);
        test1.ReadFile();
        test1.LoadArray(testArray);
    }
    else if (x == 2) {
        test2.OpenFile(x);
        test2.ReadFile();
        test2.LoadArray(testArray);
    }
    else if (x == 3) {
        test3.OpenFile(x);
        test3.ReadFile();
        test3.LoadArray(testArray);
    }
}

void Board::PlaceTestMines() {
    for (int j = 0; j < 16; j++) {
        for (int i = 0; i < 25; i++) {
            if (testArray[i][j] == '1') {
                tileArray[i][j].SetHasMine(true);
                tileArray[i][j].CreateMine(i, j);
                numberOfMines++;
            }
        }
    }
}

void Board::ClearMines() {
    for (int j = 0; j < 16; j++) {
        for (int i = 0; i < 25; i++) {
            if (tileArray[i][j].GetHasMine()) {
                tileArray[i][j].SetHasMine(false);
                numberOfMines--;
            }
        }
    }
}

void Board::DrawAllFlags() {
    for (int j = 0; j < 16; j++) {
        for (int i = 0; i < 25; i++) {
            if (tileArray[i][j].GetHasMine() && !tileArray[i][j].GetFlagOn()) {
                tileArray[i][j].CreateFlag(i * 32, j * 32);
                tileArray[i][j].DrawFlag();
                numberOfFlags--;
            }
        }
    }
}