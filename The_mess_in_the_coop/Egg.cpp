#include "Egg.h"


// Деструктор и Конструкторы
Egg::Egg()
{
	this->initEgg();
	this->initBreakEgg();
	this->initMask();
}

Egg::~Egg() {};


// Инициализации
void Egg::initVariable()
{
	this->speedXRight = 0.f;
	this->speedXLeft = 0.f;
	this->speedY = 0.f;
	this->alignEgg = 0;
	this->alignEgg2 = 0;
}

void Egg::initEgg()
{
	this->eggTexture.loadFromFile("Images/egg.png");
}

void Egg::initBreakEgg()
{
	this->breakEggTexture.loadFromFile("Images/BreakEgg.png");
}

void Egg::initMask()
{
	// Курятник слева
	this->maskLeftTexture.loadFromFile("Images/MaskLeft.png");
	this->maskLeftSprite.setTexture(this->maskLeftTexture);

	// Курятник справа
	this->maskRightTexture.loadFromFile("Images/MaskRight.png");
	this->maskRightSprite.setTexture(this->maskRightTexture);

	// Низ
	this->maskGroundTexture.loadFromFile("Images/MaskGraund.png");
	this->maskGroundSprite.setTexture(this->maskGroundTexture);
}


// Меиоды

void Egg::creatEgg(int num)
{
	this->eggSprite.setTexture(this->eggTexture);
	this->eggSprite.setOrigin(11, 9);
	if (num == 0)
	{
		this->eggSprite.setPosition(200, 165);
	}
	if (num == 1)
	{
		this->eggSprite.setPosition(790, 165);
	}
	if (num == 2)
	{
		this->eggSprite.setPosition(180, 250);
	}
	if (num == 3)
	{
		this->eggSprite.setPosition(790, 257);
	}
	
}

void Egg::updateEggLeft()
{
	// Левые яйца
	if (!Collision::pixelPerfectTest(this->eggSprite, this->maskLeftSprite) && !Collision::pixelPerfectTest(this->eggSprite, this->maskGroundSprite))
	{
		this->alignEgg += 5;
		this->speedY = 0.5f;
		this->eggSprite.setRotation(this->alignEgg);
		this->speedXLeft += 0.1f;
		this->eggSprite.move(this->speedXLeft, this->speedY);
	}
	if (Collision::pixelPerfectTest(this->eggSprite, this->maskLeftSprite))
	{
		this->speedXLeft = 0.1f;
		this->eggSprite.move(this->speedXLeft, this->speedY);
	}

	// Останавливаем падение
	if (Collision::pixelPerfectTest(this->eggSprite, this->maskGroundSprite))
	{
		this->eggSprite.setTexture(this->breakEggTexture);
		this->eggSprite.setRotation(0);
		this->eggSprite.move(0, 0);
		
	}
	this->speedY = 0.f;
	this->speedXLeft = 0.f;
}

void Egg::updateEggRight()
{
	// Правые яйца
	if (!Collision::pixelPerfectTest(this->eggSprite, this->maskRightSprite) && !Collision::pixelPerfectTest(this->eggSprite, this->maskGroundSprite))
	{
		this->alignEgg2 -= 5;
		this->eggSprite.setRotation(this->alignEgg2);
		this->speedY = 0.5f;
		this->speedXRight -= 0.15f;
		this->eggSprite.move(this->speedXRight, this->speedY);
	}
	if (Collision::pixelPerfectTest(this->eggSprite, this->maskRightSprite))
	{
		this->speedXRight = -0.1f;
		this->eggSprite.move(this->speedXRight, this->speedY);
	}

	// Останавливаем падение
	if (Collision::pixelPerfectTest(this->eggSprite, this->maskGroundSprite))
	{
		this->eggSprite.setTexture(this->breakEggTexture);
		this->eggSprite.setRotation(0);
		this->eggSprite.move(0, 0);
	}
	this->speedY = 0.f;
	this->speedXRight = 0.f;
}


bool Egg::checkCollision()
{
	if (Collision::pixelPerfectTest(this->eggSprite, this->maskGroundSprite))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Egg::renderEgg(sf::RenderTarget* target)
{
	target->draw(this->eggSprite);
	//target->draw(this->maskLeftSprite); // потом убрать чтобы ее неотрисовывать
	//target->draw(this->maskRightSprite);
	//target->draw(this->maskGroundSprite);
}