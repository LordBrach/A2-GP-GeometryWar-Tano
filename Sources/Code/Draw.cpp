#pragma once
#include "../../Sources/Headers/header_library.h"

void DrawEverything(sf::RenderWindow& window, LevelHandler& GameLevelHandler, float deltaTime, ParticleSystem& particleSys)
{	
	//KeytoPress
	InitializeInputText(GameLevelHandler.getPlayer());
	window.clear();
	// Player
	window.draw(GameLevelHandler.getPlayer().getRectangle());
	// Walls (also contains their logic, their movement and collisions)
	GameLevelHandler.getWallHandler()->DrawWalls(window, &deltaTime, GameLevelHandler.getPlayer());
	// Particles
	for (int i = 0; i < 5; i++) { window.draw(inputPlayer(i)); }
	particleSys.update(0.016f, GameLevelHandler.getPlayer());
	particleSys.draw(window);
}

void DrawMenu(sf::RenderWindow& window, MainMenu& MainMenuHandler, bool hasPlayerWon)
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