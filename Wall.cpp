#include "Wall.h"


Wall::Wall(float speed, Position position)
{
	m_speed = speed;
	m_color = sf::Color::Blue;
	m_size = sf::Vector2f(128, 128);
	setPosition(position);
	setParameter();
}

Wall::Wall(Position slot, float speed, int size)
{
	m_size = sf::Vector2f(size, size);
	m_speed = speed;
	setPosition(slot);
	m_color = sf::Color::Red;
	setParameter();
}

void Wall::setParameter()
{
	m_shape.setSize(m_size);
	m_shape.setPosition(m_position);
	m_shape.setFillColor(m_color);
}



void Wall::setPosition(Position pos)
{
	Base base;
	switch (pos)
	{
	case Position::position1:
		m_position = base.base1;
		break;
	case Position::position2:
		m_position = base.base2;
		break;
	case Position::position3:
		m_position = base.base3;
		break;
	case Position::position4:
		m_position = base.base4;
		break;
	case Position::position5:
		m_position = base.base5;
		break;
	default:
		break;
	}
	m_shape.setPosition(m_position);
}


void Wall::draw(sf::RenderWindow& window)
{
	window.draw(m_shape);
}

void Wall::slide(float* deltatime)
{
	m_position.x = m_position.x - m_speed * (*deltatime);
	m_shape.setPosition(m_position);
	std::cout << m_position.x << ", " << m_position.y << std::endl;

}

void Wall::checkCollision(Player joueur)
{
	float playerX;
	float wallX;
	float playerY;
	float wallY;
	playerX = joueur.getPosition().x;
	wallX = m_position.x;
	playerY = joueur.getPosition().y;
	wallY = m_position.y;


	if (wallX <= playerX + 64 && wallX >= playerX - 64 && wallY <= playerY + 64 && wallY >= playerY - 64)
	{
		joueur.m_isAlive = false;
		std::cout << "Player is dead" << std::endl;
	}
}

