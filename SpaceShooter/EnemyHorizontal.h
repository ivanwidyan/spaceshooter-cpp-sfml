#pragma once
#include "Enemy.h"
#include "SFML\Graphics.hpp"
class EnemyDiagonal : public Enemy // SubClassEnemy
{
	public:
	void Move();

	EnemyDiagonal();
	~EnemyDiagonal();

	private:
	sf::Texture enemyRed;
	bool moveLeft;
};

