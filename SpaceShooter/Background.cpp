#include "Background.h"
#ifdef _WIN32
	#include "SFML\Window.hpp"
#endif

#ifdef __unix__
	#include <SFML/Window.hpp>
#endif
#include <iostream>

Background::Background(int y)
{
	SetSpriteTexture(y);
}

void Background::Update(sf::RenderWindow& window) {
	Looping();
	backgroundSprite.move(sf::Vector2f(0, 0.5f));
	window.draw(backgroundSprite);
}

void Background::Looping() { // Loop the background
	if (backgroundSprite.getPosition().y >= 720) {
		backgroundSprite.setPosition(0, -720);
	}
}

void Background::SetSpriteTexture(int y) {
	// Set background y position by the input
	backgroundSprite.setPosition(0, y);
	// Set Background sprite to grass.jpg
	if (!backgroundTexture.loadFromFile("Sprite/grass.jpg")) {}
	backgroundTexture.setSmooth(true);
	backgroundSprite.setTexture(backgroundTexture);
}

Background::~Background()
{
}
