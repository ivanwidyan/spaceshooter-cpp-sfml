#pragma once
#ifdef _WIN32
	#include "SFML\Graphics.hpp"
	#include "SFML\Audio.hpp"
#endif
#ifdef __unix__
	#include <SFML/Graphics.hpp>
	#include "SFML/Audio.hpp"
#endif

class Enemy
{
public:
	int health = 1;
	float delay = 0;
	sf::Sprite enemySprite;

	void PlaySound();
	void SetEnemy();
	void Update();
	virtual void Move();
	bool Die();

	Enemy();
	~Enemy();
private:
	sf::Clock clock;
	sf::Texture enemyTexture;
};
