#include "Projectile.h"
#include "Player.h"
#include "SFML\Window.hpp"
#include <iostream>

Projectile::Projectile(Player* player)
{
	playerNum = player->playerNumber;
	SetSpriteTexture();
}

void Projectile::Update() {
	// Set Player position by the x and y of the screen
	projectileSprite.move(sf::Vector2f(0, -2));
}

void Projectile::Spawn(Player* player, sf::RenderWindow& window) {
	int xPos = player->x;
	int yPos = player->y;
	Projectile* projectile = new Projectile(player);
	projectile->projectileSprite.setPosition(sf::Vector2f(xPos, yPos));
	sf::Time elapsed1 = clock.getElapsedTime();
	if (elapsed1 >= sf::seconds(0.5f)) {
		projectileList.push_back(*projectile);
		clock.restart();
	}
	for (auto& projectile : projectileList) {
		window.draw(projectile.projectileSprite);
		projectile.Update();
	}
}

void Projectile::Colliding(Player player) {
	/*if (projectileSprite.getGlobalBounds().intersects(.getGlobalBounds())) {
		//cout << "The sprite have collided" << endl;
	}*/
}

void Projectile::overScreen() {
	
}

void Projectile::SetSpriteTexture() {
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
