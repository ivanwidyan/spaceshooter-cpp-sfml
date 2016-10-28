#pragma once

#ifdef _WIN32
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
	sf::Sprite enemySprite;

	void Update();
	virtual void Move();
	bool Die();
	void SetSpriteTexture();

	Enemy();
	~Enemy();
private:
	sf::Clock clock;
	sf::Texture enemyTexture;
};
