#include "SoundLoader.h"

SoundLoader::SoundLoader()
{
	LoadSounds();
}

void SoundLoader::LoadSounds()
{
	SFX_EnemyDead.loadFromFile("SFX/invaderexplode.ogg");
	SFX_PlayerDead.loadFromFile("SFX/playerexplode.ogg");
	SFX_Shoot.loadFromFile("SFX/shoot.ogg");
}

void SoundLoader::PlaySound(SoundName soundName)
{
	switch (soundName)
	{
	case EnemyDead:
		enemy_sound.setBuffer(SFX_EnemyDead);
		enemy_sound.play();
		break;
	case PlayerDead:
		player_sound.setBuffer(SFX_PlayerDead);
		player_sound.play();
		break;
	case PlayerShoot:
		player_sound.setBuffer(SFX_Shoot);
		player_sound.play();
		break;
	case Stop:
		player_sound.stop();
		enemy_sound.stop();
		break;
	default:
		break;
	}
}

SoundLoader::~SoundLoader()
{

}