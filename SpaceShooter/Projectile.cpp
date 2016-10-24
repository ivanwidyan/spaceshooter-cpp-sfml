#include "Projectile.h"
#include "Player.h"
#include "Enemy.h"
#include <iostream>

Projectile::Projectile(Player* player)
{
	playerNum = player->playerNumber; // Check the player number
	Start();
}

void Projectile::Update() {
	projectileSprite.move(sf::Vector2f(0, -3));} // Set the speed of projectile

void Projectile::Spawn(Player* player, std::vector<Enemy*> enemylist, sf::RenderWindow& window) {
	Projectile* projectile = new Projectile(player);
	projectile->projectileSprite.setPosition(sf::Vector2f(player->x, player->y -85)); // Set projectile spawn position in front of the player
	sf::Time elapsed1 = clock.getElapsedTime();
	if (elapsed1 >= sf::seconds(0.25f)) { // Spawn projectile every ... seconds
		projectileList.push_back(projectile);
		clock.restart();}

	// For every Projectile in projectileList do
	for (Projectile* projectile : projectileList) {
		if (projectile->collide != true && projectile->projectileSprite.getPosition().y >= 0) { // if projectile not collide and y position >= 0
			window.draw(projectile->projectileSprite);
			projectile->Update();
			projectile->Colliding(player, enemylist, projectile);
		}
	}
}

void Projectile::Colliding(Player* player, std::vector<Enemy*> enemylist, Projectile* projectile) {
	// If Colliding with enemy in enemyList, Stop drawing projectile, enemy health - 1, and player score + 100
	for (Enemy* enemy : enemylist){
		if (projectileSprite.getGlobalBounds().intersects(enemy->enemySprite.getGlobalBounds())) {
			enemy->health--;
			player->score += 100;
			projectile->collide = false;
			projectile->projectileSprite.setPosition(0, -10);
		}
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
}
