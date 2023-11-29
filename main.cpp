#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Wall.h"
#include <iostream>
#include "Player.h"
#include "WallHandler.h"
#include <filesystem>


int main()
{
	// Initialisation
	//testing wall handler
	WallHandler* wallHandlingLevel0 = new WallHandler(3.0f, ("../LevelData/Level1.txt"));
	std::cout << "RESET" << std::endl;
	wallHandlingLevel0->Reset(0.5f, ("../LevelData/Level0.txt"));

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Hiraishin");
	window.setVerticalSyncEnabled(true);
	Base base;
	Player joueur;
	sf::RectangleShape player;
	player = joueur.CreatePlayer(player);
	// Début de la boucle de jeu
	//sf::RectangleShape rectangle;
	Wall mur(500.f);
	const float cubeSpeed = mur.GetSpeed();
	sf::Clock frameClock;

	while (window.isOpen())
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
				player = joueur.PositionPlayer(player, event);
				break;
				// L'utilisateur a cliqué sur la croix => on ferme la fenêtre
				window.close();
				break;
			default:
				break;
			}
		}
		wallHandlingLevel0->CheckClock();
		float deltaTime = frameClock.restart().asSeconds();
		//std::cout << 1.f / deltaTime << " FPS" << std::endl;

		// Logique
<<<<<<< Updated upstream
		Position pos{};
=======



>>>>>>> Stashed changes
		// Affichage

		// Remise au noir de toute la fenêtre
		window.clear();

		// Tout le rendu va se dérouler ici

		mur.draw(window, pos);

		//window.draw(rectangle);
		window.draw(player);

		// On présente la fenêtre sur l'écran
		window.display();
	}
}
