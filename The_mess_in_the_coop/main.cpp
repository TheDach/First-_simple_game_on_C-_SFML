#include <SFML/Graphics.hpp>


#include "Game.h"

int main()
{
	// Инициализация игры
	srand(time(NULL));
	Game game;

	// Игровой цикл

	while (game.running())
	{
		// Опрос событий
		game.update();

		// Отображение всей игры
		game.rendering();
	}

	return 0;
}