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
	int playerNum = 0;
	float delay = 0;

	void Colliding(Player);
	void overScreen();
	void SetSpriteTexture();
	Projectile(Player * player);
	void Update();
	void Spawn(Player* player, sf::RenderWindow & window);
	~Projectile();

private:
	sf::Clock clock; // starts the clock
	sf::Texture projectileTexture;
};

