// SAE-01.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>

#include "SFML/OpenGL.hpp"
#include "SFML/Graphics.hpp"
int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML First Window");
	sf::Texture wall;

	// Basic Setup of the window
	// Vertical sync, framerate
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(30);

	// Define a Shape
	// https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Shape.php
	sf::RectangleShape shape(sf::Vector2f(50, 50));
	// set the shape color to green
	shape.setFillColor(sf::Color(150, 0, 0));
	// set a 10-pixel wide orange outline
	shape.setOutlineThickness(3.f);
	shape.setOutlineColor(sf::Color(250, 150, 100));
	// define a position
	shape.setOrigin(shape.getSize().x / 2, shape.getSize().y / 2);
	shape.setPosition(0, 0);

	// Redefine Size
	sf::Mouse mouse;

	while (window.isOpen())
	{

		//window.clear(sf::Color::Blue);

		sf::Vector2i vec;

		sf::Vector2i pos = sf::Mouse::getPosition(window);
		shape.setPosition(pos.x, pos.y);

		// on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
		sf::Event event;
		while (window.pollEvent(event))
		{

			// évènement "fermeture demandée" : on ferme la fenêtre
			if (event.type == sf::Event::Closed)
				window.close();

		}

		// Draw the shape
		window.draw(shape);

		// Here we draw
		// Draw the sprite
		//window.draw(sprite);


		// effacement les tampons de couleur/profondeur
		window.display();

	}

	return EXIT_SUCCESS;
}
