#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Audio.hpp>
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
	// Load/Restarts level depending of if the player died
	void LoadLevel(bool isGameOver);
	// Check if we have reached the end of the levels list
	bool CheckIfReachedEnd();

	PlayState getGameState();
	bool isLevelRunning();
	void setLevelRunning();
	WallHandler *getWallHandler();
	Player &getPlayer();
	// check if player is alive or if he has reached the end of the level
	void checkPlayerState(sf::RenderWindow& window);

	void changeCurrentColorScheme();
	void changeCurrentMusicTheme();
	void initMusic() {
		for (size_t i = 0; i < musicArray.size(); ++i) {
			sf::Music& music = musicArray[i];
			music.openFromFile("../LevelData/music" + std::to_string(i + 1) + ".mp3");
		}
	}
	bool hasPlayerWon();
private:
	int _CurrentLevel = 0;
	WallHandler *wallHandlerGeneric;
	Player joueur;
	PlayState state;
	bool hasWon = false;
	// Colors
	int currentColor = 0;
	int currentMusic = 0;
	std::tuple<sf::Color, sf::Color> _colorScheme;
	std::array<sf::Color, 4> colorArray = { sf::Color::Red, sf::Color::Blue, sf::Color::Cyan, sf::Color::Magenta };
	std::array<sf::Music, 6> musicArray;
	
	std::vector<std::string> levelPaths;
};