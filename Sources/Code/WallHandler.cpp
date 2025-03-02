#include "../../Sources/Headers/WallHandler.h"
#include <iostream>
#include <fstream>
#include<windows.h>

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
		MyFile.close();
	}
	else {
		std::cout << "Couldnt open level file" << std::endl;
	}
	PrintWallArray();
}	

void emptyWallsArray(std::vector < std::array<Wall*, 5>> &_arrayWalls)
{	
	_arrayWalls.clear();
}

void WallHandler::Reset(float newDelay, std::string newLevelFilePath)
{
	this->_spawnDelay = newDelay;
	this->_currentWall = 0;
	this->_vectorWallPatterns.clear();
	// TODO DELETE WALLS
	_arrayWalls.clear();
	//emptyWallsArray(_arrayWalls);
	_levelFilePath = newLevelFilePath;
	isWallSpawning = true;
	_clock.restart();
	_timeElapsed = 0;
	hasReachedEnd = false;

	ParseLvlData();
}

void WallHandler::SpawnWalls()
{
	std::cout << "SPAWNING WALLS:" << _currentWall << std::endl;
	Position positions;
	if (_currentWall < _vectorWallPatterns.size() - 1) {
		// here do the spawning
		std::cout << _currentWall << std::endl;
		// want to access first element in _vectorWallPatterns
		// want to create 5 walls based on the bools in there
		for (int i = 0; i < _vectorWallPatterns.begin()[0].size(); i++)
		{
			_arrayWalls.emplace_back();
			if (_vectorWallPatterns[_currentWall][i] == true) {
				// Set position to according value
				positions = static_cast<Position>(i);
				//std::cout << "instanciating a wall in position: " << positions->x << std::endl;

				// store new wall in _arrayWalls
				_arrayWalls[_currentWall][i] = new Wall(positions, _wallSpeed, _wallSize, _wallColor);
				_arrayWalls[_currentWall][i]->setPosition(positions);

				std::cout << "added wall to array" << std::endl;
			}
			else {
				_arrayWalls[_currentWall][i] = nullptr;

			}
		}
		_currentWall += 1;
	} else {
		std::cout << "REACHED END" << std::endl;
		hasReachedEnd = true;
	}
}

void WallHandler::CheckClock()
{
	float deltaTime = this->_clock.getElapsedTime().asSeconds();

	_clock.restart();
	if (isWallSpawning) {
		_timeElapsed += deltaTime;
	}
	//std::cout << _timeElapsed << std::endl;
	if (_timeElapsed > this->_spawnDelay) {
		this->SpawnWalls();
		_timeElapsed = 0;
	}
}


void WallHandler::DestroyOOBWalls()
{
	//If OOB, Destroy a line of walls
	for (int i = 0; i < _arrayWalls.size(); i++)
	{
		for (int j = 0; j < _arrayWalls[i].size(); j++)
		{
			if (_arrayWalls[i][j] != nullptr)
			{
				if (_arrayWalls[i][j]->getPosition().x <= -300)
				{
					for (int k = 0; k < _arrayWalls[i].size(); k++)
					{
						std::cout << "Destroying walls" << std::endl;
						delete(_arrayWalls[i][k]);
					}
					_arrayWalls.erase(_arrayWalls.begin() + i);
					return;
					}
			}
		}
	}
}

void WallHandler::DrawWalls(sf::RenderWindow& window, float* deltatime, Player& joueur)
{
	for (int i = 0; i < _arrayWalls.size(); i++)
	{
		for (int j = 0; j < _arrayWalls[i].size(); j++)
		{
			if (_arrayWalls[i][j] != nullptr)
			{
				_arrayWalls[i][j]->draw(window);
				_arrayWalls[i][j]->slide(deltatime);
				_arrayWalls[i][j]->checkCollision(joueur);
			}
		}
	}
	DestroyOOBWalls();
}

bool WallHandler::getEndCheck()
{
	return hasReachedEnd;
}

void WallHandler::SetWallColor(sf::Color color)
{
	_wallColor = color;
}