#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include "TextureManager.h"
#include "Tile.h"
#include "Toggle.h"

using namespace std;

class TestBoard : public Toggle {
private:
	ifstream activeFile;
	char fileArray[25][16];

public:
	TestBoard();
	void OpenFile(int choice);
	void ReadFile();
	void LoadArray(char(&numbers)[25][16]);
};
