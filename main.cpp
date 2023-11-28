#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Wall.h"
#include <iostream>



int main()
{
	// Initialisation

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Hiraishin");
	window.setVerticalSyncEnabled(true);
	Base base;
	// Début de la boucle de jeu
	sf::RectangleShape rectangle;
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

			default:
				break;
			}
		}

		float deltaTime = frameClock.restart().asSeconds();
		std::cout << 1.f / deltaTime << " FPS" << std::endl;

		// Logique
		sf::Vector2f pos = rectangle.getPosition();

		//pos.x = pos.x - deltaTime * cubeSpeed;

		//rectangle.setPosition(pos);

		// Affichage

		// Remise au noir de toute la fenêtre
		window.clear();

		// Tout le rendu va se dérouler ici
		mur.draw(window);

		// On présente la fenêtre sur l'écran
		window.display();
	}
}
