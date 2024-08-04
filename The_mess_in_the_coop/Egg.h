#pragma once

#include "Collision.h"
#include <iostream>

class Egg
{
private:

	// ����
	
	sf::Texture eggTexture, breakEggTexture;
	int alignEgg;
	int alignEgg2;

	// �����
	sf::Sprite maskLeftSprite, maskRightSprite, maskGroundSprite;
	sf::Texture maskLeftTexture, maskRightTexture, maskGroundTexture;
	

	float speedXLeft, speedXRight, speedY;

	// ������������� ����
	void initEgg();
	void initBreakEgg();
	void initMask();
	void initVariable();

	

public:

	// ���������� � ������������
	Egg();
	~Egg();

	
	sf::Sprite eggSprite;

	// �������� ����
	void creatEgg(int num);
	void updateEggLeft();
	void updateEggRight();
	bool checkCollision();

	

	// ��������� ����
	void renderEgg(sf::RenderTarget* target);
};
