#include "Wall.h"


Wall::Wall(float speed, Position position)
{
	Base base;
	m_speed = speed;
	m_color = sf::Color::Blue;
	m_size = sf::Vector2f(128, 128);
	m_position = setPosition(position);
	m_shape.setSize(m_size);
	m_shape.setPosition(m_position);
	m_shape.setFillColor(m_color);
}


sf::Vector2f Wall::setPosition(Position pos)
{
	Base base;
	switch (pos)
	{
	case Position::position1:
		return base.base1;
		break;
	case Position::position2:
		return base.base2;
		break;
	case Position::position3:
		return base.base3;
		break;
	case Position::position4:
		return base.base4;
		break;
	case Position::position5:
		return base.base5;
		break;
	default:
		break;
	}
	return base.base1;
}

void Wall::draw(sf::RenderWindow& window,Wall wall)
{
	window.draw(wall.m_shape);
}

void Wall::slide(float* deltatime)
{
	m_position.x = m_position.x - m_speed * (*deltatime);
	m_shape.setPosition(m_position);

}

