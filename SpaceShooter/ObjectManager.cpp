#include "ObjectManager.h"
#include "SFML\Window.hpp"

ObjectManager::ObjectManager() {
}

void ObjectManager::Update(sf::RenderWindow &window) {
	// Draw background
	background1->Update(window);
	background2->Update(window);

	// Spawn Enemies
	enemy->Spawn(window);

	// Projectile Player 1 move and spawn
	if (player1->health > 0) {
		player1->Update(window, enemy->enemyList);
		projectilePlayer1->Update();
		projectilePlayer1->Spawn(player1, enemy->enemyList, window);
	}
	else { delete player1; }

	// Projectile Player 2 move and spawn
	if (player2->health > 0) {
		player2->Update(window, enemy->enemyList);
		projectilePlayer2->Update();
		projectilePlayer2->Spawn(player2, enemy->enemyList, window);
	}
	else { delete player2; }

	// Display UI Score for Player 1 and PLayer 2
	player1->ShowUI(window);
	player2->ShowUI(window);
}


ObjectManager::~ObjectManager() {
}
