#include <iostream>
#include <string>
#include "Player.h"
#include "Enemy.h"
#include "Projectile.h"

Player::Player(int playerNum) {
	playerNumber = playerNum;
	SetSpriteTexture();
	// Set different positions for player 1 and player 2
	if (playerNumber == 1) {x = 320; y = 540;}
	else if (playerNumber == 2){x = 960; y = 540;}
}

void Player::Update(sf::RenderWindow& window, std::vector<Enemy*> &enemylist) {
	if (health > 0) { // Activate all of the Player functions if health > 0
		playerSprite.setPosition(sf::Vector2f(x, y));
		Colliding(enemylist);
		Controls();
		window.draw(playerSprite);
	}
	else {
		playerSprite.setPosition(sf::Vector2f(-640, y));
		status = "Dead\n";
	}
}

void Player::Colliding(std::vector<Enemy*> &enemylist) {
	// If Colliding with enemy in enemyList, Stop drawing projectile, player health - 1, and !visible
	for (size_t i = 0; i<enemylist.size(); i++) {
		if (playerSprite.getGlobalBounds().intersects(enemylist[i]->enemySprite.getGlobalBounds())) {
			health--;
			delete enemylist[i];
			enemylist.erase(enemylist.begin() + i);
		}
	}
}

// TODO make an invicible effect for a second
/*void Player::Invicible() {
	if (viciblecount > 0) {
		if (viciblecount % 10 == 0) {
			playerSprite.setColor(sf::Color(255, 255, 255, 128));
		}
		else {
			playerSprite.setColor(sf::Color(255, 255, 255, 255));
		}
	}
	else {
		visible = true;
	}
	viciblecount--;
}*/

void Player::Controls() {
	//Keyboard Controls for Player 1
	y -= forward; y += back; x -= left; x += right; // Apply the inertia effect on Player x and y
	if (playerNumber == 1) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && y >= 0) {
			back = 0; left = 0; right = 0;
			if (speed <= 1.0) { speed += 0.1; }
			forward = speed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && x >= 0) {
			back = 0; forward = 0; right = 0;
			if (speed <= 1.0) { speed += 0.1; }
			left = speed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && x <= 1280) {
			back = 0; left = 0; forward = 0;
			if (speed <= 1.0) { speed += 0.1; }
			right = speed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && y <= 720) {
			forward = 0; left = 0; right = 0;
			if (speed <= 1.0) { speed += 0.1; }
			back = speed;
		}
		else { Inertia(); } // Start the inertia
	}

	//Keyboard Controls for Player 2
	else if (playerNumber == 2) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && y >= 0) {
			back = 0; left = 0; right = 0;
			if (speed <= 1.0) { speed += 0.1; }
			forward = speed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && x >= 0) {
			back = 0; forward = 0; right = 0;
			if (speed <= 1.0) { speed += 0.1; }
			left = speed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && x <= 1280) {
			back = 0; left = 0; forward = 0;
			if (speed <= 1.0) { speed += 0.1; }
			right = speed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && y <= 720) {
			forward = 0; left = 0; right = 0;
			if (speed <= 1.0) { speed += 0.1; }
			back = speed;
		}
		else { Inertia(); } // Start the inertia
	}
}

void Player::Inertia() { // Give inertia effect to the player sprite
	if (forward > 0 && y >= 0) { forward -= 0.01;}
	else if (back > 0 && y <= 720) { back -= 0.01;}
	else if (left > 0 && x >= 0) { left -= 0.01; }
	else if (right > 0 && x <= 1280) { right -= 0.01; }
	else { forward = 0; back = 0; left = 0; right = 0;	speed = 0; }
}

void Player::ShowUI(sf::RenderWindow& window) { // Set and draw the UI for Player
	text.setString(status + std::to_string(score));
	window.draw(text);
}

void Player::SetSpriteTexture() {
	// Create text for UI
	if (!font.loadFromFile("Font/BebasNeue.otf")) {}
	text.setFont(font);
	text.setColor(sf::Color::Black);
	text.setCharacterSize(72);
	// Set different sprite for player 1 and player 2
	if (playerNumber == 1) {
		if (!playerTexture.loadFromFile("Sprite/Player1.png")) {}
		status = "Player2\n";
		text.setPosition(1075, 0);
	}
	else if (playerNumber == 2) { if (!playerTexture.loadFromFile("Sprite/Player2.png")) {}
		status = "Player1\n";
	}
	playerTexture.setSmooth(true);
	playerSprite.setTexture(playerTexture);

	// Adjusting the Player sprite size and set the origin to the middle
	playerSprite.setScale(sf::Vector2f(0.2, 0.2));
	playerSprite.setOrigin(sf::Vector2f(playerSprite.getTexture()->getSize().x * 0.5, playerSprite.getTexture()->getSize().y * 0.5));
}

Player::~Player() {
	std::cout << "I am being deleted" << std::endl;
}
