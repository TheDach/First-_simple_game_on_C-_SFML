#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

class WolfModel
{
private:

	// Волк
	sf::Texture wolfTexture, wolfArmsTexture;
	sf::Sprite wolfSprite;
	bool leftWolf, upWolfArms;
	sf::Vector2f positionArm;
	int aY;

	// Приватные методы	


	// Инициализации
	void initVariable(); // Инициализация всех переменных для окна
	void initWolf();
	void initwolfArms();


	// Обработка действий
	void updateInput();
	void updateLeftRight();
	void updateUpDown();


public:

	// Деструктор и Конструкторы
	WolfModel();
	~WolfModel();

	sf::Sprite wolfArmsSprite;

	// Обработка действий
	void update();
	sf::Vector2f returnPosition();

	// вывод на экран
	void render(sf::RenderTarget* target);

};

