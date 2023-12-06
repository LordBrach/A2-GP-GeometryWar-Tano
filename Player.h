#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>

class Player
{
public:
	Player();
	sf::Vector2f PositionPlayer(Player player, sf::Event inputEvent);
	sf::RectangleShape getRectangle() const { return m_shape; }
	sf::Vector2f getPosition() const { return m_position; }
<<<<<<< Updated upstream
=======
	void setPosition(sf::Vector2f newPos);
>>>>>>> Stashed changes
	sf::Color getColor() const { return m_color; }
	bool m_isAlive;
private :
	
	sf::RectangleShape m_shape;
	sf::Vector2f m_position;
	sf::Vector2f m_size;
	sf::Color m_color;
};