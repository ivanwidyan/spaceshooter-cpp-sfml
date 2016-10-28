#include "EnemyHorizontal.h"
#include "Time.h"



EnemyDiagonal::EnemyDiagonal(){
	moveLeft = rand() % 2;
	if (moveLeft) {
		enemySprite.setRotation(45);
	}
	else {
		enemySprite.setRotation(-45);
	}
}

void EnemyDiagonal::Move() {
	enemySprite.move(sf::Vector2f(0, 100.0f * timesec::deltaTime));		//Move y 100 every second
	if (moveLeft) {
		enemySprite.move(sf::Vector2f(-100.0f * timesec::deltaTime, 0));		//Move y 100 every second
		if (enemySprite.getPosition().x <= 0) {
			enemySprite.setRotation(-45);
			moveLeft = false;
		}
	}
	else {
		enemySprite.move(sf::Vector2f(100.0f * timesec::deltaTime, 0));		//Move y 100 every second
		if (enemySprite.getPosition().x >= 1280) {
			enemySprite.setRotation(45);
			moveLeft = true;
		}
	}
}

EnemyDiagonal::~EnemyDiagonal(){
}
