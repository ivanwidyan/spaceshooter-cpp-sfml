#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include <iostream>
#include "Player.h"

using namespace std;
//Collision
int main() {
	sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML WORK!");

	//Create new player
	Player *player = new Player();
	player->x = 10;
	player->y = 10;

	sf::Sprite background;
	sf::Texture texture_background;
	if (!texture_background.loadFromFile("Sprite/Desert.jpg")) {
		//cout << "Error" << endl;
	}
	background.setTexture(texture_background);

	sf::Clock clock;
	window.setVerticalSyncEnabled(true);
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
			//Keyboard Input
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && player->sprite.getPosition().y > 0) {
				player->Up();
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				player->Left();
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				player->Right();
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				player->Down();
			}
		}

		//Collision Detection
		/*if (pinzoChar.pinzoSprite.getGlobalBounds().intersects(groundSprite.getGlobalBounds())) {
			//cout << "The sprite have collided" << endl;
		}
		else {
			pinzoChar.pinzoSprite.move(sf::Vector2f(0, 5));
		}*/

		sf::Time time = clock.getElapsedTime();
		clock.restart().asSeconds();

		window.clear();

		window.draw(background);
		
		player->update();
		window.draw(player->sprite);

		window.display();
	}
}