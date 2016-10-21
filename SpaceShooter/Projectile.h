#pragma once

#include "Projectile.h"
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include "Player.h"

class Projectile
{
public:
	std::vector<Projectile> projectileList;
	sf::Sprite projectileSprite;
	int x = 0, y = 0;
	float delay = 0;

	void Colliding(Player);
	void SetSpriteTexture();

	void Draw();

	Projectile();
	void Update();
	void Spawn(Player* player, sf::RenderWindow & window);
	~Projectile();

private:
	sf::Clock clock; // starts the clock
	sf::Texture projectileTexture;
};

