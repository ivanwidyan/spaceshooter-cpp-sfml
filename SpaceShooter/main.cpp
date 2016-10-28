#include "SFML\Window.hpp"
#include <iostream>
#include "ObjectManager.h"

int main() {
	srand(time(NULL));
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Alien Invasion", sf::Style::Titlebar | sf::Style::Close);

	// Create an object Manager
	ObjectManager* objectManager = new ObjectManager();

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type==sf::Event::Closed) {
				window.close();
				break;
			}
		}
		window.clear();

		// Update the Object Manager
		objectManager->Update(window);

		window.display();
	}
}
