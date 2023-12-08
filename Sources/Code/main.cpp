#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <filesystem>
#include <iostream>
#include "../../Sources/Headers/Wall.h"
#include "../../Sources/Headers/Player.h"
#include "../../Sources/Headers/WallHandler.h"
#include "../../Sources/Headers/LevelHandler.h"
#include "../../Sources/Headers/MainMenu.h"
#include "../../Sources/Headers/ParticleSystem.h"


void initGame(sf::RenderWindow &window)
{
	window.setFramerateLimit(60);
	// Add other stuff here if needed
}

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
			if (levelHandler.isLevelRunning() == true) {
				// Key presses relating to the running portion of the game
				levelHandler.getPlayer().PositionPlayer(event);
			}
			else {
				// Key presses relating to the main menu
				if (event.key.code == sf::Keyboard::Enter) {
					// start game
					levelHandler.setLevelRunning();
					// destroy main menu ?
				}
			}
			break;
			// L'utilisateur a cliqué sur la croix => on ferme la fenêtre

		default:
			break;
		}
	}
}

void DrawEverything(sf::RenderWindow& window, LevelHandler &GameLevelHandler, float deltaTime, ParticleSystem &particleSys)
{	//KeytoPress
	InitializeInputText(GameLevelHandler.getPlayer());
	window.clear();
	// Player
	window.draw(GameLevelHandler.getPlayer().getRectangle());
	for (int i = 0; i < 5; i++) { window.draw(inputPlayer(i)); }
	// Walls (also contains their logic, their movement and collisions)
	GameLevelHandler.getWallHandler()->DrawWalls(window, &deltaTime, GameLevelHandler.getPlayer());
	// Particles
	particleSys.update(0.016f, GameLevelHandler.getPlayer());
	particleSys.draw(window);
}

void DrawMenu(sf::RenderWindow &window, MainMenu &MainMenuHandler, bool hasPlayerWon)
{
	window.clear();
	// title drawing
	for (int i = 0; i < MainMenuHandler.GetTitle().size(); i++)
	{
		window.draw(MainMenuHandler.GetTitle()[i]);
	}
	// ui drawing
	window.draw(MainMenuHandler.GetUIText());
	if (hasPlayerWon) {

		window.draw(MainMenuHandler.GetVictoryStar());
	}
}

int main()
{
	
	// Initialisation

	int bpm = 120;
	int bps = bpm / 60;


	//musique fin
	LevelHandler GameLevelHandler;
	MainMenu MainMenuHandler;
	ParticleSystem particleSys;
	// Create and initialize window values
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Hiraishin");
	float deltaTime = 0;
	initGame(window);
	//TEMP, i will init the level here for testing purposes before menu is done
	// Début de la boucle de jeu
	sf::Clock frameClock;

	while (window.isOpen())
	{
		checkEvents(window, GameLevelHandler);
		// Funcs for running level (not menu)
		if (GameLevelHandler.isLevelRunning() == true)
		{		
			// Wall Spawning timer and logic
			GameLevelHandler.checkPlayerState(window);
			GameLevelHandler.getWallHandler()->CheckClock();
			deltaTime = frameClock.restart().asSeconds();
			// Draw every element, add to this function if you want other visible things
			DrawEverything(window, GameLevelHandler, deltaTime, particleSys);
		}
		else {
			// Main menu funcs
			MainMenuHandler.CheckClock();
			DrawMenu(window, MainMenuHandler, GameLevelHandler.hasPlayerWon());
		}
		// On présente la fenêtre sur l'écran
		window.display();
	}
}
