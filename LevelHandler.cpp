#include "LevelHandler.h"
#include <iostream>


LevelHandler::LevelHandler()
{
	this->state = PlayState::Running;
	//TODO, if there is time, instead of doing it by hand make it so that
	// you check every files in "Levels" and put them in the vector dynamically

	this->levelPaths.push_back("../LevelData/Level2.txt");
	this->levelPaths.push_back("../LevelData/Level1.txt");
	// Prepare first level
	this->wallHandlerGeneric = new WallHandler(0.5f, this->levelPaths[_CurrentLevel]);
}

LevelHandler::~LevelHandler()
{
	this->levelPaths.clear();
}
bool LevelHandler::CheckIfReachedEnd()
{
	if (this->_CurrentLevel = levelPaths.size() - 1)
	{
		return true;
	}
	return false;
}
void LevelHandler::LoadLevel(bool isGameOver)
{
	if (!isGameOver) {
		_CurrentLevel += 1;
	}
	this->wallHandlerGeneric->Reset(3.0f, this->levelPaths[_CurrentLevel]);

	// TODO
}
void LevelHandler::LoadMenu() {}// TODO, secondary
void LevelHandler::UnloadLevel()
{
	// TODO	
	// Empty WallHandler
	//delete(this->wallHandlerGeneric.)
}

WallHandler *LevelHandler::getWallHandler()
{
	return this->wallHandlerGeneric;
}


Player &LevelHandler::getPlayer()
{
	return this->joueur;
}

LevelHandler::PlayState LevelHandler::getGameState()
{
	return this->state;
}

bool LevelHandler::isLevelRunning()
{
	if (getGameState() == LevelHandler::PlayState::Running) {
		return true;
	}
	else {
		return false;
	}
}

void LevelHandler::checkPlayerState()
{
	if (!this->joueur.m_isAlive)
	{
		std::cout << "IS DEAD";
		LoadLevel(true);
		this->joueur.m_isAlive = true;
	}
}