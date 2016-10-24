#pragma once
#include "SFML\Graphics.hpp"

class Enemy
{
public:
	int health = 1;
	float delay = 0;
	std::vector<Enemy*> enemyList;
	sf::Sprite enemySprite;

	void Update();
	void Spawn(sf::RenderWindow & window);
	void SetSpriteTexture();
	int randRange(int low, int high);
	Enemy();
	~Enemy();
private:
	sf::Clock clock; // starts the clock
	sf::Texture enemyTexture;
};

