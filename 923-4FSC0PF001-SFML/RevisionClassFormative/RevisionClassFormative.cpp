

#include <iostream>
#include <random>

#include "SFML/Main.hpp"
#include "SFML/Graphics.hpp"




int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "The Game");

	// Basic Setup of the window
	// Vertical sync, framerate
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(30);


	std::vector<sf::CircleShape> balls;
	sf::Clock clock;
	bool bGameOver = false;

	float kCoolDown = 3;
	constexpr float kCoolDownDecrease = 0.2;
	constexpr float kFadeRatio = 0.95f;
	constexpr int kCuttableDistance = 25 * 25;


	const sf::Color kOrange = sf::Color(235, 152, 9);
	const sf::Color kWhite = sf::Color::White;

	while (window.isOpen())
	{
		if(bGameOver)
		{
			std::cout << "=== === === === === === === GAME OVER === === === === === === ===" << std::endl;
			continue;
		}


		if (clock.getElapsedTime().asSeconds() > kCoolDown)
		{

			std::random_device rd;
			std::mt19937 eng(rd());
			std::uniform_real_distribution<float> rnd_radius(0, 300);

			float gen_radius = std::floorf(rnd_radius(eng));
			std::uniform_real_distribution<float> rnd_x(gen_radius, window.getSize().x - gen_radius);
			std::uniform_real_distribution<float> rnd_y(gen_radius, window.getSize().y - gen_radius);

			float x = rnd_x(eng);
			float y = rnd_y(eng);

			balls.emplace_back(gen_radius, 64);

			balls.back().setOrigin(gen_radius, gen_radius);
			balls.back().setPosition(x, y);
			balls.back().setFillColor(kOrange);
			balls.back().setOutlineColor(kWhite);
			balls.back().setOutlineThickness(1);

			std::cout << "Shape generated : Radius=" << gen_radius << " X=" << x << " X=" << y << std::endl;

			clock.restart();
		}


		// on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
		sf::Event event;

		while (window.pollEvent(event))
		{

			switch (event.type)
			{


			case sf::Event::MouseButtonReleased:
			{
				sf::Vector2f mousePos = { (float)event.mouseButton.x, (float)event.mouseButton.y };

					for(auto ball_it = balls.begin(); ball_it != balls.end(); ++ball_it)
					{
						//sf::Vector2f mem_position = b.getPosition();
						sf::Vector2f dist = ball_it->getPosition() - mousePos;
						if(std::sqrt(dist.x*dist.x + dist.y*dist.y) < ball_it->getRadius())
						{
							ball_it->setRadius(ball_it->getRadius() / 2);
							ball_it->setOrigin(ball_it->getRadius(), ball_it->getRadius());

							if(ball_it->getRadius() < 8)
							{
								balls.erase(ball_it);
								kCoolDown -= kCoolDownDecrease;
							}

							break;
						}
					}

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

		for (auto& b : balls)
		{
			// Fade out ----------------------------------------------------
			sf::Color current_color = b.getFillColor();
			current_color.a *= kFadeRatio;
			b.setFillColor(current_color);

			if (current_color.a == 0)
			{
				// Game Over ----------------------------------------------
				bGameOver = true;
			}

			window.draw(b);
		}

		std::cout << "Nb balls : " << balls.size() << std::endl;

		// Window Display
		window.display();

	}



}
