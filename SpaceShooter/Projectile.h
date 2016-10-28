#pragma once
#include "Enemy.h"
#include "Projectile.h"

#ifdef _WIN32
	#include "SFML\Audio.hpp"
	#include "SFML\Window.hpp"
	#include "SFML\Graphics.hpp"
#endif

#ifdef __unix__
	#include <SFML/Graphics.hpp>
	#include <SFML/Window.hpp>
	#include <SFML/Audio.hpp>
#endif

#include "Player.h"

class Player;

class Projectile
{
public:
	Projectile(float speed, std::string texturePath);
	~Projectile();

	bool collide = false;

	void Update();
	void Colliding(Player *player, std::vector<Enemy*> &enemylist, Projectile * projectile);
	sf::Sprite & GetProjectileSprite();

private:
	sf::Texture projectileTexture;
	sf::Sprite projectileSprite;
	float speed;
};
