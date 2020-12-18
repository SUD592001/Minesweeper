#include "Tile.h"

using namespace std;

Tile::Tile() {
    hasMine = false;
    nearbyMines = 0;
    numOn = false;
    revealed = false;
    flagOn = false;
    for (int i = 0; i < 8; i++) {
        neighbors[i] = nullptr;
    }
    flagToggle = 0;
}

void Tile::CreateHiddenTile(int x, int y) {
    tileSprite.setTexture(textManager.getTexture("tile_hidden"));
    tileSprite.setPosition(x, y);
}

void Tile::CreateRevealedTile(int x, int y) {
    tileSprite.setTexture(textManager.getTexture("tile_revealed"));
    tileSprite.setPosition(x, y);
}

void Tile::CreateMine(int x, int y) {
    mineSprite.setTexture(textManager.getTexture("mine"));
    mineSprite.setPosition(x * 32, y * 32);
}

void Tile::CreateNum(int x, int y) {
    if (nearbyMines == 1) {
        numSprite.setTexture(textManager.getTexture("number_1"));
    }
    else if (nearbyMines == 2) {
        numSprite.setTexture(textManager.getTexture("number_2"));
    }
    else if (nearbyMines == 3) {
        numSprite.setTexture(textManager.getTexture("number_3"));
    }
    else if (nearbyMines == 4) {
        numSprite.setTexture(textManager.getTexture("number_4"));
    }
    else if (nearbyMines == 5) {
        numSprite.setTexture(textManager.getTexture("number_5"));
    }
    else if (nearbyMines == 6) {
        numSprite.setTexture(textManager.getTexture("number_6"));
    }
    else if (nearbyMines == 7) {
        numSprite.setTexture(textManager.getTexture("number_7"));
    }
    else if (nearbyMines == 8) {
        numSprite.setTexture(textManager.getTexture("number_8"));
    }
    else {
    }
    numSprite.setPosition(x, y);
}

void Tile::CreateFlag(int x, int y) {
    flagSprite.setTexture(textManager.getTexture("flag"));
    flagSprite.setPosition(x, y);
}


void Tile::DrawTile() {
    window->draw(tileSprite);
}

void Tile::DrawMine() {
    window->draw(mineSprite);
}

void Tile::DrawNum() {
    window->draw(numSprite);
}

void Tile::DrawFlag() {
    window->draw(flagSprite);
}

void Tile::SetWindow(sf::RenderWindow* win) {
    window = win;
}
void Tile::Reveal() {
    if (this->hasMine == true || this->flagOn == true) {

    }
    else if (this->nearbyMines > 0) {
        tileSprite.setTexture(textManager.getTexture("tile_revealed"));
        this->numOn = true;
        this->revealed = true;
    }
    else {
        tileSprite.setTexture(textManager.getTexture("tile_revealed"));
        this->revealed = true;
        for (int i = 0; i < 8; i++) {
            if (neighbors[i] != nullptr && neighbors[i]->GetRevealed() != true) {
                neighbors[i]->Reveal();
            }
        }
    }
}

bool Tile::GetHasMine() {
    return hasMine;
}

void Tile::SetHasMine(bool mineBool) {
    hasMine = mineBool;
}

void Tile::SetNeighbors(Tile* (&tiles)[8]) {
    for (int i = 0; i < 8; i++) {
        neighbors[i] = tiles[i];
    }
}

void Tile::CountSurroudingMines() {
    for (int i = 0; i < 8; i++) {
        if (neighbors[i] != nullptr && neighbors[i]->GetHasMine()) {
            nearbyMines++;
        }
    }
}

void Tile::SetNearbyMinesCount(int mineCount) {
    nearbyMines = mineCount;
}

int Tile::GetNearbyMinesCount() {
    return nearbyMines;
}

void Tile::SetNumOn(bool switchOn) {
    numOn = switchOn;
}

bool Tile::GetNumOn() {
    return numOn;
}

bool Tile::GetRevealed() {
    return revealed;
}

void Tile::SetRevealed(bool reveal) {
    revealed = reveal;
}

bool Tile::GetFlagOn() {
    return flagOn;
}

void Tile::SetFlagOn(bool toggle) {
    flagOn = toggle;
    flagToggle++;
}

void Tile::SetFlagToggle(int value) {
    flagToggle = value;
}

int Tile::GetFlagToggle() {
    return flagToggle;
}