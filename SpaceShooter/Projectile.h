#pragma once

#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include "Player.h"

class Projectile
{
public:

	sf::Sprite projectileSprite;
	int x = 0, y = 0;
	float delay = 0;

	void Colliding(Player);
	void SetSpriteTexture();
	void Spawn(sf::RenderWindow&);

	void Draw();

	Projectile();
	void Update();
	void Spawn(int x, int y, sf::RenderWindow & window);
	~Projectile();

private:

	sf::Clock clock; // starts the clock
	sf::Texture projectileTexture;
};

