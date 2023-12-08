#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#pragma once
#include "../../Sources/Headers/header_library.h"

sf::Text A, Z, E, R, V;
sf::Font font;
std::vector<sf::Text> listText = { A, Z, E, R, V };

void InitializeInputText(Player& joueur)
{
	sf::Text Letter;
	float Heigh = 0;

	font.loadFromFile("../Fonts/Arial.ttf");
	std::vector<std::string> listString = { "A", "Z", "E", "R", "V" };
	for (int i = 0; i < 5; i++)
	{
		listText[i].setCharacterSize(100);
		listText[i].setFont(font);
		listText[i].setString(listString[i]);
		listText[i].setPosition(100.0f, 1080.f * (0.05f + Heigh));
		listText[i].setFillColor(joueur.getColor());
		Heigh = Heigh + 0.2;
	}
}

sf::Text& inputPlayer(int i)
{
	return listText[i];
}