#include "TextureManager.h"

using namespace std;

TextureManager::TextureManager() {
    tile_hidden.loadFromFile("images/tile_hidden.png");
    tile_revealed.loadFromFile("images/tile_revealed.png");
    face_happy.loadFromFile("images/face_happy.png");
    face_lose.loadFromFile("images/face_lose.png");
    face_win.loadFromFile("images/face_win.png");
    test_1.loadFromFile("images/test_1.png");
    test_2.loadFromFile("images/test_2.png");
    test_3.loadFromFile("images/test_3.png");
    debug.loadFromFile("images/debug.png");
    digits.loadFromFile("images/digits.png");
    flag.loadFromFile("images/flag.png");
    mine.loadFromFile("images/mine.png");
    number_1.loadFromFile("images/number_1.png");
    number_2.loadFromFile("images/number_2.png");
    number_3.loadFromFile("images/number_3.png");
    number_4.loadFromFile("images/number_4.png");
    number_5.loadFromFile("images/number_5.png");
    number_6.loadFromFile("images/number_6.png");
    number_7.loadFromFile("images/number_7.png");
    number_8.loadFromFile("images/number_8.png");

    textures.emplace("tile_hidden", tile_hidden);
    textures.emplace("tile_revealed", tile_revealed);
    textures.emplace("face_happy", face_happy);
    textures.emplace("face_lose", face_lose);
    textures.emplace("face_win", face_win);
    textures.emplace("test_1", test_1);
    textures.emplace("test_2", test_2);
    textures.emplace("test_3", test_3);
    textures.emplace("debug", debug);

    textures.emplace("digits", digits);
    textures.emplace("flag", flag);
    textures.emplace("mine", mine);

    textures.emplace("number_1", number_1);
    textures.emplace("number_2", number_2);
    textures.emplace("number_3", number_3);
    textures.emplace("number_4", number_4);
    textures.emplace("number_5", number_5);
    textures.emplace("number_6", number_6);
    textures.emplace("number_7", number_7);
    textures.emplace("number_8", number_8);

}

sf::Texture& TextureManager::getTexture(string textureKey) {
    iter = textures.begin();
    for (; iter != textures.end(); iter++) {
        if (textureKey == iter->first) {
            return iter->second;
        }
    }
}


