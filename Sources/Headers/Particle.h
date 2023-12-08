#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"

class Particle {
public:
	Particle();

	void update(float dt, Player& joueur);
	void draw(sf::RenderWindow& window);

private:
	sf::RectangleShape shape;
	sf::Vector2f velocity;
};


