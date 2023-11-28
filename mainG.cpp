#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Wall.h"
#include <iostream>
#include "Player.h"



int main()
{
	// Initialisation
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Hiraishin");
	window.setVerticalSyncEnabled(true);
	Base base;
	Player joueur;
	Position position;
	sf::RectangleShape Player;
	Player = joueur.CreatePlayer(Player);
	int index = 2;
	// Début de la boucle de jeu
	sf::RectangleShape rectangle;
	Wall mur(300.f);
	const float cubeSpeed = mur.GetSpeed();
	sf::Clock frameClock;
	sf::Vector2f pos = rectangle.getPosition();
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
				if (event.key.code == sf::Keyboard::Z)
				{
					Player = joueur.PositionPlayer(Player, "Top", index);
				}
				else if (event.key.code == sf::Keyboard::S)
				{
					Player = joueur.PositionPlayer(Player, "Down", index);
				}

				break;
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


		//pos.x = pos.x - deltaTime * cubeSpeed;


		//rectangle.setPosition(pos);


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
			pos.y = pos.y - deltaTime * cubeSpeed;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			pos.y = pos.y + deltaTime * cubeSpeed;

		rectangle.setPosition(pos);
		// Affichage

		// Remise au noir de toute la fenêtre
		window.clear();

		// Tout le rendu va se dérouler ici

		mur.draw(window,Position::position1);
		mur.draw(window,Position::position2);
		mur.draw(window,Position::position3);
		mur.draw(window,Position::position4);
		mur.draw(window,Position::position5);

		//window.draw(rectangle);
		window.draw(Player);

		// On présente la fenêtre sur l'écran
		window.display();
	}
}
