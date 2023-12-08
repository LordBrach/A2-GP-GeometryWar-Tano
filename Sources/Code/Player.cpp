#include "../../Sources/Headers/Player.h"
#include <SFML/Window.hpp>

Player::Player()
{
	m_isAlive = true;
	m_color = sf::Color::Blue;
	m_shape.setFillColor(m_color);
	m_size = sf::Vector2f(128, 128);
	m_shape.setSize(m_size);
	m_position = sf::Vector2f(300.0f, 1080.f * 0.45f);
	m_shape.setPosition(m_position);

}



sf::Vector2f Player::PositionPlayer(sf::Event inputEvent)
{
	if (inputEvent.key.code == sf::Keyboard::A) 
	{
		m_position=sf::Vector2f(300.0f, 1080.f * 0.05f);
	}
	else if (inputEvent.key.code == sf::Keyboard::Z) 
	{
		m_position = sf::Vector2f(300.0f, 1080.f * 0.25f);
	}
	else if (inputEvent.key.code == sf::Keyboard::E)
	{
		m_position = sf::Vector2f(300.0f, 1080.f * 0.45f);
	}
	else if (inputEvent.key.code == sf::Keyboard::R)
	{
		m_position = sf::Vector2f(300.0f, 1080.f * 0.65f);
	}
	else if (inputEvent.key.code == sf::Keyboard::Space)
	{
		m_position = sf::Vector2f(300.0f, 1080.f * 0.85f);
	}
	
	
	m_shape.setPosition(m_position);
	return m_position;
}

void Player::setPosition(sf::Vector2f newPos)
{
	m_position = newPos;
	m_shape.setPosition(m_position);
}


void Player::changePlayerColor(sf::Color newColor)
{
	m_color = newColor;
	m_shape.setFillColor(m_color);
}
