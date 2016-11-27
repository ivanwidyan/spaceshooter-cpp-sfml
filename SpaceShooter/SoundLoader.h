#pragma once

#include "SFML/Audio.hpp"
#include <iostream>

enum SoundName { EnemyDead, PlayerDead, PlayerShoot, Stop };

class SoundLoader
{
public:
	SoundLoader();
	~SoundLoader();

	void LoadSounds();
	void PlaySound(SoundName soundName);
private:
	sf::SoundBuffer SFX_PlayerDead, SFX_Shoot, SFX_EnemyDead;
	sf::Sound player_sound, enemy_sound;
};