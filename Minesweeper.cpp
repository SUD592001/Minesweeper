#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include "Board.h"


using namespace std;

int main(int argc, char* argv[])
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Minesweeper", sf::Style::Close | sf::Style::Titlebar);
    window.setFramerateLimit(30);
    sf::RenderWindow* windowPtr = &window;
    Board board(windowPtr);
    board.Initialize();

    while (window.isOpen())
    {

        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();

            if (event.type == sf::Event::MouseButtonPressed) {

                if (event.mouseButton.button == sf::Mouse::Left) {
                    int xClick = event.mouseButton.x;
                    int yClick = event.mouseButton.y;
                    board.CheckLeftClick(xClick, yClick);
                }

                if (event.mouseButton.button == sf::Mouse::Right) {
                    int xClick = event.mouseButton.x;
                    int yClick = event.mouseButton.y;
                    board.PlaceFlag(xClick, yClick);
                }
            }
        }

        window.clear();
        board.Update();
        window.display();
    }

    return 0;
}
