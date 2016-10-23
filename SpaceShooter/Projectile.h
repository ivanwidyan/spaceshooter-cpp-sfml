#pragma once

#include "Projectile.h"
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"
#include "Player.h"

class Projectile
{
public:
	Projectile(Player * player);
	~Projectile();
	
	std::vector<Projectile*> projectileList;
	sf::Sprite projectileSprite;
	int playerNum = 0;
	float delay = 0;
	bool collide = false;

	void Update();
	void Spawn(Player * player, Player * other, sf::RenderWindow & window);
	void Start();

	void Colliding(Player * player, Projectile * projectile);
	

private:
	sf::Clock clock; // starts the clock
	sf::Texture projectileTexture;
};

