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
		sf::RectangleShape Player;
	Player = joueur.CreatePlayer(Player);
	int index = 2;
	// Début de la boucle de jeu
	//sf::RectangleShape rectangle;
	Wall mur(500.f, Position::position1);
	Wall mur1(500.f, Position::position2);
	Wall mur2(500.f, Position::position3);
	Wall mur3(Position::position4, 500.0f, 256);
	const float cubeSpeed = mur.getSpeed();
		sf::RectangleShape player;
	Position pos;
	player = joueur.CreatePlayer(player);
	// Début de la boucle de jeu
	//sf::RectangleShape rectangle;
	//const float cubeSpeed = mur.GetSpeed();
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
				/*case sf::Event::KeyPressed:
					if (event.key.code == sf::Keyboard::Z)
					{
						Player = joueur.PositionPlayer(Player,"Top",index);
					}
					else if (event.key.code == sf::Keyboard::S)
					{
						Player = joueur.PositionPlayer(Player,"Down",index);
					}
					break;
				*/
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::A)
				{
					Player = joueur.PositionPlayer(Player, 0);
				}
				else if (event.key.code == sf::Keyboard::Z)
				{
					Player = joueur.PositionPlayer(Player, 1);
				}
				else if (event.key.code == sf::Keyboard::E)
				{
					Player = joueur.PositionPlayer(Player, 2);
				}
				else if (event.key.code == sf::Keyboard::R)
				{
					Player = joueur.PositionPlayer(Player, 3);
				}
				else if (event.key.code == sf::Keyboard::Space)
				{
					Player = joueur.PositionPlayer(Player, 4);
				}
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

		//sf::Vector2f pos = mur.getPosition();
		//pos.x = pos.x - deltaTime * cubeSpeed;


		//rectangle.setPosition(pos);


		/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
			pos.y = pos.y - deltaTime * cubeSpeed;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			pos.y = pos.y + deltaTime * cubeSpeed;

		rectangle.setPosition(pos); */
		// Affichage

		// Remise au noir de toute la fenêtre
		window.clear();

		// Tout le rendu va se dérouler ici

		mur.draw(window);
		mur1.draw(window);
		mur2.draw(window);
		mur3.draw(window);
		mur.slide(&deltaTime);
		mur1.slide(&deltaTime);
		mur2.slide(&deltaTime);
		mur3.slide(&deltaTime);

		//window.draw(rectangle);
		window.draw(Player);
		// On présente la fenêtre sur l'écran
		window.display();
	}
}
