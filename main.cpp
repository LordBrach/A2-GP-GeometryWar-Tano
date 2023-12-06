#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include "Wall.h"
#include <iostream>
#include "Player.h"
#include "WallHandler.h"
#include <filesystem>
#include "LevelHandler.h"


void initGame(sf::RenderWindow &window)
{
	window.setVerticalSyncEnabled(true);
	
	// Add other stuff here if needed
}



sf::Text A, Z, E, R, V;
sf::Font font;
std::vector<sf::Text> listText = { A, Z, E, R, V };
void InitializeInputText()
{
	sf::Text Letter;
	float Heigh = 0;

	font.loadFromFile("../Font/Arial.ttf");
	std::vector<std::string> listString = { "A", "Z", "E", "R", "V" };
	for (int i = 0;i < 5;i++)
	{
		listText[i].setCharacterSize(100);
		listText[i].setFont(font);
		listText[i].setString(listString[i]);
		listText[i].setPosition(100.0f, 1080.f * (0.05f + Heigh));
		Heigh = Heigh + 0.2;
	}
}

sf::Text& inputPlayer(int i) 
{
	return listText[i];
}


void checkEvents(sf::RenderWindow &window, LevelHandler &levelHandler)
{
	// Gérer les événéments survenus depuis le dernier tour de boucle
	sf::Event event;
	while (window.pollEvent(event))
	{
		// On gère l'événément
		switch (event.type)
		{
		case sf::Event::Closed:
			// L'utilisateur a cliqué sur la croix => on ferme la fenêtre
			window.close();
			break;

		case sf::Event::KeyPressed:
			levelHandler.getPlayer().PositionPlayer(event);
			break;
			// L'utilisateur a cliqué sur la croix => on ferme la fenêtre

		default:
			break;
		}
	}
}

void DrawEverything(sf::RenderWindow& window, LevelHandler &GameLevelHandler, float deltaTime)
{
	window.clear();
	// Player
	for (int i = 0; i < 5; i++) { window.draw(inputPlayer(i)); }
	window.draw(GameLevelHandler.getPlayer().getRectangle());
	// Walls (also contains their logic, their movement and collisions)
	GameLevelHandler.getWallHandler()->DrawWalls(window, &deltaTime, GameLevelHandler.getPlayer());
}

int main()
{
	InitializeInputText();
	// Initialisation
	LevelHandler GameLevelHandler;
	// Create and initialize window values
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Hiraishin");
	float deltaTime = 0;
	initGame(window);
	//TEMP, i will init the level here for testing purposes before menu is done
	// Début de la boucle de jeu
	sf::Clock frameClock;

	while (window.isOpen())
	{
		// Funcs for running level (not menu)
		if (GameLevelHandler.isLevelRunning() == true)
		{		
			checkEvents(window, GameLevelHandler);
			// Wall Spawning timer and logic
			GameLevelHandler.checkPlayerState(window);
			GameLevelHandler.getWallHandler()->CheckClock();
			deltaTime = frameClock.restart().asSeconds();
			// Draw every element, add to this function if you want other visible things
			DrawEverything(window, GameLevelHandler, deltaTime);
		}
		else {
			// Main menu funcs
		}
		// On présente la fenêtre sur l'écran
		window.display();
	}
}
