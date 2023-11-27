#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
enum class Stab
{


};
struct Base
{
	const float tailleY = 1080.f;
	const float Xposition = 1700.f;
	sf::Vector2f base0 = sf::Vector2f(Xposition, 0);
	sf::Vector2f base1 = sf::Vector2f(Xposition, tailleY / 4.f);
	sf::Vector2f base2 = sf::Vector2f(Xposition, tailleY / 2.f);
	sf::Vector2f base3 = sf::Vector2f(Xposition, tailleY - 256);
	sf::Vector2f base4 = sf::Vector2f(tailleY / 1.f, Xposition);

};
class Wall
{
public:
	Wall(float speed);
	sf::RectangleShape create(sf::RectangleShape rectangle, sf::Vector2f vec);
	void setPosition();
	float GetSpeed() const
	{
		return m_speed;
	}
private:
	float m_speed;
	sf::Vector2f m_position;
};