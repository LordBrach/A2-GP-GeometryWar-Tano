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
	//std::cout << m_position.x << ", " << m_position.y << std::endl;

}

void Wall::checkCollision(Player joueur)
{
	float playerSide = 128.f;
	if (m_position.x <= joueur.getPosition().x + 128 && m_position.x >= joueur.getPosition().x - 128 && joueur.m_isAlive == true)
	{
		float playerMaxX = joueur.getPosition().x + playerSide / 2;
		float playerMinX = joueur.getPosition().x - playerSide / 2;
		float playerMaxY = joueur.getPosition().y - playerSide / 2;
		float playerMinY = joueur.getPosition().y + playerSide / 2;

		float wallMaxX = m_position.x + m_size.x / 2;
		float wallMinX = m_position.x - m_size.x / 2;
		float wallMaxY = m_position.y - m_size.y / 2;
		float wallMinY = m_position.y + m_size.y / 2;

		if (playerMaxX >= wallMinX && playerMaxX <= wallMaxX && playerMaxY <= wallMinY && playerMaxY >= wallMaxY)
		{
			std::cout << "hello" << std::endl;
			joueur.m_isAlive = false;
		}

	}


}

