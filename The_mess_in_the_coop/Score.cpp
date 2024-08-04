#include "Score.h"

Score::Score()
{
	this->initVariable();
	this->initScore();
}

Score::~Score() {}



void Score::initVariable()
{
	this->count = 0;
	for (int i = 0; i < 2; i++)
	{
		this->scoreNum[i] = 0;
	}
}

void Score::initScore()
{
	this->scoreTexture.loadFromFile("Images/score.png");
	for (int i = 0; i < 2; i++)
	{
		this->scoreSprite[i].setTexture(this->scoreTexture);
		this->scoreSprite[i].setPosition(670 + 30 * i, 70);
	}
}

void Score::updateScore()
{
	if (this->count < 10)
	{
		this->scoreNum[1] = this->count;
	}
	else 
	{
		this->scoreNum[0] = this->count / 10;
		this->scoreNum[1] = this->count % 10;
	}

	for (int i = 0; i < 2; i++)
		this->scoreSprite[i].setTextureRect(sf::IntRect(25 * this->scoreNum[i], 0, 25, 46));
}

void Score::renderScore(sf::RenderTarget* target)
{
	for (int i = 0; i < 2; i++)
	{
		target->draw(this->scoreSprite[i]);
	}
}