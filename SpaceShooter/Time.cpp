#include "Time.h"

namespace timesec {
	float deltaTime = 0;
	float timeScale = 1;
}

Time::Time()
{
}

void Time::Update() {
	time = restartClock.restart();	//Set the deltaTime value on each frame
	timesec::deltaTime = time.asSeconds() * timesec::timeScale;
}

Time::~Time()
{
}