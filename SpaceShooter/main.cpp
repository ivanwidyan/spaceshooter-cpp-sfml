#ifdef _WIN32
	#include "SFML\Window.hpp"
#endif
#ifdef __unix__
	#include <SFML/Window.hpp>
#endif
#include <iostream>
#include "Game.h"

int main() {
	srand(time(NULL));
	Game startGame(2); // Set the total players to 2
	startGame.Run(); // Run the game
}
