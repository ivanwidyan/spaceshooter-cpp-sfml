#include "Time.h"
#include "Projectile.h"
#include "Player.h"
#include "Enemy.h"
#include <iostream>

Projectile::Projectile(float speed, std::string texturePath) {
	this->speed = speed;
	if (!projectileTexture.loadFromFile(texturePath)) {
		std::cout << "Can't load texture" << std::endl;
	}
	projectileTexture.setSmooth(true);
	projectileSprite.setTexture(projectileTexture);
	// Adjusting the size
	projectileSprite.setScale(sf::Vector2f(0.5, 0.5));
	projectileSprite.setOrigin(sf::Vector2f(projectileSprite.getTexture()->getSize().x * 0.5, projectileSprite.getTexture()->getSize().y * 0.5));
}

void Projectile::Update() {
	//projectileSprite.move(sf::Vector2f(0, -3));	// Set the speed of projectile
	projectileSprite.move(sf::Vector2f(0, speed * timesec::deltaTime));		// Set the speed of projectile
} 

void Projectile::Colliding(Player* player, std::vector<Enemy*> &enemylist, Projectile* projectile) {
	// If Colliding with enemy in enemyList, Stop drawing projectile, enemy health - 1, and player score + 100
	for (size_t i=0; i<enemylist.size(); i++){
		if (projectileSprite.getGlobalBounds().intersects(enemylist[i]->enemySprite.getGlobalBounds())) {
			enemylist[i]->health--;
			player->score += 100;
			projectile->collide = false;
			projectile->projectileSprite.setPosition(0, -10);
		}
	}
}

sf::Sprite & Projectile::GetProjectileSprite() {
	return projectileSprite;
}

Projectile::~Projectile()
{
	//std::cout << "Projectile Deleted" << '\n';
}
