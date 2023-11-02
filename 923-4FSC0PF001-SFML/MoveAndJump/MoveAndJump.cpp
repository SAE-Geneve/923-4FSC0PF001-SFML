

#include <iostream>

#include "SFML/Main.hpp"
#include "SFML/Graphics.hpp"

const sf::Vector2f kGravityForce = sf::Vector2f(0.0f, 1.0f);

constexpr float kHorizontalMaxSpeed = 10;

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
	
	sf::Vector2f jump_force;
	sf::Vector2f move_force;

	while (window.isOpen())
	{

		// on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
		sf::Event event;

		bool is_grounded = shape.getPosition().y >= (window.getSize().y - shape.getSize().y / 2);
		jump_force = sf::Vector2f(0.0f, 0.0f);
		move_force = sf::Vector2f(0.0f, 0.0f);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			if (is_grounded)
			{
				jump_force = sf::Vector2f(0.0f, -30.0f);
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			if (speed.x > (-1 * kHorizontalMaxSpeed))
			{
				move_force = sf::Vector2f(-5.0f, 0.0f);
			}

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			if (speed.x < kHorizontalMaxSpeed)
			{
				move_force = sf::Vector2f(5.0f, 0.0f);
			}
			
		}

		while (window.pollEvent(event))
		{
			sf::Vector2i new_pos;
			switch (event.type)
			{

			case sf::Event::MouseButtonPressed:
				new_pos = sf::Mouse::getPosition(window);
				speed = sf::Vector2f(0, 0);
				shape.setPosition(new_pos.x, new_pos.y);
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

		// acceleration is a sum of forces ---------------------------------
		sf::Vector2f acceleration = sf::Vector2f(0, 0);

		if (!is_grounded)
		{
			acceleration += kGravityForce;
		}
		else
		{
			speed.y = 0;
		}

		acceleration += jump_force;
		acceleration += move_force;

		// Speed is a sum of acceleration -----------------------------------------
		speed += acceleration;
		if(!is_grounded)
		{
			speed.x *= 0.75f;
		}else
		{
			speed.x *= 0.95f;
		}
		

		// Position is a sum of speeds -----------------------------------------------
		shape.setPosition(shape.getPosition() + speed);

		std::cout << std::endl;
		std::cout << "is grounded ?" << is_grounded << std::endl;
		std::cout << "Acceleration : \tX=" << acceleration.x << ":\tY=" << acceleration.y << std::endl;
		std::cout << "Vitesse : \tX=" << speed.x << ":\tY=" << speed.y << std::endl;
		std::cout << "Position : \tX=" << shape.getPosition().x << ":\tY=" << shape.getPosition().y << std::endl;

		window.draw(shape);

		// Window Display
		window.display();

	}



}
