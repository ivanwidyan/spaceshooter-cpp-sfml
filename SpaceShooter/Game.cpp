#include "Game.h"
#include "Time.h"
#include <string>
#include "Player.h"
#include "Projectile.h"
#include "Enemy.h"
#include "EnemyHorizontal.h"
#include "Background.h"

Game::Game(int totalPlayers = 1) {
	window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Alien Invasion", sf::Style::Titlebar | sf::Style::Close);
	this->totalPlayers = totalPlayers;
	//Create players and projectiles
	players = new Player*[totalPlayers];
	for (int i = 0; i < totalPlayers; i++) {
		std::string path = "Sprite/Projectile" + std::to_string(i + 1);
		path += ".png";
		players[i] = new Player(i + 1, path);
	}

	// Create Background
	background1 = new Background(0);
	background2 = new Background(-720);

	// Create a Lose Screen
	if (!font.loadFromFile("Font/BebasNeue.otf")) {}
	GameOver.setFont(font);
	GameOver.setColor(sf::Color::White);
	GameOver.setCharacterSize(72);
	GameOver.setPosition(640, 360);
	GameOver.setString("You Lose!");
}

void Game::Run() { // Run game function
	while (window->isOpen()) {
		time.Update();
		sf::Event event;
		while (window->pollEvent(event)) {
			if (event.type == sf::Event::Closed)
			{
				window->close();
				break;
			}
		}
		if (players[0]->health > 0 || players[1]->health > 0) {
			window->clear();
			// Draw background
			background1->Update(*window);
			background2->Update(*window);
			// Spawn Enemies
			SpawnEnemies();
			for (int i = 0; i < totalPlayers; i++) {
				players[i]->Update(*window, enemyList); // Player Controlls and draw
				players[i]->ShowUI(*window); // Display UI Score for each Players
			}
			window->display();
		}
		else {
			window->clear();
			window->draw(GameOver); // Show Lose Screen
			window->display();
		}
	}
}

void Game::SpawnEnemies() {
	sf::Time elapsed1 = clock.getElapsedTime();
	if (elapsed1 >= sf::seconds(2)) { // Spawn enemy for every ... seconds
		Enemy* enemy;
		int randomEnemy = randRange(0, 2);
		if (randomEnemy == 0) {
			enemy = new Enemy();
		}
		else {
			enemy = new EnemyDiagonal();
		}	
		enemyList.push_back(enemy);
		enemy->enemySprite.setPosition(randRange(50, 1230), -25); // Random position for enemy
		clock.restart();
	}

	// For every enemy in enemyList do
	for (size_t i = 0; i<enemyList.size(); i++) {
		enemyList[i]->Update();
		if (!enemyList[i]->Die()) { // Check whether enemy is dead or not
			window->draw(enemyList[i]->enemySprite);
		}
		else { // Delete enemy
			enemyList.erase(enemyList.begin() + i);
		}
	}
}

int Game::randRange(int low, int high) { return rand() % (high - low) + low; }

Game::~Game() { // Clean up all unused items, FREE THE MEMORY!
	delete background1;
	delete background2;
	delete window;
	for (int i = 0; i < totalPlayers; i++) {
		delete[] players[i];
	}
	delete [] players;
	for (size_t i = 0; i < enemyList.size(); i++) {
		delete enemyList[i];
		enemyList.erase(enemyList.begin() + i);
	}
}