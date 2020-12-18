#include "Toggle.h"

Toggle::Toggle() {

}

void Toggle::LoadToggle(int x, int y, string ToggleName) {
	toggle.setTexture(textManager.getTexture(ToggleName));
	toggle.setPosition(x, y);
}

void Toggle::DrawToggle() {
	window->draw(toggle);
}

void Toggle::SetWindow(sf::RenderWindow* victory) {
	window = victory;
}