#pragma once
#include "../../Sources/Headers/header_library.h"


void checkEvents(sf::RenderWindow& window, LevelHandler& levelHandler)
{
	// Gérer les événéments survenus depuis le dernier tour de boucle
	sf::Event event;
	while (window.pollEvent(event))
	{
		// On gère l'événément
		switch (event.type)
		{
		case sf::Event::Closed:
			// L'utilisateur a cliqué sur la croix => on ferme la fenêtre
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
