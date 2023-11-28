#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>

class Player
{
public:
	void Draw(sf::RenderWindow& window);
	int index = 2;
	sf::RectangleShape CreatePlayer(sf::RectangleShape Player);
	//sf::RectangleShape PositionPlayer(sf::RectangleShape Player,std::string orientation,int &index);
	sf::RectangleShape PositionPlayer(sf::RectangleShape Player, int index);
};