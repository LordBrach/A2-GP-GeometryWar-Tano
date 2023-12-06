#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include "ParticleSystem.h"
#include "Wall.h"
#include <iostream>
#include "Player.h"
#include "WallHandler.h"
#include <filesystem>


int main()
{
	// Initialisation
	ParticleSystem particlesystem;
	
	sf::CircleShape circlePart;

	//testing wall handler
	WallHandler* wallHandlingLevel0 = new WallHandler(3.0f, ("../LevelData/Level1.txt"));
	//std::cout << "RESET" << std::endl;
	wallHandlingLevel0->Reset(0.5f, ("../LevelData/Level2.txt"));

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Hiraishin");
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);
	ParticleSystem particleSystem;
	Base base;
	Player joueur;
	sf::Music music;
	if (!music.openFromFile("../LevelData/musicLVL1.mp3"))
		std::cout << "music failed" << std::endl;

	music.play();
	int index = 2;

	// Début de la boucle de jeu
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
				joueur.PositionPlayer(joueur, event);
				break;
				// L'utilisateur a cliqué sur la croix => on ferme la fenêtre
			
			default:
				break;
			}
		}
		wallHandlingLevel0->CheckClock();
		float dt = 0.016f;
		particleSystem.update(dt, joueur);


		float deltaTime = frameClock.restart().asSeconds();

		window.clear();
		wallHandlingLevel0->DrawWalls(window, &deltaTime, joueur);
		//std::cout << 1.f / deltaTime << " FPS" << std::endl;
		particleSystem.draw(window);

		// Logique
		window.draw(joueur.getRectangle());
		if (joueur.m_isAlive == false)
		{
			wallHandlingLevel0->DrawWalls(window, &deltaTime, joueur);
			//joueur.m_isAlive = true;
		}
		// On présente la fenêtre sur l'écran
		window.display();
	}
}
