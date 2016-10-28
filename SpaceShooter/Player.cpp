#include "Time.h"
#include <iostream>
#include <string>
#include "Player.h"
#include "Projectile.h"

Player::Player(int playerNum, std::string projectileTexturePath)
{
	playerNumber = playerNum;
	this->projectileTexturePath = projectileTexturePath;
	SetPlayer();
	// Set different positions for player 1 and player 2
	if (playerNumber == 1) {x = 320; y = 540;}
	else if (playerNumber == 2){x = 960; y = 540;}
}

void Player::Update(sf::RenderWindow& window, std::vector<Enemy*> &enemylist) {
	if (health > 0) { // Activate all of the Player functions if health > 0
		Shoot(window, enemylist);
		if (vulnerable) { // If vulnerable do
			playerSprite.setColor(sf::Color(255, 255, 255, 255));
			playerSprite.setPosition(sf::Vector2f(x, y));
			Controls();
			Colliding(enemylist);
			window.draw(playerSprite);
		}
		else { // If !vulnerable do, without colliding enemy
			playerSprite.setPosition(sf::Vector2f(x, y));
			Controls();
			BlinkSprite();
			window.draw(playerSprite);
		}
	}
	else { // If health <= 0
		playerSprite.setPosition(sf::Vector2f(-640, y));
		status = "Dead\n";
	}
}

void Player::Controls() {
	//Keyboard Controls for Player 1
	y -= forward; y += back; x -= left; x += right; // Apply the inertia effect on Player x and y
	if (playerNumber == 1) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && y >= 0) {
			back = 0; left = 0; right = 0;
			if (speed <= 1.0) { speed += 40 * timesec::deltaTime; }
			forward = speed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && x >= 0) {
			back = 0; forward = 0; right = 0;
			if (speed <= 1.0) { speed += 40 * timesec::deltaTime; }
			left = speed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && x <= 1280) {
			back = 0; left = 0; forward = 0;
			if (speed <= 1.0) { speed += 40 * timesec::deltaTime; }
			right = speed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && y <= 720) {
			forward = 0; left = 0; right = 0;
			if (speed <= 1.0) { speed += 40 * timesec::deltaTime; }
			back = speed;
		}
		else { Inertia(); } // Start the inertia for Player 1
	}

	//Keyboard Controls for Player 2
	else if (playerNumber == 2) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && y >= 0) {
			back = 0; left = 0; right = 0;
			if (speed <= 1.0) { speed += 40 * timesec::deltaTime; }
			forward = speed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && x >= 0) {
			back = 0; forward = 0; right = 0;
			if (speed <= 1.0) { speed += 40 * timesec::deltaTime; }
			left = speed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && x <= 1280) {
			back = 0; left = 0; forward = 0;
			if (speed <= 1.0) { speed += 40 * timesec::deltaTime; }
			right = speed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && y <= 720) {
			forward = 0; left = 0; right = 0;
			if (speed <= 1.0) { speed += 40 * timesec::deltaTime; }
			back = speed;
		}
		else { Inertia(); } // Start the inertia for Player 2
	}
}

void Player::Inertia() { // Give inertia effect to the player sprite
	if (forward > 0 && y >= 0) { forward -= 4 * timesec::deltaTime;}
	else if (back > 0 && y <= 720) { back -= 4 * timesec::deltaTime;}
	else if (left > 0 && x >= 0) { left -= 4 * timesec::deltaTime; }
	else if (right > 0 && x <= 1280) { right -= 4 * timesec::deltaTime; }
	else { forward = 0; back = 0; left = 0; right = 0;	speed = 0; }
}

void Player::Colliding(std::vector<Enemy*> &enemylist) { // If Colliding with enemy in enemyList, player health - 1, and !vulnerable
	for (size_t i=0; i<enemylist.size(); i++){
		if (playerSprite.getGlobalBounds().intersects(enemylist[i]->enemySprite.getGlobalBounds())) {
			delete enemylist[i];
			enemylist.erase(enemylist.begin() + i);
			health--;
			vulnerable = false;
		}
	}
}

void Player::ShowUI(sf::RenderWindow& window) { // Set and draw the UI for Player
	text.setString(status + std::to_string(score));
	window.draw(text);
}

void Player::SetPlayer() {
	// Create text for UI
	if (!font.loadFromFile("Font/BebasNeue.otf")) {}
	text.setFont(font);
	text.setColor(sf::Color::Black);
	text.setCharacterSize(72);
	// Set different sprite for player 1 and player 2
	if (playerNumber == 1) {
		if (!playerTexture.loadFromFile("Sprite/Player1.png")) {}
		status = "Player1\n";
	}
	else if (playerNumber == 2) { if (!playerTexture.loadFromFile("Sprite/Player2.png")) {}
		status = "Player2\n";
		text.setPosition(1075, 0);
	}
	playerTexture.setSmooth(true);
	playerSprite.setTexture(playerTexture);
	// Adjusting the Player sprite size and set the origin to the middle
	playerSprite.setScale(sf::Vector2f(0.2, 0.2));
	playerSprite.setOrigin(sf::Vector2f(playerSprite.getTexture()->getSize().x * 0.5, playerSprite.getTexture()->getSize().y * 0.5));
}

void Player::BlinkSprite() { //Blink player sprite 6 times. 
	if (blinkCount < 6) {
		if (blinkCount % 2 != 0) { //Increase Alpha
			spriteAlpha += 400 * timesec::deltaTime;
			if (spriteAlpha >= 255) {
				spriteAlpha = 255;
				blinkCount++;
			}
			playerSprite.setColor(sf::Color(255, 255, 255, spriteAlpha));
		}
		else { //Decrease Alpha
			spriteAlpha -= 400 * timesec::deltaTime;
			if (spriteAlpha <= 50) {
				spriteAlpha = 50;
				blinkCount++;
			}
			playerSprite.setColor(sf::Color(255, 255, 255, spriteAlpha));
		}
	}
	else {
		blinkCount = 0;
		vulnerable = true;
	}
}

void Player::Shoot(sf::RenderWindow& window, std::vector<Enemy*> &enemylist) {
	sf::Time elapsed1 = clock.getElapsedTime();
	if (elapsed1 >= sf::seconds(0.25f)) { // Spawn projectile every ... seconds
		Projectile* projectile = new Projectile(-600, projectileTexturePath);
		projectile->GetProjectileSprite().setPosition(sf::Vector2f(x, y - 85)); // Set projectile spawn position in front of the player
		projectileList.push_back(projectile);
		soundPlayer->PlaySound(PlayerShoot);
		clock.restart();
	}

	// For every Projectile in projectileList do
	for (size_t i = 0; i<projectileList.size(); i++) {
		if (projectileList[i]->collide != true && projectileList[i]->GetProjectileSprite().getPosition().y >= 0) { // if projectile not collide and y position >= 0
			window.draw(projectileList[i]->GetProjectileSprite());
			projectileList[i]->Update();
			projectileList[i]->Colliding(this, enemylist, projectileList[i]);
		}
		else if (projectileList[i]->GetProjectileSprite().getPosition().y <= 0) {
			delete projectileList[i];
			projectileList.erase(projectileList.begin() + i);
		}
	}
}

Player::~Player()
{
}
