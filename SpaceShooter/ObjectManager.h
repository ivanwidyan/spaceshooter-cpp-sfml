#pragma once
#include "SFML\Window.hpp"
#include <iostream>
#include "Player.h"
#include "Projectile.h"
#include "Enemy.h"
#include "Background.h"

class ObjectManager
{
public:
	void Update(sf::RenderWindow &window);

	// Create two players
	Player* player1 = new Player(1);
	Player* player2 = new Player(2);
	Projectile* projectilePlayer1 = new Projectile(player1);
	Projectile* projectilePlayer2 = new Projectile(player2);
	
	// Create enemy
	Enemy* enemy = new Enemy();
	
	// Create Background
	Background* background1 = new Background(0);
	Background* background2 = new Background(-720);

	ObjectManager();
	~ObjectManager();
};

