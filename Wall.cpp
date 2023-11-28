#include "Wall.h"

Wall::Wall(float speed)
{
	m_speed = speed;
}


sf::RectangleShape Wall::create(sf::Vector2f vec)
{
	m_position = vec;
	sf::RectangleShape rectangle;
	rectangle.setFillColor(sf::Color::Blue);
	rectangle.setPosition(m_position);
	rectangle.setSize(sf::Vector2f(256, 1080/5));
	return rectangle;
}

sf::Vector2f Wall::setPosition()
{
	Position pos;;
	pos = Position::position1;
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
}

void Wall::draw(sf::RenderWindow& window)
{
	window.draw(create(setPosition()));
}

