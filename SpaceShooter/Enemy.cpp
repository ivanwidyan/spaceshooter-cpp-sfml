#include "Enemy.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

Enemy::Enemy()
{
	srand(time(NULL));
	enemySprite.setPosition(randRange(50, 1230), -25);
	SetSpriteTexture();
}

void Enemy::Update() {
	enemySprite.move(sf::Vector2f(0, 0.25f));
}

void Enemy::Spawn(sf::RenderWindow& window) {
	sf::Time elapsed1 = clock.getElapsedTime();
	Enemy* enemy = new Enemy();
	if (elapsed1 >= sf::seconds(5)) {
		enemyList.push_back(enemy);
		enemy->enemySprite.setPosition(enemy->randRange(50, 1230), -25);
		clock.restart();
	}

	// For every Projectile in projectileList do
	for (Enemy* enemy : enemyList) {
		if (enemy->health > 0) {
			window.draw(enemy->enemySprite);
			enemy->Update();
		}
		else {
			enemy->enemySprite.setPosition(-50, 0);
		}
	}
}

void Enemy::SetSpriteTexture() {
	// Set Player sprite to Player.png
	if (!enemyTexture.loadFromFile("Sprite/Enemy.png")) {}
	enemyTexture.setSmooth(true);
	enemySprite.setTexture(enemyTexture);
	// Adjusting the Player sprite size and set the origin to the middle
	enemySprite.setScale(sf::Vector2f(0.5, 0.5));
	enemySprite.setOrigin(sf::Vector2f(enemySprite.getTexture()->getSize().x * 0.5, enemySprite.getTexture()->getSize().y * 0.5));
}

int Enemy::randRange(int low, int high) { return rand() % (high - low) + low;}

Enemy::~Enemy()
{
}
