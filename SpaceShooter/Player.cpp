#include <iostream>
#include "Player.h"
#include "Projectile.h"
#include "SFML\Window.hpp"

//void SetSpriteTexture();

Player::Player(int playerNum)
{
	playerNumber = playerNum;
	std::cout << "I'm alive!" << std::endl;
	std::cout << playerNumber << std::endl;
	SetSpriteTexture();
	if (playerNumber == 1){x = 960; y = 540;}
	else if (playerNumber == 2) { x = 320; y = 540; }
}

void Player::Update() {
	playerSprite.setPosition(sf::Vector2f(x, y));
	Controls();
	Colliding();
}

void Player::Controls() {
	//Keyboard Controls Player 1
	if (playerNumber == 1) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { y--; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { x--; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { x++; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) { y++; }
	}
	else if (playerNumber == 2) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { y--; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { x--; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { x++; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { y++; }
	}
}

void Player::GetPlayerPos() {
	int playerPosX, playerPosY;
	//std::cout << "x " << playerSprite.getPosition().x << " y " << playerSprite.getPosition().y << std::endl;
	// TODO Make Projectile class and spawn it
}

void Player::Colliding() {
	// TODO Make a colliding with enemy and projectile
	// if Collide with projectile health --;
}

void Player::SetSpriteTexture() {
	// Set Player position in the middle of the screen
	// Set Player sprite to Player.png
	if (playerNumber == 1) { if (!playerTexture.loadFromFile("Sprite/Player1.png")) {} }
	else if (playerNumber == 2) { if (!playerTexture.loadFromFile("Sprite/Player2.png")) {} }
	//playerTexture.setSmooth(true);
	playerSprite.setTexture(playerTexture);
	// Adjusting the size
	playerSprite.setScale(sf::Vector2f(0.5, 0.5));
	playerSprite.setOrigin(sf::Vector2f(playerSprite.getTexture()->getSize().x * 0.5, playerSprite.getTexture()->getSize().y * 0.5));
}



/* // TODO make the plane invicible for some time
	// Give blink effect
void Player::Invicible() {
sprite.setColor(sf::Color(255, 255, 255, 128));
}
*/

Player::~Player()
{
	std::cout << "I am being deleted" << std::endl;
}
