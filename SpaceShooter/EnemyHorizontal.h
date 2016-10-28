#pragma once
#include "Enemy.h"
class EnemyDiagonal :
	public Enemy
{
	public:
	void Move();

	EnemyDiagonal();
	~EnemyDiagonal();

	private:
	bool moveLeft;
};

