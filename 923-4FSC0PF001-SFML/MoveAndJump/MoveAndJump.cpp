

#include <iostream>

#include "SFML/Main.hpp"
#include "SFML/Graphics.hpp"

constexpr float gravityForce = 1.0f;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "The Game");

	// Basic Setup of the window
	// Vertical sync, framerate
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(30);

	// Define a Shape
	// https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Shape.php
	sf::RectangleShape shape(sf::Vector2f(50, 50));
	// set the shape color to green
	shape.setFillColor(sf::Color(150, 0, 0));

	// define a position
	shape.setOrigin(shape.getSize().x / 2, shape.getSize().y / 2);
	shape.setPosition(window.getSize().x / 2.0f, window.getSize().y / 2.0f);

	sf::Vector2f vitesse = sf::Vector2f(0, 0);


	std::vector<int> a = { 6,1 };


	while (window.isOpen())
	{

		// on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
		sf::Event event;

		bool isGrounded = shape.getPosition().y >= (window.getSize().y - shape.getSize().y / 2);

		while (window.pollEvent(event))
		{
			sf::Vector2i newPos;
			switch (event.type)
			{


			case sf::Event::MouseButtonPressed:
				newPos = sf::Mouse::getPosition(window);
				vitesse = sf::Vector2f(0, 0);
				shape.setPosition(newPos.x, newPos.y);
				break;

			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Space && isGrounded)
				{
					vitesse.y = -30.0f;
				}
				break;

				// évènement "fermeture demandée" : on ferme la fenêtre
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::Resized:
				window.close();
				break;

			default:
				break;
			}

		}



		// Graphical Region
		window.clear(sf::Color::Black);

		if(!isGrounded)
		{
			vitesse.y += gravityForce;
		}else
		{
			vitesse.y = 0;
		}
		shape.setPosition(shape.getPosition() + vitesse);
		window.draw(shape);

		// Window Display
		window.display();

	}



}
