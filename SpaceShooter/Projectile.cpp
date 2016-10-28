#include "Projectile.h"
#include "Player.h"
#include "Enemy.h"
#include <iostream>

Projectile::Projectile(Player* player)
{
	playerNum = player->playerNumber; // Check the player number
	if (player->health > 0) {
		Start();
	}
}

void Projectile::Clear(){
	for (size_t i = 0; i < projectileList.size(); i++) {
	delete projectileList[i];
	}
}

void Projectile::Update() {
	projectileSprite.move(sf::Vector2f(0, -3));} // Set the speed of projectile

void Projectile::Spawn(Player* player, std::vector<Enemy*> &enemylist, sf::RenderWindow& window) {
	Projectile* projectile = new Projectile(player);
	projectile->projectileSprite.setPosition(sf::Vector2f(player->x, player->y -85)); // Set projectile spawn position in front of the player
	sf::Time elapsed1 = clock.getElapsedTime();
	if (elapsed1 >= sf::seconds(0.25f)) { // Spawn projectile every ... seconds
		projectileList.push_back(projectile);
		clock.restart();}

	// For every Projectile in projectileList do
	for (size_t i=0; i<projectileList.size(); i++){
		if (projectileList[i]->collide != true && projectileList[i]->projectileSprite.getPosition().y >= 0) { // if projectile not collide and y position >= 0
			window.draw(projectileList[i]->projectileSprite);
			projectileList[i]->Update();
			projectileList[i]->Colliding(player, enemylist, projectileList[i]);
		}
		else if (projectileList[i]->projectileSprite.getPosition().y <= 0) {
			delete projectileList[i];
			projectileList.erase (projectileList.begin()+i);
		}
	}
}

void Projectile::Colliding(Player* player, std::vector<Enemy*> &enemylist, Projectile* projectile) { // On Collision function for projectile
	// If Colliding with enemy in enemyList, Stop drawing projectile, enemy health - 1, and player score + 100
	for (size_t i=0; i<enemylist.size(); i++){
		if (projectileSprite.getGlobalBounds().intersects(enemylist[i]->enemySprite.getGlobalBounds())) {
			enemylist[i]->health--;
			player->score += 100;
			projectile->collide = false;
			projectile->projectileSprite.setPosition(0, -10);
		}
	}
}

void Projectile::Start() {
	// Set Player sprite to Player.png
	if (playerNum == 1) { if (!projectileTexture.loadFromFile("Sprite/Projectile.png")) {} }
	else if (playerNum == 2) { if (!projectileTexture.loadFromFile("Sprite/Projectile2.png")) {} }
	projectileTexture.setSmooth(true);
	projectileSprite.setTexture(projectileTexture);
	// Adjusting the size
	projectileSprite.setScale(sf::Vector2f(0.5, 0.5));
	projectileSprite.setOrigin(sf::Vector2f(projectileSprite.getTexture()->getSize().x * 0.5, projectileSprite.getTexture()->getSize().y * 0.5));
}

Projectile::~Projectile()
{
	//std::cout << "Projectile Deleted" << '\n';
}
