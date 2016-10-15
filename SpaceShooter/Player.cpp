#include <iostream>
#include "Player.h"

Player::Player()
{
	sprite.setPosition(sf::Vector2f(640, 360));
	if (!texture.loadFromFile("Sprite/Player.png")) {}
	sprite.setTexture(texture);
	sprite.setScale(sf::Vector2f(0.25, 0.25));
	sprite.setOrigin(sf::Vector2f(sprite.getTexture()->getSize().x * 0.5, sprite.getTexture()->getSize().y * 0.5));
}

void Player::update() {
	//std::cout << "Update" << std::endl;
}

void Player::Up() {
	sprite.move(sf::Vector2f(0, -5));
}

void Player::Right() {
	sprite.move(sf::Vector2f(5, 0));
}

void Player::Down() {
	sprite.move(sf::Vector2f(0, 5));
}

void Player::Left() {
	sprite.move(sf::Vector2f(-5, 0));
}


Player::~Player()
{
}
