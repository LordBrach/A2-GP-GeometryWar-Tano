#include "Wall.h"

Wall::Wall(float speed)
{
	m_speed = speed;
}


sf::RectangleShape Wall::create(sf::RectangleShape rectangle, sf::Vector2f vec)
{
	m_position = vec;
	rectangle.setFillColor(sf::Color::Blue);
	rectangle.setPosition(m_position);
	rectangle.setSize(sf::Vector2f(256, 1080/5));
	return rectangle;
}

void Wall::setPosition()
{
}

