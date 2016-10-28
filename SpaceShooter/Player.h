#pragma once

#ifdef _WIN32
	#include "SFML\Graphics.hpp"
#endif

#ifdef __unix__
	#include <SFML/Graphics.hpp>
#endif
#include "Enemy.h"

class Player
{
public:
	int playerNumber = 0;
	int health = 3;
	int viciblecount;
	bool visible = true;
	float x = 0, y = 0;
	float speed = 0;
	int score = 0;
	sf::Sprite playerSprite;
	sf::Text text;

	void Controls();
	void Inertia();
	void Invicible();
	void Colliding(std::vector<Enemy*> &enemylist);
	void ShowUI(sf::RenderWindow & window);
	void SetSpriteTexture();
	void Update(sf::RenderWindow & window,std::vector<Enemy*> &enemylist,sf::Time deltaTime);

	Player(int playerNum);
	~Player();

private:
	float forward = 0, back = 0, left = 0, right = 0;
	std::string status;
	sf::Time m_frameTime;
	sf::Time m_currentTime;
	sf::Texture playerTexture;
	sf::Font font;
};
