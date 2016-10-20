#pragma once
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include <iostream>

class CreateWindow
{
public:
	sf::RenderWindow window(sf::VideoMode(int, int));
	CreateWindow();
	~CreateWindow();
};

