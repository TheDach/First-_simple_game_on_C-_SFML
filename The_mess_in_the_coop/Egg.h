#pragma once

#include "Collision.h"
#include <iostream>

class Egg
{
private:

	// Яйцо
	
	sf::Texture eggTexture, breakEggTexture;
	int alignEgg;
	int alignEgg2;

	// Маска
	sf::Sprite maskLeftSprite, maskRightSprite, maskGroundSprite;
	sf::Texture maskLeftTexture, maskRightTexture, maskGroundTexture;
	

	float speedXLeft, speedXRight, speedY;

	// Инициализация яйца
	void initEgg();
	void initBreakEgg();
	void initMask();
	void initVariable();

	

public:

	// Деструктор и Конструкторы
	Egg();
	~Egg();

	
	sf::Sprite eggSprite;

	// Создания яйца
	void creatEgg(int num);
	void updateEggLeft();
	void updateEggRight();
	bool checkCollision();

	

	// Отрисовка яйца
	void renderEgg(sf::RenderTarget* target);
};
