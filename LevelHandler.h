#pragma once
#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>
#include <array>
#include <vector>
#include <string>


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
	bool CheckIfReachedEnd();
	void LoadLevel();
	void LoadMenu();
	void UnloadLevel();

private:
	int _CurrentLevel = 0;
	PlayState state;

	std::vector<std::string> levelNames;
};