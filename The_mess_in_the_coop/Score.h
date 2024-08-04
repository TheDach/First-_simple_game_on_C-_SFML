#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Score
{
private:

	sf::Sprite scoreSprite[2];
	sf::Texture scoreTexture;
	int scoreNum[2]; // ������� �� ��, ��� ����� �� ��������, ����� �����
	

	void initVariable(); // ������������� ���� ���������� 
	void initScore(); // ������������� � ��������� �������

public:

	int count;

	Score(); 
	~Score();

	void updateScore(); // �������� �������� �������� � ������������ �� ��������
	void renderScore(sf::RenderTarget* target); // ������� ���� �� �����
};