#pragma once

#ifdef _WIN64
	#include "SFML\Graphics.hpp"
#endif

#ifdef __unix__
	#include <SFML/Graphics.hpp>
#endif

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
