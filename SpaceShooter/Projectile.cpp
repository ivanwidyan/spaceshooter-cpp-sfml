#include "Projectile.h"
#include "Player.h"
#include "SFML\Window.hpp"
#include <iostream>

Projectile::Projectile()
{
	x = 640;
	y = 360;
	SetSpriteTexture();
}

void Projectile::Update() {
	projectileSprite.move(sf::Vector2f(0, -0.1f));
}

void Projectile::Spawn(int xPos, int yPos, sf::RenderWindow& window) {
	x = xPos;
	y = yPos;
	std::cout << x << " " << y << std::endl;
	sf::Time elapsed1 = clock.getElapsedTime();
	if (elapsed1 >= sf::seconds(1.0f)) {
		std::cout << "wow" << std::endl;
		clock.restart();
	}
	window.draw(projectileSprite);
}

void Projectile::Draw() {

}


void Projectile::Colliding(Player player) {
	/*if (projectileSprite.getGlobalBounds().intersects(.getGlobalBounds())) {
		//cout << "The sprite have collided" << endl;
	}*/
}

void Projectile::SetSpriteTexture() {
	// Set Player position in the middle of the screen
	projectileSprite.setPosition(sf::Vector2f(x, y));
	// Set Player sprite to Player.png
	if (!projectileTexture.loadFromFile("Sprite/Projectile.png")) {
		std::cout << "Error" << std::endl;
	}
	projectileTexture.setSmooth(true);
	projectileSprite.setTexture(projectileTexture);
	// Adjusting the size
	//projectileSprite.setScale(sf::Vector2f(0.1, 0.1));
	//projectileSprite.setOrigin(sf::Vector2f(projectileSprite.getTexture()->getSize().x * 0.5, playerSprite.getTexture()->getSize().y * 0.5));
}


Projectile::~Projectile()
{
}
