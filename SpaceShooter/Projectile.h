#pragma once
#include "Enemy.h"
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
	int playerNum = 0;
	float delay = 0;
	bool collide = false;

	void Update();
	void Spawn(Player * player, std::vector<Enemy*> enemylist, sf::RenderWindow &);
	void Colliding(Player * player, std::vector<Enemy*> enemylist, Projectile * projectile);
	void Start();
	
private:
	sf::Clock clock; // starts the clock
	sf::Texture projectileTexture;
	sf::Sprite projectileSprite;
};

