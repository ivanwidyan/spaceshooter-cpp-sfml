#pragma once
#ifdef _WIN32
	#include "SFML\Graphics.hpp"
	#include "SFML\Audio.hpp"
#endif
#ifdef __unix__
	#include <SFML/Graphics.hpp>
	#include "SFML/Audio.hpp"
#endif
#include "SoundLoader.h"

class Enemy { // Enemy super class
public:
	int health = 1;
	float delay = 0;
	sf::Sprite enemySprite;

	void SetEnemy();
	void Update();
	virtual void Move();
	bool Die();

	Enemy();
	~Enemy();
private:
	sf::Clock clock;
	sf::Texture enemyTexture;
	SoundLoader *soundEnemy = new SoundLoader();
};
