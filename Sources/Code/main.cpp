#include "../../Sources/Headers/header_library.h"

void initGame(sf::RenderWindow &window)
{
	window.setFramerateLimit(60);
	// Add other stuff here if needed
}

int main()
{
	// Initialisation
	LevelHandler GameLevelHandler;
	MainMenu MainMenuHandler;
	ParticleSystem particleSys;

	int bpm = 120;
	int bps = bpm / 60;

	sf::Clock frameClock;
	// Create and initialize window values
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Hiraishin");
	float deltaTime = 0;
	initGame(window);

	// Début de la boucle de jeu

	while (window.isOpen())
	{
		checkEvents(window, GameLevelHandler);
		// Funcs for running level (not menu)
		if (GameLevelHandler.isLevelRunning() == true)
		{		
			// Wall Spawning timer and logic
			GameLevelHandler.checkPlayerState(window);
			GameLevelHandler.getWallHandler()->CheckClock();
			deltaTime = frameClock.restart().asSeconds();

			// Draw every element, add to this function if you want other visible things
			DrawEverything(window, GameLevelHandler, deltaTime, particleSys);
		}
		else {
			// Main menu funcs
			MainMenuHandler.CheckClock();
			DrawMenu(window, MainMenuHandler, GameLevelHandler.hasPlayerWon());
		}
		// On présente la fenêtre sur l'écran
		window.display();
	}
}
