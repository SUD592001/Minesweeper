#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include "TextureManager.h"
#include "Toggle.h"
#include "Tile.h"

using namespace std;

class Debug : public Toggle {
private:

public:
	Debug();
};
