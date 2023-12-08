#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>
#include <array>
#include <vector>
#include "Wall.h"

class WallHandler
{
public:
	WallHandler(float spawnDelay, std::string levelFilePath);
	~WallHandler();
	// Parse a level.txt folder into _vectorWallPatterns, read the README in the LevelData folder
	void ParseLvlData();
	// print values, for debug
	void PrintWallArray();
	// reset values to prepare for new level
	void Reset(float newDelay, std::string newLevelFilePath);
	void Reset();
	// spawn walls and iterate
	void SpawnWalls();
	// restart WallHandler Clock and checks if the delay is reached
	void CheckClock();
	// Draw walls contained in array
	void DrawWalls(sf::RenderWindow&window, float* deltatime, Player& joueur);
	// Destroy Walls
	void DestroyOOBWalls();
	// return value
	bool getEndCheck();
	// Color
	void SetWallColor(sf::Color);
private:
	// is WallSpawning active ?
	bool isWallSpawning = true;
	// Origin of level data
	std::string _levelFilePath;
	// What series of walls to spawn
	int _currentWall = 0;
	// Leveldata, contains every pattern of walls in arrays of bools, true means a wall is to be spawned
	std::vector<std::array<bool, 5>> _vectorWallPatterns;
	std::vector < std::array<Wall*, 5>> _arrayWalls;
	// Values for time handling
	sf::Clock _clock;
	float _timeElapsed = 0;
	// Delay between wall spawns
	float _spawnDelay;
	// Win check for levelHandler
	bool hasReachedEnd = false;

	// Wall values
	const float _wallSpeed = 500;
	const int _wallSize = 256;
	// Wall color 
	sf::Color _wallColor = sf::Color::Red;

};