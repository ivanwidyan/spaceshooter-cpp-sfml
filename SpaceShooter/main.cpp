#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include <iostream>
#include "Player.h"
#include "Projectile.h"

//Collision
int main() {
	sf::Clock clock; // starts the clock
	sf::Time elapsed1;
	sf::Time delayShoot = sf::seconds(0.01f);

	sf::RenderWindow window(sf::VideoMode(1280, 720), "Space Shooter");
	//Create new player
	Player* player1 = new Player(1);
	Player* player2 = new Player(2);
	Projectile* projectilePlayer1 = new Projectile(player1);
	Projectile* projectilePlayer2 = new Projectile(player2);

	sf::Sprite background;
	sf::Texture texture_background;
	if (!texture_background.loadFromFile("Sprite/Desert.jpg")) {}
	background.setTexture(texture_background);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		}
		window.clear();
		
		// Draw background
		window.draw(background);
		// Projectile Player 1 move and spawn
		projectilePlayer1->Update();
		projectilePlayer1->Spawn(player1, window);

		// Projectile Player 2 move and spawn
		projectilePlayer2->Update();
		projectilePlayer2->Spawn(player2, window);
		
		// Player 2 Controll and draw
		player2->Update();
		window.draw(player2->playerSprite);

		// Player 1 Controll and draw
		player1->Update();
		window.draw(player1->playerSprite);

		window.display();
	}

}