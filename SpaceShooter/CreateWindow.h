#pragma once

#ifdef _WIN64
	#include "SFML\Graphics.hpp"
	#include "SFML\Window.hpp"
#endif

#ifdef __unix__
	#include <SFML/Graphics.hpp>
	#include <SFML/Window.hpp>
#endif

#include <iostream>

class CreateWindow
{
public:
	sf::RenderWindow window(sf::VideoMode(int, int));
	CreateWindow();
	~CreateWindow();
};
