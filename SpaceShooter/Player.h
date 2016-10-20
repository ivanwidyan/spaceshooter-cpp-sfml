#pragma once
#include "SFML\Graphics.hpp"

class Player
{
public:	
	// Declare health of player to 3
	sf::Sprite playerSprite;
	int health = 3;
	int x = 0, y = 0;
	int score = 0;

	// Declare Controls and Shoots functions
	void Controls();
	void Shoot();
	void Colliding();
	void SetSpriteTexture();
	void Update();

	Player();
	~Player();

private:
	sf::Texture playerTexture;
};

