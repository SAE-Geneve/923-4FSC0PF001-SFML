// SAE921-GPR4100-SFML-03c-Events.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>

#include "SFML/Main.hpp"
#include "SFML/Graphics.hpp"

#include "player.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML First Window");

	// Basic Setup of the window
	// Vertical sync, framerate
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(30);

	// Setting up thh events
	window.setKeyRepeatEnabled(true);

	Player link;
	link.Load();


	sf::Color background_color(sf::Color::Black);

	while (window.isOpen())
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
		{
			link.Sprint();
		}


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			link.Move(sf::Vector2f(0, -1));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			link.Move(sf::Vector2f(0, 1));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			link.Move(sf::Vector2f(-1, 0));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			link.Move(sf::Vector2f(1, 0));
		}

		// on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				// évènement "fermeture demandée" : on ferme la fenêtre
			case sf::Event::Closed:
				window.close();
				break;

			default:
				break;
			}
		}

		window.clear(background_color);

		window.draw(link);

		// Window Display

		window.display();
	}
}
