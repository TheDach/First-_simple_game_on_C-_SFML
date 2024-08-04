#pragma once

#include "WolfModel.h"
#include "Egg.h"
#include "Score.h"
#include "Sound.h"

#include <time.h>
#include <iostream>

class Game
{
private:

	// ����
	sf::RenderWindow* window; // ��������� ������ ����
	sf::Event event; // ��������� �������
	sf::VideoMode videoMode; // ����������
	sf::Image icon;
	bool game;


	// ��������� ������
	void initVariable(); // ������������� ���� ���������� ��� ����
	void initWindow(); // �������� ���� ����
	void initBackgraund(); // �������� ������� ����
	void initIcon(); // �������� ������
	void createNewEggs(); // ��������� ����� ���� � ���� ����
	void uddateLogic();
	void initGameOver();
	void restartGame();

	// ������ ���
	sf::Texture backgraundTexture;
	sf::Sprite backgraundSprite;


	// �����
	WolfModel wolf;
	sf::Vector2f vecPosition; // ����������� ������������ ���
	sf::Vector2f vecPositionArm1; // ��� ����� ���� ��������� ���
	sf::Vector2f vecPositionArm2;
	sf::Vector2f vecPositionArm3;
	sf::Vector2f vecPositionArm4;

	// ����
	int const kollEgg = 4;
	Egg egg[4];
	int randEgg;
	int lastEgg;
	int lastDrawEgg;
	int countLoseEgg;


	// �������
	Score score;

	// �����
	Sound sound;

	// ��������
	sf::Sprite gameOverSprite, loseSprite[3];
	sf::Texture gameOverTexture, loseTexture;
	
public:

	// ����������� � ����������
	Game();
	~Game();


	//�������
	const bool running() const; // �������� ������� ����


	//������
	void pollEvent(); // ����� �������
	void update(); // ����� ������ ������ �������
	void rendering(); // ����������� ���� ����
	
};

