#include "LevelHandler.h"
#include <iostream>


LevelHandler::LevelHandler()
{
	this->state = PlayState::Title;
	//TODO, if there is time, instead of doing it by hand make it so that
	// you check every files in "Levels" and put them in the vector dynamically

	this->levelNames.push_back("Level0");
	this->levelNames.push_back("Level1");
}

LevelHandler::~LevelHandler()
{
	this->levelNames.clear();
}
bool LevelHandler::CheckIfReachedEnd()
{
	if (this->_CurrentLevel = levelNames.size() - 1)
	{
		return true;
	}
	return false;
}
void LevelHandler::LoadLevel()
{
	// TODO
}
void LevelHandler::LoadMenu()
{
	// TODO
}
void LevelHandler::UnloadLevel()
{
	// TODO	
}