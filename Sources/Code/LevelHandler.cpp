#include "../../Sources/Headers/LevelHandler.h"
#include <iostream>



LevelHandler::LevelHandler()
{
	state = PlayState::Title;
	//TODO, if there is time, instead of doing it by hand make it so that
	// you check every files in "Levels" and put them in the vector dynamically
	this->levelPaths.push_back("../LevelData/Debug0.txt");
	this->levelPaths.push_back("../LevelData/Debug1.txt");
	this->levelPaths.push_back("../LevelData/Debug2.txt");
	this->levelPaths.push_back("../LevelData/Debug3.txt");

	//this->levelPaths.push_back("../LevelData/Level2.txt");
	//this->levelPaths.push_back("../LevelData/Level1.txt");
	// Prepare first level
	this->wallHandlerGeneric = new WallHandler(0.5f, this->levelPaths[_CurrentLevel]);
}

LevelHandler::~LevelHandler()
{
	this->levelPaths.clear();
}
bool LevelHandler::CheckIfReachedEnd()
{
	if (this->_CurrentLevel == levelPaths.size() - 1)
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
	this->wallHandlerGeneric->Reset(0.5f, this->levelPaths[_CurrentLevel]);
	this->getPlayer().m_isAlive = true;
	// reset player pos
	this->getPlayer().setPosition(sf::Vector2f(300.0f, 1080.f * 0.45f));

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

void LevelHandler::checkPlayerState(sf::RenderWindow& window)
{
	//std::cout << "Player is: " << this->joueur.m_isAlive << std::endl;
	if (!this->joueur.m_isAlive)
	{
		//std::cout << "IS DEAD";
		LoadLevel(true);
	}
	else if (this->wallHandlerGeneric->getEndCheck()) {
		if (this->CheckIfReachedEnd()) {
			// Delete everything in wallHandler and level handler
			//wallHandlerGeneric->Reset();
			// for now, quits the app
			//window.close();
			// End screen > main menu
			state = LevelHandler::PlayState::Title;
			hasWon = true;
		}
		else {
			changeCurrentColorScheme();
			LoadLevel(false);
		}
	}
	//else if(!_clockStarted)
	//{
	//	_levelEndClock.restart();
	//}
}

void LevelHandler::changeCurrentColorScheme()
{
	currentColor++;
	if (currentColor == colorArray.size() - 1) {
		currentColor = 0;
	}
	_colorScheme = { colorArray[currentColor],  colorArray[currentColor+1]};
	wallHandlerGeneric->SetWallColor(std::get<0>(_colorScheme));
	joueur.changePlayerColor(std::get<1>(_colorScheme));
}

void LevelHandler::setLevelRunning()
{
	_CurrentLevel = 0;
	state = LevelHandler::PlayState::Running;
}

bool LevelHandler::hasPlayerWon()
{
	return hasWon;
}
