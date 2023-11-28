#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Player.h"

constexpr float cubeSpeed = 500.f;

int main()
{
	// Initialisation

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Hiraishi");
	window.setVerticalSyncEnabled(true);
	Player joueur;
	sf::RectangleShape Player;
	Player = joueur.CreatePlayer(Player);
	int index = 2;
	// Début de la boucle de jeu
	sf::RectangleShape rectangle;
	rectangle.setFillColor(sf::Color::Red);
	rectangle.setPosition(640, 360);
	rectangle.setSize(sf::Vector2f(128, 128));

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
						Player = joueur.PositionPlayer(Player,0);
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

		float deltaTime = frameClock.restart().asSeconds();
		std::cout << 1.f / deltaTime << " FPS" << std::endl;

		// Logique
		sf::Vector2f pos = rectangle.getPosition();
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
			pos.x = pos.x - deltaTime * cubeSpeed;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			pos.x = pos.x + deltaTime * cubeSpeed;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
			pos.y = pos.y - deltaTime * cubeSpeed;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			pos.y = pos.y + deltaTime * cubeSpeed;

		rectangle.setPosition(pos);
		// Affichage
		
		// Remise au noir de toute la fenêtre
		window.clear();
		
		// Tout le rendu va se dérouler ici
		window.draw(rectangle);
		window.draw(Player);

		// On présente la fenêtre sur l'écran
		window.display();
	}
}
