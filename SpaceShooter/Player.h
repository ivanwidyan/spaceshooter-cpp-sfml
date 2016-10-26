#pragma once

#ifdef _WIN64
	#include "SFML\Graphics.hpp"
#endif

#ifdef __unix__
	#include <SFML/Graphics.hpp>
#endif


class Player
{
public:
	int playerNumber = 0;
	int health = 3;
	int x = 0, y = 0;
	int score = 0;
	sf::Sprite playerSprite;
	sf::Text text;

	void Controls();
	void Colliding();
	void ShowUI(sf::RenderWindow & window);
	void SetSpriteTexture();
	void Update(sf::RenderWindow & window);

	Player(int playerNum);
	~Player();

private:
	std::string status;
	sf::Texture playerTexture;
	sf::Font font;
};
