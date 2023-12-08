#ifndef LIBRARY_H
	#define LIBRARY_H
		#include <SFML/Graphics.hpp>
		#include <SFML/Audio.hpp>
		#include <SFML/Window.hpp>
		#include <filesystem>
		#include <iostream>

		#include "../../Sources/Headers/Player.h"
		#include "../../Sources/Headers/WallHandler.h"
		#include "../../Sources/Headers/LevelHandler.h"
		#include "../../Sources/Headers/MainMenu.h"
		#include "../../Sources/Headers/ParticleSystem.h"

//	UI
		sf::Text& inputPlayer(int i);
		void InitializeInputText(Player& joueur);
//	Draw
		void DrawEverything(sf::RenderWindow& window, LevelHandler& GameLevelHandler, float deltaTime, ParticleSystem& particleSys);
		void DrawMenu(sf::RenderWindow& window, MainMenu& MainMenuHandler, bool hasPlayerWon);
// Events
		void checkEvents(sf::RenderWindow& window, LevelHandler& levelHandler);

#endif