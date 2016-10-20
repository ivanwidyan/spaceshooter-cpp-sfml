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
	Player* player = new Player();
	Projectile* projectile = new Projectile();

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
		
		window.draw(background);
		
		player->Update();
		window.draw(player->playerSprite);
		//window.draw(player->playerSprite);
		/*projectile->Update();
		projectile->Spawn(640, 720, window);
		projectile->Update();
		projectile->Spawn(800, 500, window);*/

		window.display();
	}

}