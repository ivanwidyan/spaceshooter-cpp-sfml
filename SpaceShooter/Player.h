#pragma once
#include "SFML/Graphics.hpp"

class Player
{
public:
	int x, y, rotation;
	void update();
	void Up();
	void Left();
	void Right();
	void Down();
	sf::Sprite sprite;
	Player();
	~Player();

private:
	sf::Texture texture;
};

