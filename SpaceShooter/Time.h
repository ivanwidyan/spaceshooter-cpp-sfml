#pragma once

#ifdef _WIN32
#include "SFML\Graphics.hpp"
#endif

#ifdef __unix__
#include <SFML/Graphics.hpp>
#endif

class Time
{
	public:
	void Update();

	Time();
	~Time();

	private:
	sf::Clock clock;
	sf::Clock restartClock;	//Always restarted to get deltaTime
	sf::Time time;
};

//This package handles Time with unit of seconds
namespace timesec {

	extern float timeScale;
	extern float deltaTime;
		
}

