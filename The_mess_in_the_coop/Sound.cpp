#include  "Sound.h"

Sound::Sound()
{
	this->initSound();
}

void Sound::initSound()
{
	this->catchBuffer.loadFromFile("Sounds/catch.ogg");
	this->eggBuffer.loadFromFile("Sounds/egg.ogg");
	this->gameoverBuffer.loadFromFile("Sounds/gameover.ogg");
	this->passBuffer.loadFromFile("Sounds/pass.ogg");

	this->catchSound.setBuffer(this->catchBuffer);
	this->eggSound.setBuffer(this->eggBuffer);
	this->gameoverSound.setBuffer(this->gameoverBuffer);
	this->passSound.setBuffer(this->passBuffer);

	this->catchSound.setVolume(this->volume);
	this->eggSound.setVolume(this->volume);
	this->gameoverSound.setVolume(this->volume);
	this->passSound.setVolume(this->volume);
}