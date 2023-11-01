

#include <iostream>

#include "SFML/Main.hpp"
#include "SFML/Graphics.hpp"

const sf::Vector2f gravityForce = sf::Vector2f(0.0f, 1.0f);

const float kHorizontalMaxSpeed = 10;

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

	sf::Vector2f speed = sf::Vector2f(0, 0);
	sf::Vector2f acceleration = sf::Vector2f(0, 0);
	sf::Vector2f jumpForce;
	sf::Vector2f moveForce;

	while (window.isOpen())
	{

		// on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
		sf::Event event;

		bool isGrounded = shape.getPosition().y >= (window.getSize().y - shape.getSize().y / 2);
		jumpForce = sf::Vector2f(0.0f, 0.0f);
		moveForce = sf::Vector2f(0.0f, 0.0f);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			if (isGrounded)
			{
				jumpForce = sf::Vector2f(0.0f, -30.0f);
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			if (speed.x > (-1 * kHorizontalMaxSpeed))
			{
				moveForce = sf::Vector2f(-5.0f, 0.0f);
			}

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			if (speed.x < kHorizontalMaxSpeed)
			{
				moveForce = sf::Vector2f(5.0f, 0.0f);
			}
			
		}

		while (window.pollEvent(event))
		{
			sf::Vector2i newPos;
			switch (event.type)
			{

			case sf::Event::MouseButtonPressed:
				newPos = sf::Mouse::getPosition(window);
				speed = sf::Vector2f(0, 0);
				shape.setPosition(newPos.x, newPos.y);
				break;

			case sf::Event::Closed:
				window.close();
				break;

			default:
				break;
			}

		}



		// Graphical Region
		window.clear(sf::Color::Black);

		// acceleration is a summ of forces ---------------------------------
		acceleration = sf::Vector2f(0, 0);

		if (!isGrounded)
		{
			acceleration += gravityForce;
		}
		else
		{
			speed.y = 0;
		}

		acceleration += jumpForce;
		acceleration += moveForce;

		// Speed is a sum of acceleration -----------------------------------------
		speed += acceleration;
		if(!isGrounded)
		{
			speed.x *= 0.75f;
		}else
		{
			speed.x *= 0.95f;
		}
		

		// Position is a sum of speeds -----------------------------------------------
		shape.setPosition(shape.getPosition() + speed);

		std::cout << std::endl;
		std::cout << "is grounded ?" << isGrounded << std::endl;
		std::cout << "Acceleration : \tX=" << acceleration.x << ":\tY=" << acceleration.y << std::endl;
		std::cout << "Vitesse : \tX=" << speed.x << ":\tY=" << speed.y << std::endl;
		std::cout << "Position : \tX=" << shape.getPosition().x << ":\tY=" << shape.getPosition().y << std::endl;

		window.draw(shape);

		// Window Display
		window.display();

	}



}
