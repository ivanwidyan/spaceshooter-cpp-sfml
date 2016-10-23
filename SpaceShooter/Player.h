#pragma once
#include "SFML\Graphics.hpp"

class Player
{
public:	
	// Declare health of player to 3
	int playerNumber = 0;
	sf::Sprite playerSprite;
	sf::Text text;
	int health = 3;
	int x = 0, y = 0;
	int score = 0;

	// Declare Controls and Shoots functions
	void Controls();
	void Colliding();
	void ShowUI(sf::RenderWindow & window);
	void SetSpriteTexture();

	Player(int playerNum);
	void Update(sf::RenderWindow & window);
	~Player();

private:
	std::string status;
	sf::Texture playerTexture;
	sf::Font font;
};

