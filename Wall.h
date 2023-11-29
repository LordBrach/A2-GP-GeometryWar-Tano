#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>
enum class Position
{
	position1,
	position2,
	position3,
	position4,
	position5,

};
struct Base
{
	const float tailleY = 1080.f;
	const float Xposition = 1700.f;
	sf::Vector2f base1 = sf::Vector2f(Xposition, 180.0f - 64);
	sf::Vector2f base2 = sf::Vector2f(Xposition, 360.0f - 64);
	sf::Vector2f base3 = sf::Vector2f(Xposition, 540.0f - 64);
	sf::Vector2f base4 = sf::Vector2f(Xposition, 720.0f - 64);
	sf::Vector2f base5 = sf::Vector2f(Xposition, 900.0f - 64);

};
class Wall
{
public:
	Wall(float speed, Position position);
	Wall(Position slot, float speed, int size);
	void setParameter();
	sf::Vector2f setPosition(Position pos);
	void draw(sf::RenderWindow &window);
	void slide(float* deltatime);
	float getSpeed() const
	{
		return m_speed;
	}
	sf::Vector2f getPosition() const
	{
		return m_position;
	}

private:
	float m_speed;
	sf::RectangleShape m_shape;
	sf::Vector2f m_size;
	sf::Vector2f m_position;
	sf::Color m_color;
};