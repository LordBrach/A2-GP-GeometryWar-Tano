#pragma once
#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>
#include <array>
#include <vector>
#include <string>
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

private:
	int _CurrentLevel = 0;
	WallHandler *wallHandlerGeneric;
	PlayState state;

	std::vector<std::string> levelPaths;
};