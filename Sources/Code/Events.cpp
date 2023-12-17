#pragma once
#include "../../Sources/Headers/header_library.h"


void checkEvents(sf::RenderWindow& window, LevelHandler& levelHandler)
{
	// G�rer les �v�n�ments survenus depuis le dernier tour de boucle
	sf::Event event;
	while (window.pollEvent(event))
	{
		// On g�re l'�v�n�ment
		switch (event.type)
		{
		case sf::Event::Closed:
			// L'utilisateur a cliqu� sur la croix => on ferme la fen�tre
			window.close();
			break;

		case sf::Event::KeyPressed:
			if (levelHandler.isLevelRunning() == true) {
				// Key presses relating to the running portion of the game
				levelHandler.getPlayer().PositionPlayer(event);
			}
			else {
				// Key presses relating to the main menu
				if (event.key.code == sf::Keyboard::Enter) {
					// start game
					levelHandler.setLevelRunning();
					// destroy main menu ?
				}
			}
			break;
		default:
			break;
		}
	}
}
