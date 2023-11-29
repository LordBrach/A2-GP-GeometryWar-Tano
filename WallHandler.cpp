#include "WallHandler.h"
#include <iostream>
#include <fstream>

WallHandler::WallHandler(float spawnDelay, std::string levelFilePath)
{
	this->_spawnDelay = spawnDelay;
	this->_levelFilePath = levelFilePath;
	this->isWallSpawning = true;
	ParseLvlData();
}

WallHandler::~WallHandler(){}

void WallHandler::PrintWallArray()
{
	for (int i = 0; i < _vectorWallPatterns.size(); i++)
	{
		for(int j = 0; j < 5; j++)
		{
			std::cout << _vectorWallPatterns[i][j];
		}
		std::cout << std::endl;
	}
}
std::array<bool, 5> convertLine(std::string &line)
{
	std::array <bool, 5> TempArray;
	TempArray.fill(false);
	for (int i = 0; i < line.length(); i++)
	{
		if (line[i] == 'x') {
			TempArray[i] = true;
		}
	}
	return TempArray;
}

void WallHandler::ParseLvlData()
{
	std::ifstream MyFile(_levelFilePath);
	std::string levelLine;
	int i = 0;
	if (MyFile.is_open()) {
		while (MyFile) {
			if (MyFile.eof()) break;
			std::getline(MyFile, levelLine);
			//_vectorWallPatterns[i] = new array<bool, 5>;
				i++;
			_vectorWallPatterns.push_back(convertLine(levelLine));
			//std::cout << levelLine << std::endl;
		}
	}
	else {
		std::cout << "Couldnt open level file" << std::endl;
	}
	PrintWallArray();
}	

void WallHandler::Reset(float newDelay, std::string newLevelFilePath)
{
	this->_spawnDelay = newDelay;
	this->_currentWall = 0;
	this->_vectorWallPatterns.clear();
	this->_levelFilePath = newLevelFilePath;
	this->isWallSpawning = true;
	ParseLvlData();
}

void WallHandler::SpawnWalls()
{
	std::cout << "SPAWNING WALLS:" << _currentWall << std::endl;
	if (_currentWall < _vectorWallPatterns.size() - 1) {
		_currentWall += 1;
		// here do the spawning

		// want to access first element in _vectorWallPatterns
		// want to create 5 walls based on the bools in there
		// these walls are stored in _arrayWalls
		for (int i = 0; i < _vectorWallPatterns.begin()[0].size(); i++)
		{
			if (_vectorWallPatterns.begin()[0][i] == true) {
				_arrayWalls[_currentWall][i] = new Wall(_wallSpeed);
			}
		}
		// pop first element in _vectorWallPatterns
		_vectorWallPatterns.erase(_vectorWallPatterns.begin());
		// TODO make it so that the new walls stored in _arrayWalls disappear after 5 seconds


		// you need to handle the drawing of walls, they move by themselves though




	}
	else {
		std::cout << "REACHED END" << std::endl;
		this->isWallSpawning = false;
	}
}

void WallHandler::CheckClock()
{
	float deltaTime = this->_clock.getElapsedTime().asSeconds();

	_clock.restart();
	if (isWallSpawning) {
		_timeElapsed += deltaTime;
	}
	if (_timeElapsed > this->_spawnDelay) {
		this->SpawnWalls();
		_timeElapsed = 0;
	}
}

void WallHandler::DrawWalls(sf::RenderWindow &window)
{
	for (int i = 0; i < _arrayWalls.size(); i++)
	{
		for (int j = 0; i < _arrayWalls[i].size(); j++)
		{
			//_arrayWalls[i][j]->draw(window, _arrayWalls[i][j]);
		}
	}
}