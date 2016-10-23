#pragma once
#include "SFML\Graphics.hpp"

class Background
{
public:
	Background(int y);
	void Update(sf::RenderWindow & window);
	void Looping();
	void SetSpriteTexture(int y);
	~Background();

	sf::Sprite backgroundSprite;

private:
	sf::Texture backgroundTexture;
};

