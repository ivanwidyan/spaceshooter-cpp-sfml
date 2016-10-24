#include "Enemy.h"
#include <ctime>
#include <cstdlib>

Enemy::Enemy()
{
	SetSpriteTexture();
}

void Enemy::Update() {
	enemySprite.move(sf::Vector2f(0, 0.5f)); // Move y 0.25 every update
}

void Enemy::Spawn(sf::RenderWindow& window) {
	sf::Time elapsed1 = clock.getElapsedTime();
	Enemy* enemy = new Enemy();
	if (elapsed1 >= sf::seconds(2)) { // Spawn enemy for every ... seconds
		enemyList.push_back(enemy);
		enemy->enemySprite.setPosition(enemy->randRange(50, 1230), -25); // Random position for enemy
		clock.restart();
	}

	// For every enemy in enemyList do
	for (Enemy* enemy : enemyList) {
		if (enemy->health > 0) { // Stop drawing if enemy health <= 0
			window.draw(enemy->enemySprite);
			enemy->Update();
		} else {enemy->enemySprite.setPosition(-50, 0);}
	}
}

void Enemy::SetSpriteTexture() {
	// Set Enemy Sprite
	if (!enemyTexture.loadFromFile("Sprite/Enemy.png")) {}
	enemyTexture.setSmooth(true);
	enemySprite.setTexture(enemyTexture);
	// Adjusting the Enemy Sprite Size and Origin
	enemySprite.setScale(sf::Vector2f(0.5, 0.5));
	enemySprite.setOrigin(sf::Vector2f(enemySprite.getTexture()->getSize().x * 0.5, enemySprite.getTexture()->getSize().y * 0.5));
}

int Enemy::randRange(int low, int high) { return rand() % (high - low) + low;}

Enemy::~Enemy()
{
}
