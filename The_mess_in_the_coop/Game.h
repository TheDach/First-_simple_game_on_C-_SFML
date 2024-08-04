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

	// Окно
	sf::RenderWindow* window; // Обработка самого окна
	sf::Event event; // Обработка событий
	sf::VideoMode videoMode; // Разширение
	sf::Image icon;
	bool game;


	// Приватные методы
	void initVariable(); // Инициализация всех переменных для окна
	void initWindow(); // Создание окна игры
	void initBackgraund(); // Создание заднего фона
	void initIcon(); // Создание иконки
	void createNewEggs(); // оюновляем номер яйца и само яйцо
	void uddateLogic();
	void initGameOver();
	void restartGame();

	// Задний фон
	sf::Texture backgraundTexture;
	sf::Sprite backgraundSprite;


	// Игрок
	WolfModel wolf;
	sf::Vector2f vecPosition; // фактическое расположение рук
	sf::Vector2f vecPositionArm1; // Где может быть положение рук
	sf::Vector2f vecPositionArm2;
	sf::Vector2f vecPositionArm3;
	sf::Vector2f vecPositionArm4;

	// Яйцо
	int const kollEgg = 4;
	Egg egg[4];
	int randEgg;
	int lastEgg;
	int lastDrawEgg;
	int countLoseEgg;


	// Счетчик
	Score score;

	// Звуки
	Sound sound;

	// Проигрыш
	sf::Sprite gameOverSprite, loseSprite[3];
	sf::Texture gameOverTexture, loseTexture;
	
public:

	// Конструктор и Деструктор
	Game();
	~Game();


	//Доступы
	const bool running() const; // Проверка запуска игры


	//Методы
	void pollEvent(); // Опрос событий
	void update(); // Метод вызова опроса событий
	void rendering(); // Отображение всей игры
	
};

