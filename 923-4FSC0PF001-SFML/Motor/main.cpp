

#include <iostream>

#include "enemy.hpp"
#include "SFML/Main.hpp"
#include "SFML/Graphics.hpp"
#include "Motor.h"
#include "projectile.hpp"
#include "projectile_manager.hpp"
#include "starship_player.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "The Game");

	Motor motor;
	motor.SetPosition({ 0, 0 });
	motor.SetDirection({ 10,0 });
	motor.SetSpeed(750);

	sf::CircleShape circle;
	circle.setRadius(5);

	sf::Clock clock;
	//sf::Time time = clock.getElapsedTime();

	StarshipPlayer starship_player;
	starship_player.Load();

	Enemy enemy;
	enemy.Load();

	
	// Basic Setup of the window
	// Vertical sync, framerate
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(30);

	while (window.isOpen())
	{

		sf::Time deltaTime = clock.restart();


		// on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
		while (const std::optional event = window.pollEvent())
		{

			if (event->is<sf::Event::Closed>())
			{
				window.close();
			}
			else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
			{
				if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
					window.close();

			}

			

		}

		// Physics FRAME
		sf::Vector2f followMouseDirection = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)) - circle.getPosition();
		motor.SetDirection(followMouseDirection);

		sf::Vector2f position = motor.Move(deltaTime.asSeconds());
		//std::cout << position.x << ":" << position.y << "\n";
		circle.setPosition(position);

		starship_player.HandleEvent();
		starship_player.Update(window, deltaTime.asSeconds());

		enemy.Move(deltaTime.asSeconds());

		//starship_player.setPosition({ 0,0, });

		/*std::vector<StarshipPlayer> players;

		players.emplace_back();*/

		//for (const auto& p : players)
		//{
		//	p.setPosition({0, 0});
		//}

		// Graphical FRAME ---------------------------------------
		window.clear(sf::Color::Black);

		window.draw(circle);
		window.draw(starship_player);

		window.draw(enemy);

		// Window Display
		window.display();


	}



}
