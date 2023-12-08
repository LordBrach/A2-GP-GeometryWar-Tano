#pragma once
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include<iostream>
#include<tuple>
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/ConvexShape.hpp"
#include "SFML/System/Clock.hpp"
class MainMenu
{
public:
	MainMenu();
	~MainMenu();
	void CheckClock();
	// TITLE FUNCTIONS
	std::vector<sf::ConvexShape> GetTitle();
	void AddToVector(sf::ConvexShape);
	void CreateLetter(char which);
	// UI FUNCTIONS
	sf::Text GetUIText();
	void BlinkUI();
	// EXTRA
	void CreateStar();
	sf::ConvexShape GetVictoryStar();
private:
	// TITLE VALUES
	float size = 1.0f;
	int increment = 60;
	int currentPos;
	std::tuple<int, int> StartPos;
	std::vector<sf::ConvexShape> TitleVector;
	// UI
	sf::Font uiFont;
	sf::Text uiText;
	// EXTRA
	sf::ConvexShape victoryStar;
	// CLOCK
	sf::Clock _MenuClock;
	float _timeElapsed = 0;
	float _uiFlashDelay;
};