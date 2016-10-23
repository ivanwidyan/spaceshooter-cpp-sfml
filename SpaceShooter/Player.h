#pragma once
#include "SFML\Graphics.hpp"

class Player
{
public:	
	// Declare health of player to 3
	int playerNumber = 0;
	sf::Sprite playerSprite;
	int health = 3;
	int x = 0, y = 0;
	int score = 0;

	// Declare Controls and Shoots functions
	void Controls();
	void GetPlayerPos();
	void Colliding();
	void SetSpriteTexture();
	Player(int playerNum);
	void Update();

	~Player();

private:
	sf::Texture playerTexture;
};

