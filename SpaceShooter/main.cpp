#include "SFML\Window.hpp"
#include <iostream>
#include "Player.h"
#include "Projectile.h"
#include "Enemy.h"
#include "Background.h"

int main() {
	srand(time(NULL));
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Alien Invasion", sf::Style::Titlebar | sf::Style::Close);

	//Create two players and projectile
	Player* player1 = new Player(1);
	Player* player2 = new Player(2);
	Projectile* projectilePlayer1 = new Projectile(player1);
	Projectile* projectilePlayer2 = new Projectile(player2);

	// Create enemy
	Enemy* enemy = new Enemy();

	// Create Background
	Background* background1 = new Background(0);
	Background* background2 = new Background(-720);

	sf::Clock frameClock;
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type==sf::Event::Closed)
			{
				window.close();
				break;
			}
		}
		sf::Time frameTime = frameClock.restart();
		window.clear();

		// Draw background
		background1->Update(window);
		background2->Update(window);

		// Projectile Player 1 move and spawn
		projectilePlayer1->Update();
		projectilePlayer1->Spawn(player1, enemy->enemyList, window);

		// Projectile Player 2 move and spawn
		projectilePlayer2->Update();
		projectilePlayer2->Spawn(player2, enemy->enemyList, window);


		// Spawn Enemies
		enemy->Spawn(window);

		// Player 1 and 2 Controll and draw
		player1->Update(window);
		player2->Update(window);

		// Display UI Score for Player 1 and PLayer 2
		player1->ShowUI(window);
		player2->ShowUI(window);

		window.display();
	}
	/*enemy->Clear();
	projectilePlayer1->Clear();
	projectilePlayer2->Clear();
	if (enemy) delete enemy;
	if (background1) delete background1;
	if (background2) delete background2;
	if (player1) delete player1;
	if (player2) delete player2;
	if (projectilePlayer1) delete projectilePlayer1;
	if (projectilePlayer2) delete projectilePlayer2;*/
}
