#include "Numbers.h"

Numbers::Numbers() {

}

void Numbers::flagNumber(int x, int y, int z) {
	firstNumber.setTexture(textMan.getTexture("digits"));
	firstNumber.setPosition(0, 512);

	secondNumber.setTexture(textMan.getTexture("digits"));
	secondNumber.setPosition(21, 512);

	thirdNumber.setTexture(textMan.getTexture("digits"));
	thirdNumber.setPosition(42, 512);

	sf::IntRect IntRect1 = firstNumber.getTextureRect();
	IntRect1.left = x * 21;
	IntRect1.width = 21;
	firstNumber.setTextureRect(IntRect1);

	sf::IntRect IntRect2 = secondNumber.getTextureRect();
	IntRect2.left = y * 21;
	IntRect2.width = 21;
	secondNumber.setTextureRect(IntRect2);

	sf::IntRect IntRect3 = thirdNumber.getTextureRect();
	IntRect3.left = z * 21;
	IntRect3.width = 21;
	thirdNumber.setTextureRect(IntRect3);
}

void Numbers::DrawNumbers() {
	window->draw(firstNumber);
	window->draw(secondNumber);
	window->draw(thirdNumber);
}

void Numbers::SetWindow(sf::RenderWindow* win) {
	window = win;
}