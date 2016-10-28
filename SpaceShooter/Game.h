#pragma once

#ifdef _WIN32
#include "SFML\Graphics.hpp"
#endif

#ifdef __unix__
#include <SFML/Graphics.hpp>
#endif

#include "Time.h"
#include "Player.h"
#include "Projectile.h"
#include "Enemy.h"
#include "Background.h"

class Game
{
	public:
	int randRange(int low, int high);
	void Run();
	void SpawnEnemies();

	Game(int totalPlayers);
	~Game();

	private:
	Time time;
	sf::Clock clock;
	sf::RenderWindow* window;
	int totalPlayers;
	Player** players;
	Projectile** projectiles;
	std::vector<Enemy*> enemyList;
	Background* background1;
	Background* background2;

};

