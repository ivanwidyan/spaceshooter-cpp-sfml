#include "Time.h"
#include "Game.h"
#include "Enemy.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

Enemy::Enemy()
{
	SetSpriteTexture();
}

void Enemy::Update() {
	Move();
	if (enemySprite.getPosition().y > 800) {
		delete this;
	}
}

void Enemy::Move() {
	enemySprite.move(sf::Vector2f(0, 100.0f * timesec::deltaTime));		//Move y 100 every second
}

bool Enemy::Die() {
	if (health > 0) { // Stop drawing and delete if enemy health <= 0
		return false;
	}
	else {
		return true;
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

Enemy::~Enemy()
{
	//std::cout << "Enemy Deleted" << '\n';
	
}
