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

sf::RectangleShape Player::PositionPlayer(sf::RectangleShape Player,std::string orientation,int &index)
{
	
	std::vector<sf::Vector2f> listVecteur;
	listVecteur.push_back(sf::Vector2f(300.0f, 180.0f - 64));
	listVecteur.push_back(sf::Vector2f(300.0f, 360.0f - 64));
	listVecteur.push_back(sf::Vector2f(300.0f, 540.0f - 64));
	listVecteur.push_back(sf::Vector2f(300.0f, 720.0f - 64));
	listVecteur.push_back(sf::Vector2f(300.0f, 900.0f - 64));
	if (orientation == "Top" && index>0) 
	{
		index--;
	}
	else if (orientation == "Down" && index < 4)
	{
		index++;
	}
	Player.setPosition(listVecteur[index]);
	return Player;
}
