#include "Projectile.h"
#include "Player.h"
#include "Enemy.h"
#include "SFML\Window.hpp"
#include <iostream>

Projectile::Projectile(Player* player)
{
	playerNum = player->playerNumber;
	Start();
}

void Projectile::Update() {
	// Set Player position by the x and y of the screen
	projectileSprite.move(sf::Vector2f(0, -2));}

void Projectile::Spawn(Player* player, Enemy* enemy, sf::RenderWindow& window) {
	int xPos = player->x;
	int yPos = player->y;
	Projectile* projectile = new Projectile(player);
	projectile->projectileSprite.setPosition(sf::Vector2f(xPos, yPos-85));
	sf::Time elapsed1 = clock.getElapsedTime();
	if (elapsed1 >= sf::seconds(0.5f)) {
		projectileList.push_back(projectile);
		clock.restart();}

	// For every Projectile in projectileList do
	for (Projectile* projectile : projectileList) {
		if (projectile->collide != true && projectile->projectileSprite.getPosition().y >= 25) {
			window.draw(projectile->projectileSprite);
			projectile->Update();
			projectile->Colliding(enemy, projectile);
		}
	}
}

void Projectile::Colliding(Enemy* enemy, Projectile* projectile) {
	if (projectileSprite.getGlobalBounds().intersects(enemy->enemySprite.getGlobalBounds())) {
		enemy->health -= 1;
		std::cout << enemy->health << std::endl;
		projectile->collide = false;
		projectile->projectileSprite.setPosition(0, -10);
	}
}

void Projectile::Start() {
	// Set Player sprite to Player.png
	if (playerNum == 1) { if (!projectileTexture.loadFromFile("Sprite/Projectile.png")) {} }
	else if (playerNum == 2) { if (!projectileTexture.loadFromFile("Sprite/Projectile2.png")) {} }
	projectileTexture.setSmooth(true);
	projectileSprite.setTexture(projectileTexture);
	// Adjusting the size
	projectileSprite.setScale(sf::Vector2f(0.5, 0.5));
	projectileSprite.setOrigin(sf::Vector2f(projectileSprite.getTexture()->getSize().x * 0.5, projectileSprite.getTexture()->getSize().y * 0.5));
}

Projectile::~Projectile()
{
	std::cout << "I'm deleted" << std::endl;
}
