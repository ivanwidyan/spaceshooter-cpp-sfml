#pragma once

#ifdef _WIN64
	#include "SFML\Graphics.hpp"
#endif

#ifdef __unix__
	#include <SFML/Graphics.hpp>
#endif

class Enemy
{
public:
	int health = 1;
	float delay = 0;
	std::vector<Enemy*> enemyList;
	sf::Sprite enemySprite;

	int randRange(int low, int high);
	void Update();
	void Spawn(sf::RenderWindow & window);
	void SetSpriteTexture();

	Enemy();
	~Enemy();
private:
	sf::Clock clock;
	sf::Texture enemyTexture;
};
