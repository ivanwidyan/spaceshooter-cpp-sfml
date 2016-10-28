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
		P1_text.setString("Player 1\n" + std::to_string(player1->score));
		window.draw(P1_text);
	}
	else {
		Score_Player1 = player1->score;
		P1_text.setString("Dead\n" + std::to_string(Score_Player1));
		delete player1; 
	}

	// Projectile Player 2 move and spawn
	if (player2->health > 0) {
		player2->Update(window, enemy->enemyList);
		projectilePlayer2->Update();
		projectilePlayer2->Spawn(player2, enemy->enemyList, window);
	}
	else { delete player2; }

	// Display UI Score for Player 1 and PLayer 2
	//player2->ShowUI(window);
}

void ObjectManager::SetUI() {
	// Create text for UI
	if (!font.loadFromFile("Font/BebasNeue.otf")) {}
	P1_text.setFont(font);
	P1_text.setColor(sf::Color::Black);
	P1_text.setCharacterSize(72);
	P2_text.setFont(font);
	P2_text.setColor(sf::Color::Black);
	P2_text.setCharacterSize(72);
}

ObjectManager::~ObjectManager() {
}
