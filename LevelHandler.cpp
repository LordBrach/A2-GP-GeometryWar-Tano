#include "LevelHandler.h"
#include <iostream>


LevelHandler::LevelHandler()
{
	this->state = PlayState::Title;
	//TODO, if there is time, instead of doing it by hand make it so that
	// you check every files in "Levels" and put them in the vector dynamically

	this->levelPaths.push_back("../LevelData/Level0.txt");
	this->levelPaths.push_back("../LevelData/Level1.txt");
	// Prepare first level
	this->wallHandlerGeneric = new WallHandler(3.0f, this->levelPaths[_CurrentLevel]);
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