#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include "TextureManager.h"

using namespace std;

class Tile {
private:
	TextureManager textManager;
	sf::Sprite tileSprite;
	sf::Sprite mineSprite;
	sf::Sprite numSprite;
	sf::Sprite flagSprite;
	sf::RenderWindow* window;
	bool hasMine;
	bool numOn;
	bool revealed;
	bool flagOn;
	int flagToggle;
	Tile* neighbors[8];
	int nearbyMines;
public:
	Tile();
	void CreateHiddenTile(int x, int y);
	void CreateRevealedTile(int x, int y);
	void CreateMine(int x, int y);
	void CreateNum(int x, int y);
	void CreateFlag(int x, int y);
	void DrawTile();
	void DrawMine();
	void DrawNum();
	void DrawFlag();
	void SetWindow(sf::RenderWindow* win);
	void Reveal();
	bool GetHasMine();
	void SetHasMine(bool mineBool);
	void SetNeighbors(Tile* (&tiles)[8]);
	void CountSurroudingMines();
	void SetNearbyMinesCount(int mineCount);
	int GetNearbyMinesCount();
	void SetNumOn(bool switchOn);
	bool GetNumOn();
	bool GetRevealed();
	void SetRevealed(bool reveal);
	bool GetFlagOn();
	void SetFlagOn(bool toggle);
	void SetFlagToggle(int value);
	int GetFlagToggle();
};
