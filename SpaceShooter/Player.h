#pragma once
#ifdef _WIN32
	#include "SFML\Graphics.hpp"
#endif
#ifdef __unix__
	#include <SFML/Graphics.hpp>
#endif
#include "Enemy.h"
#include "Projectile.h"

class Projectile;

class Player
{
public:
	int playerNumber = 0;
	int health = 3;
	int score = 0;
	float x = 0, y = 0;
	float speed = 0;
	bool vulnerable = true;
	sf::Sprite playerSprite;
	sf::Text text;

	void Controls();
	void Inertia();
	void BlinkSprite();
	void Colliding(std::vector<Enemy*> &enemylist);
	void ShowUI(sf::RenderWindow & window);
	void SetSpriteTexture();
	void Update(sf::RenderWindow & window,std::vector<Enemy*> &enemylist);
	void Shoot(sf::RenderWindow& window, std::vector<Enemy*> &enemylist);

	Player(int playerNum, std::string projectileTexturePath);
	~Player();

private:
	sf::Texture playerTexture;
	sf::Font font;
	sf::Clock clock; // Starts the clock
	std::string status;
	int blinkCount = 0;
	float forward = 0, back = 0, left = 0, right = 0;
	float spriteAlpha = 255;

	std::vector<Projectile*> projectileList;
	std::string projectileTexturePath;
};
