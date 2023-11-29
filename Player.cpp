#include "Player.h"
#include <SFML/Window.hpp>

void Player::Draw(sf::RenderWindow& window)
{
	
	
	
}

sf::RectangleShape Player::CreatePlayer(sf::RectangleShape player)
{
	player.setPosition(300, 540 - 64);;
	player.setSize(sf::Vector2f(128, 128));
	player.setFillColor(sf::Color::Yellow);
	return player;
}

sf::RectangleShape Player::PositionPlayer(sf::RectangleShape player, sf::Event inputEvent)
{
	if (inputEvent.key.code == sf::Keyboard::A) 
	{
		player.setPosition(sf::Vector2f(300.0f, 180.0f - 64));
	}
	else if (inputEvent.key.code == sf::Keyboard::Z) 
	{
		player.setPosition(sf::Vector2f(300.0f, 360.0f - 64));
	}
	else if (inputEvent.key.code == sf::Keyboard::E)
	{
		player.setPosition(sf::Vector2f(300.0f, 540.0f - 64));
	}
	else if (inputEvent.key.code == sf::Keyboard::R)
	{
		player.setPosition(sf::Vector2f(300.0f, 720.0f - 64));
	}
	else if (inputEvent.key.code == sf::Keyboard::Space)
	{
		player.setPosition(sf::Vector2f(300.0f, 900.0f - 64));
	}
	return player;
}