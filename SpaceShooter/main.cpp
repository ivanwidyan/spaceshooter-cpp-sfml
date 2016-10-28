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

	Game game(2);	//Set the total players to 2
	game.Run();


	/*enemy->Clear();
	projectilePlayer1->Clear();
	projectilePlayer2->Clear();
	if (enemy) delete enemy;
	if (background1) delete background1;
	if (background2) delete background2;
	if (player1) delete player1;
	if (player2) delete player2;
	if (projectilePlayer1) delete projectilePlayer1;
	if (projectilePlayer2) delete projectilePlayer2;*/
}
