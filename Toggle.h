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

class Toggle {
private:
	TextureManager textManager;
	sf::Sprite toggle;
	sf::RenderWindow* window;

public:
	Toggle();
	void LoadToggle(int x, int y, string ButtonName);
	void DrawToggle();
	void SetWindow(sf::RenderWindow* win);
};
