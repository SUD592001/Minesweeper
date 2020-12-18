#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include "TextureManager.h"
#include "Tile.h"
#include "Reset.h"
#include "TestBoard.h"
#include "Debug.h"
#include "Numbers.h"
#include <random>

using namespace std;

class Board {
private:
	Tile tileArray[25][16];
	Reset resetButton;
	TestBoard test1;
	TestBoard test2;
	TestBoard test3;
	Debug debug;
	Numbers digits;
	sf::RenderWindow* window;
	char testArray[25][16];
	bool mineClicked;
	bool success;
	bool clickDebug;
	bool resetClicked;
	bool mouseClickTest1;
	bool mouseClickTest2;
	bool mouseClickTest3;
	int debugToggle;
	int numberOfFlags;
	int numberOfMines;
	vector<sf::Vector2i> mineLocations;
	int score;

public:
	Board(sf::RenderWindow* win);
	void Initialize();
	void Update();
	void CreateTiles();
	void PlaceMines();
	void DrawTiles();
	void RevealMines();
	bool CheckDuplicateMine(int x, int y);
	void ClearBoard();
	void ConnectTiles();
	void SetNumbers();
	void flagCounter();
	void CheckLeftClick(int x, int y);
	void TileClick(int x, int y);
	void LoseGame();
	void DebugClick();
	void ResetClick();
	void PlaceFlag(int x, int y);
	void HideFlags();
	void CheckWin();
	void WinGame();

	void LoadTestFile(int x);
	void PlaceTestMines();
	void ClearMines();
	void DrawAllFlags();
};