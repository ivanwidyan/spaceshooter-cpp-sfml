#pragma once

#include "SFML\Graphics.hpp"

class Background
{
public:
	void Update(sf::RenderWindow & window);
	void Looping();
	void SetSpriteTexture(int y);

	Background(int y);
	~Background();

private:
	sf::Sprite backgroundSprite;
	sf::Texture backgroundTexture;
};
