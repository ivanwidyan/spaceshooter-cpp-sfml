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
	int totalPlayers;
	Time time;
	sf::Clock clock;
	sf::RenderWindow* window;
	std::vector<Enemy*> enemyList;
	Player** players;

	Background* background1;
	Background* background2;

};

