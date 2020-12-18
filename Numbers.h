#pragma once

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

using namespace std;

class Numbers {
private:
	TextureManager textMan;
	sf::Sprite firstNumber;
	sf::Sprite secondNumber;
	sf::Sprite thirdNumber;
	sf::RenderWindow* window;
public:
	Numbers();
	void flagNumber(int x, int y, int z);
	void DrawNumbers();
	void SetWindow(sf::RenderWindow* win);
};

