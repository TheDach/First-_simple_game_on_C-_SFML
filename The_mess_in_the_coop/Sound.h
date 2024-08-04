#pragma once

#include "SFML/Audio.hpp"

class Sound
{
private:

	sf::SoundBuffer catchBuffer, eggBuffer, gameoverBuffer, passBuffer;
	float volume = 30.f;

	void initSound();

public:

	sf::Sound catchSound, eggSound, gameoverSound, passSound;

	Sound();
	~Sound() {};
};