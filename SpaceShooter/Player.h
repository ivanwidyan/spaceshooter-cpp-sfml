#pragma once
#include "SFML\Graphics.hpp"
#include "Enemy.h"
#include <iostream>

class Player
{
public:
	int playerNumber = 0;
	int health = 3;
	float x = 0, y = 0;
	float speed = 0;
	int score = 0;
	sf::Sprite playerSprite;

	void Controls();
	void Inertia();
	void Score();
	void Invicible();
	void SetSpriteTexture();
	void Colliding(std::vector<Enemy*>& enemylist);

	Player(int playerNum);
	void Update(sf::RenderWindow & window, std::vector<Enemy*>& enemylist);
	~Player();

private:
	float forward = 0, back = 0, left = 0, right = 0;
	sf::Texture playerTexture;
	sf::Font font;
};
