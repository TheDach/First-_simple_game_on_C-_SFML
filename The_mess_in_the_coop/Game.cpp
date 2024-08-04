#include "Game.h"

//����������� � �����������


Game::Game()
{
	this->initVariable();
	this->initWindow();
	this->initBackgraund();
	this->initIcon();
	this->initGameOver();
	this->egg[randEgg].creatEgg(randEgg);
}

Game::~Game()
{
	delete[] this->window;
}


// ��������� ������


void Game::initVariable()
{
	this->window = nullptr;
	this->randEgg = rand() % 4;;
	this->countLoseEgg = 0;
	this->lastDrawEgg = 0;
	this->game = true;
	this->vecPositionArm1.x = 334; this->vecPositionArm1.y = 247; // ������� ��� ��� �� ��������
	this->vecPositionArm2.x = 664; this->vecPositionArm2.y = 247;
	this->vecPositionArm3.x = 334; this->vecPositionArm3.y = 297;
	this->vecPositionArm4.x = 664; this->vecPositionArm4.y = 297;
}

void Game::initWindow()
{
	this->videoMode.height = 500;
	this->videoMode.width = 1000;
	this->window = new sf::RenderWindow(this->videoMode, L"The_mess_in_the_coop", sf::Style::Titlebar | sf::Style::Default); // �������� ���� ����
}

void Game::initBackgraund()
{
	this->backgraundTexture.loadFromFile("Images/fon.png");
	this->backgraundSprite.setTexture(this->backgraundTexture);
}

void Game::initIcon()
{
	this->icon.loadFromFile("Images/lose.png");
	this->window->setIcon(50, 50, icon.getPixelsPtr());
}

void Game::initGameOver()
{
	this->gameOverTexture.loadFromFile("Images/gameover.png");
	this->gameOverSprite.setTexture(this->gameOverTexture);
	this->gameOverSprite.setPosition(380, 120);

	this->loseTexture.loadFromFile("Images/lose.png");
	for (int i = 0; i < 3; i++)
	{
		this->loseSprite[i].setTexture(this->loseTexture);
		this->loseSprite[i].setPosition(400 + 70 * i, 70);
	}
}



// �������


const bool Game::running() const
{
	return this->window->isOpen();
}


// ��������� ������


void Game::pollEvent()
{
	// ����� �������
	while (this->window->pollEvent(this->event))
	{
		switch (this->event.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;

		case sf::Event::KeyPressed:
			if (this->event.key.code == sf::Keyboard::Escape)
			{
				this->window->close();
				break;
			}
		}
	}
}

void Game::update()
{
	if (game)
	{
		this->pollEvent();
		this->wolf.update();
		this->uddateLogic();
		this->score.updateScore();
	}
	if (this->countLoseEgg == 2)
	{
		this->sound.gameoverSound.play();
	}
}

void Game::uddateLogic()
{
	this->vecPosition = wolf.returnPosition(); // �������� ����������� ��������� ��� �����
	/*std::cout << this->vecPosition.x << " " << this->vecPosition.y << " " << randEgg << " ";
	std::cout << this->vecPositionArm1.x << " " << this->vecPositionArm1.y << std::endl;*/

	if (this->egg[randEgg].checkCollision()) // ������� ��
	{
		this->lastDrawEgg = randEgg;
		this->createNewEggs();
		this->score.count--;
		this->countLoseEgg++;
		this->sound.passSound.play();
	}

	if (egg[randEgg].eggSprite.getGlobalBounds().intersects(wolf.wolfArmsSprite.getGlobalBounds())) // �������� �������� ����� ���� � ���������, ����� ��������� �������� �������
	{
		if (randEgg == 0 && vecPosition == vecPositionArm1) // ��������� �������� ��������� ���� � ���
		{
			this->createNewEggs();
		}
		if (randEgg == 2 && vecPosition == vecPositionArm3)
		{
			this->createNewEggs();
		}
		if (randEgg == 1 && vecPosition == vecPositionArm2)
		{
			this->createNewEggs();
		}
		if (randEgg == 3 && vecPosition == vecPositionArm4)
		{
			this->createNewEggs();
		}
		this->sound.catchSound.play();

	}
	if (randEgg == 0 || randEgg == 2)
	{
		this->egg[randEgg].updateEggLeft();
	}
	if (randEgg == 1 || randEgg == 3)
	{
		this->egg[randEgg].updateEggRight();
	}
}

void Game::createNewEggs() // ��������� ����� ���� � ���� ����
{
	lastEgg = randEgg;
	randEgg = rand() % 4;
	this->score.count++;
	while (lastEgg == randEgg) // ��� �� �� ���� ������������� ���
	{
		randEgg = rand() % 4;
	}
	this->egg[randEgg].creatEgg(randEgg);
	this->sound.eggSound.play();
}

void Game::restartGame()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		this->game = true;
		this->countLoseEgg = 0;
		this->score.count = 0;
	}
}

void Game::rendering()
{
	/*
		- ������� ������� �����
		- ��������� �������
		- ����� ����� �� �����

		��������� �������� � ����
	*/

	// ��������� �����
	this->window->clear(); // ������� ��� ���������� �������, �� ���� ������� � ��������� ���������
	

	// ������ ��� �������
	this->window->draw(backgraundSprite);
	this->wolf.render(this->window);
	this->score.renderScore(this->window); // ��������� �����
	this->egg[lastDrawEgg].renderEgg(this->window);
	this->egg[randEgg].renderEgg(this->window);
	//for (int i = 0; i < kollEgg; i++) // ��������� ���
	//{
	//	this->egg[i].renderEgg(this->window);
	//}
	if (this->countLoseEgg == 3)
	{
		this->game = false; // ������� ��� ������� ���� ��������
		this->window->draw(this->gameOverSprite); // ��������� ���������
	}
	for (int i = 0; i < this->countLoseEgg; i++) // ������������ ���-�� ������������ ���
	{
		this->window->draw(this->loseSprite[i]);
	}
	

	this->window->display(); // ������ � o��� �� ��� �����������
}
