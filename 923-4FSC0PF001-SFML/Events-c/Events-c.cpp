// SAE921-GPR4100-SFML-03c-Events.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>

#include "SFML/Main.hpp"
#include "SFML/Graphics.hpp"


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML First Window");

	// Basic Setup of the window
	// Vertical sync, framerate
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(30);

	// Setting up thh events
	window.setKeyRepeatEnabled(true);

	// Loading a file as texture
	sf::Texture up;
	sf::Texture down;
	sf::Texture left;
	sf::Texture right;
	up.loadFromFile("data/sprites/ZeldaUp.png");
	down.loadFromFile("data/sprites/ZeldaDown.png");
	left.loadFromFile("data/sprites/ZeldaLeft.png");
	right.loadFromFile("data/sprites/ZeldaRight.png");

	// Using a sprite
	// https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Sprite.php
	sf::Sprite sprite;
	sprite.setTexture(up);
	sprite.setOrigin(up.getSize().x / 2.0f, up.getSize().y / 2.0f);
	const auto center = window.getSize();
	sprite.setPosition(center.x / 2.0f, center.y / 2.0f);
	//sprite.setScale(0.33f, 0.33f);

	sf::Color background_color(sf::Color::Black);

	const float speed = 8.0f;

	while (window.isOpen())
	{
		// on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
		sf::Event event;
		sf::Keyboard keyboard;
		sf::Vector2f position;

		auto key_code = sf::Keyboard::Up;

		if (sf::Keyboard::isKeyPressed(key_code))
		{
			// Change texture
			sprite.setTexture(up);
			// Move the sprite
			position = sprite.getPosition();
			position.y -= speed;
			sprite.setPosition(position);
		}

		std::cout << "Before while" << std::endl;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			// évènement "fermeture demandée" : on ferme la fenêtre
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::KeyPressed:
				// Test de la valeur de la touche
				std::cout << "Key pressed : " << event.key.code << std::endl;
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
				case sf::Keyboard::Z:
					std::cout << "UP ^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << std::endl;
					break;

				case sf::Keyboard::Down:
				case sf::Keyboard::S:
					std::cout << "DOWN vvvvvvvvvvvvvvvvvvvvvvvvvvv" << std::endl;

				//// Change texture
				//sprite.setTexture(down);
				//// Move the sprite
				//position = sprite.getPosition();
				//position.y += speed;
				//sprite.setPosition(position);
					break;

				case sf::Keyboard::Left:
				case sf::Keyboard::Q:
					std::cout << "LEFT <<<<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;

				// Change texture
				//sprite.setTexture(left);
				//// Move the sprite
				//position = sprite.getPosition();
				//position.x -= speed;
				//sprite.setPosition(position);
					break;

				case sf::Keyboard::Right:
				case sf::Keyboard::D:
					std::cout << "RIGHT >>>>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;

				//// Change texture
				//sprite.setTexture(right);
				//// Move the sprite
				//position = sprite.getPosition();
				//position.x += speed;
				//sprite.setPosition(position);
					break;

				default:
					break;
				}
				break;

			default:
				break;
			}
		}
		std::cout << "After while" << std::endl;

		window.clear(background_color);

		window.draw(sprite);

		// Window Display

		window.display();
	}
}
