#include "Player.h"
#include <SFML/Window.hpp>

Player::Player() 
{
	m_isAlive = true;
	m_color = sf::Color::Yellow;
	m_shape.setFillColor(m_color);
	m_size = sf::Vector2f(128, 128);
	m_shape.setSize(m_size);
	m_position = sf::Vector2f(300, 540 - 64);
	m_shape.setPosition(m_position);

}


sf::Vector2f Player::PositionPlayer(Player player, sf::Event inputEvent)
{
	if (inputEvent.key.code == sf::Keyboard::A) 
	{
		m_position=sf::Vector2f(300.0f, 180.0f - 64);
	}
	else if (inputEvent.key.code == sf::Keyboard::Z) 
	{
		m_position = sf::Vector2f(300.0f, 360.0f - 64);
	}
	else if (inputEvent.key.code == sf::Keyboard::E)
	{
		m_position = sf::Vector2f(300.0f, 540.0f - 64);
	}
	else if (inputEvent.key.code == sf::Keyboard::R)
	{
		m_position = sf::Vector2f(300.0f, 720.0f - 64);
	}
	else if (inputEvent.key.code == sf::Keyboard::Space)
	{
		m_position = sf::Vector2f(300.0f, 900.0f - 64);
	}
	m_shape.setPosition(m_position);
	return m_position;
}