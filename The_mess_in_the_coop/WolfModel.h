#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

class WolfModel
{
private:

	// ����
	sf::Texture wolfTexture, wolfArmsTexture;
	sf::Sprite wolfSprite;
	bool leftWolf, upWolfArms;
	sf::Vector2f positionArm;
	int aY;

	// ��������� ������	


	// �������������
	void initVariable(); // ������������� ���� ���������� ��� ����
	void initWolf();
	void initwolfArms();


	// ��������� ��������
	void updateInput();
	void updateLeftRight();
	void updateUpDown();


public:

	// ���������� � ������������
	WolfModel();
	~WolfModel();

	sf::Sprite wolfArmsSprite;

	// ��������� ��������
	void update();
	sf::Vector2f returnPosition();

	// ����� �� �����
	void render(sf::RenderTarget* target);

};

