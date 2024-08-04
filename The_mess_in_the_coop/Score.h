#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Score
{
private:

	sf::Sprite scoreSprite[2];
	sf::Texture scoreTexture;
	int scoreNum[2]; // отвечет за то, что будет на счетчике, какая цыфрв
	

	void initVariable(); // Инициализация всех переменных 
	void initScore(); // Устанавливаем и размещаем счетчик

public:

	int count;

	Score(); 
	~Score();

	void updateScore(); // Изменяем значения счетчика и перемещаемся по картинке
	void renderScore(sf::RenderTarget* target); // выводим счет на экран
};