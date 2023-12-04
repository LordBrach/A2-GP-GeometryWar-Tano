#pragma once
#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>
#include <array>
#include <vector>
#include <string>
#include "Player.h"
#include "WallHandler.h"


class LevelHandler
{
public:
	LevelHandler();
	~LevelHandler();

	enum class PlayState {
		Running,
		Title,
		Paused,
		Restart
	};
	void LoadMenu();
	// Load/Restarts level depending of if the player died
	void LoadLevel(bool isGameOver);
	void UnloadLevel();
	// Check if we have reached the end of the levels list
	bool CheckIfReachedEnd();

	PlayState getGameState();
	bool isLevelRunning();

	WallHandler *getWallHandler();
	Player &getPlayer();
	// check if player is alive or if he has reached the end of the level
	void checkPlayerState(sf::RenderWindow& window);

	void changeCurrentColorScheme();

private:
	int _CurrentLevel = 0;
	WallHandler *wallHandlerGeneric;
	Player joueur;
	PlayState state;

	sf::Clock _levelEndClock;
	float _elapsedTime;
	float _endDelay = 4.0f;
	bool _clockStarted = false;
	// Colors
	int currentColor = 0;
	std::tuple<sf::Color, sf::Color> _colorScheme;
	std::array<sf::Color, 4> colorArray = { sf::Color::Red, sf::Color::Blue, sf::Color::Cyan, sf::Color::Magenta };


	std::vector<std::string> levelPaths;
};