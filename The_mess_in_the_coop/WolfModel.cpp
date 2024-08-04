#include "WolfModel.h"


// ������������ � ����������


WolfModel::WolfModel()
{
	this->initVariable();
	this->initWolf();
	this->initwolfArms();
}

WolfModel::~WolfModel() {};


// ��������� ������


// �������������
void WolfModel::initVariable()
{
	this->leftWolf = true;
	this->upWolfArms = true;
	this->aY = 0;
}

void WolfModel::initWolf()
{
	this->wolfTexture.loadFromFile("Images/player.png");
	this->wolfSprite.setTexture(wolfTexture);
}

void WolfModel::initwolfArms()
{
	this->wolfArmsTexture.loadFromFile("Images/arm.png");
	this->wolfArmsSprite.setTexture(this->wolfArmsTexture);
	this->wolfArmsSprite.setOrigin(54, 47); // ����� ���� ����� ��������� � ������ ��������
}


// ��������� ��������
void WolfModel::update()
{
	this->updateInput();
	this->updateLeftRight();
}

void WolfModel::updateInput()
{
	this->upWolfArms = false; // �������� ���� ���� ������ �������� ����� �� ������
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		this->leftWolf = true;
		this->updateLeftRight();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		this->leftWolf = false;
		this->updateLeftRight();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		this->upWolfArms = true;
		this->updateLeftRight();
	}	
}

void WolfModel::updateLeftRight()
{
	if (this->leftWolf)
	{
		// ����
		this->wolfSprite.setTextureRect(sf::IntRect(0, 0, 134, 201));
		this->wolfSprite.setPosition(360, 200);
		// ������� ��� ������� � ��������� ���
		if (this->upWolfArms && this->leftWolf)
		{
			this->wolfArmsSprite.setRotation(0);
			this->aY = 0;
		}
		else
		{
			this->wolfArmsSprite.setRotation(-30);
			this->aY = 50;
		}
		// ����
		this->wolfArmsSprite.setTextureRect(sf::IntRect(0, 0, 108, 94));
		this->wolfArmsSprite.setPosition(280 + 54, 200 + 47 + this->aY);
	}
	else
	{
		// ����
		this->wolfSprite.setTextureRect(sf::IntRect(134, 0, -134, 201));
		this->wolfSprite.setPosition(510, 200);
		// ������� ��� ������� � ��������� ���
		if (this->upWolfArms && !this->leftWolf)
		{
			this->wolfArmsSprite.setRotation(0);
			this->aY = 0;
		}
		else
		{
			this->wolfArmsSprite.setRotation(30);
			this->aY = 50;
		}
		// ����
		this->wolfArmsSprite.setTextureRect(sf::IntRect(108, 0, -108, 93));
		this->wolfArmsSprite.setPosition(610 + 54, 200 + 47 + this->aY);
	}
	this->positionArm = this->wolfArmsSprite.getPosition();
}

sf::Vector2f WolfModel::returnPosition()
{
	return positionArm;
}


// ����� �� �����


void WolfModel::render(sf::RenderTarget* target)
{
	target->draw(this->wolfSprite);
	target->draw(this->wolfArmsSprite);
}
