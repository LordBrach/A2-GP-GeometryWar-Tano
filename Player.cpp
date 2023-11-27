#include "Player.h"
#include <SFML/Window.hpp>

void Player::Draw(sf::RenderWindow& window)
{
	
	
	
}

sf::RectangleShape Player::CreatePlayer(sf::RectangleShape Player)
{
	Player.setPosition(300, 540 - 64);;
	Player.setSize(sf::Vector2f(128, 128));
	Player.setFillColor(sf::Color::Yellow);
	return Player;
}

sf::RectangleShape Player::PositionPlayer(sf::RectangleShape Player)
{
	while (window.pollEvent(event))
	{
		// check the type of the event...
		switch (event.type)
		{
			// window closed
		case sf::Event::Closed:
			window.close();
			break;

			// key pressed
		case sf::Event::KeyPressed:
			...
				break;

			// we don't process other types of events
		default:
			break;
		}
	}
	std::vector<sf::Vector2f> listVecteur;
	listVecteur.push_back(sf::Vector2f(300.0f, 180.0f - 64));
	listVecteur.push_back(sf::Vector2f(300.0f, 360.0f - 64));
	listVecteur.push_back(sf::Vector2f(300.0f, 540.0f - 64));
	listVecteur.push_back(sf::Vector2f(300.0f, 620.0f - 64));
	listVecteur.push_back(sf::Vector2f(300.0f, 800.0f - 64));

	if ( && index <= 3)
	{
		
		index++;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && index >= 1)
	{
		index--;
	}
	Player.setPosition(listVecteur[index]);
	return Player;
	
}
