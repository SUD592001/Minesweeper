#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <map>

using namespace std;

class TextureManager {
private:
	sf::Texture tile_hidden;
	sf::Texture tile_revealed;
	sf::Texture face_happy;
	sf::Texture face_lose;
	sf::Texture face_win;
	sf::Texture test_1;
	sf::Texture test_2;
	sf::Texture test_3;
	sf::Texture debug;
	sf::Texture digits;
	sf::Texture flag;
	sf::Texture mine;
	sf::Texture number_1;
	sf::Texture number_2;
	sf::Texture number_3;
	sf::Texture number_4;
	sf::Texture number_5;
	sf::Texture number_6;
	sf::Texture number_7;
	sf::Texture number_8;
	map<string, sf::Texture> textures;
	map<string, sf::Texture>::iterator iter;

public:
	TextureManager();
	sf::Texture& getTexture(string textureName);

};




