#include "Game.h"

#include <iostream>
#include <random>

constexpr float kCoolDownDecrease = 0.2f;
//constexpr float kFadeRatio = 0.95f;

void Game::setup()
{

	window_.create(sf::VideoMode(800, 600), "The Game");

	// Basic Setup of the window
	// Vertical sync, framerate
	window_.setVerticalSyncEnabled(true);
	window_.setFramerateLimit(30);

}


int Game::loop()
{
	while (window_.isOpen())
	{
		if (game_over_)
		{
			std::cout << "=== === === === === === === GAME OVER === === === === === === ===" << std::endl;
			continue;
		}

		SpawnABall();

		Events();

		GraphicalFrame();

	}

	return EXIT_SUCCESS;
}

void Game::SpawnABall()
{

	if (clock_.getElapsedTime().asSeconds() > cool_down_)
	{
		/* Non Factorized Version

		std::cout << "New ball ?????" << std::endl;

		std::random_device rd;
		std::mt19937 eng(rd());
		std::uniform_real_distribution<float> rnd_radius(0, 300);

		float gen_radius = std::floorf(rnd_radius(eng));
		std::uniform_real_distribution<float> rnd_x(gen_radius, window_.getSize().x - gen_radius);
		std::uniform_real_distribution<float> rnd_y(gen_radius, window_.getSize().y - gen_radius);

		float x = rnd_x(eng);
		float y = rnd_y(eng);

		balls_.emplace_back(gen_radius, 64);

		balls_.back().setOrigin(gen_radius, gen_radius);
		balls_.back().setPosition(x, y);
		balls_.back().setFillColor(kOrange);
		balls_.back().setOutlineColor(kWhite);
		balls_.back().setOutlineThickness(1);
		*/

		balls_objects_.emplace_back(window_.getSize());
		clock_.restart();

	}
}

void Game::Events()
{
	// on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
	sf::Event event;

	while (window_.pollEvent(event))
	{

		switch (event.type)
		{

		case sf::Event::MouseButtonReleased:
		{
			sf::Vector2f mousePos = { (float)event.mouseButton.x, (float)event.mouseButton.y };
			/* non factorized version
			for (auto ball_it = balls_.begin(); ball_it != balls_.end(); ++ball_it)
			{
				//sf::Vector2f mem_position = b.getPosition();
				sf::Vector2f dist = ball_it->getPosition() - mousePos;
				float truc = std::sqrt(dist.x * dist.x + dist.y * dist.y);

				// Si on clique à une certaine distance, il se passe qq chose
				if (truc < ball_it->getRadius())
				{
					ball_it->setRadius(ball_it->getRadius() / 2);
					ball_it->setOrigin(ball_it->getRadius(), ball_it->getRadius());

					if (ball_it->getRadius() < 8)
					{
						balls_.erase(ball_it);
						//cool_down_ -= kCoolDownDecrease;
					}

					break;
				}
			}
			*/

			for (auto ball_it = balls_objects_.begin(); ball_it != balls_objects_.end(); ++ball_it)
			{
				ball_it->CutTheBall(mousePos);
				if (ball_it->IsDead())
				{
					cool_down_ -= kCoolDownDecrease;
					break;
				}

			}

			// find the element and remove
			std::_Erase_remove_if(balls_objects_, [](Ball& a) {return a.IsDead(); });

		}
		break;

		// évènement "fermeture demandée" : on ferme la fenêtre
		case sf::Event::Closed:
			window_.close();
			break;

		default:
			break;
		}

	}
}

void Game::GraphicalFrame()
{
	// Graphical Region
	window_.clear(sf::Color::Black);

	/* Non Factorized Version
	for (auto& b : balls_)
	{
		// Fade out ----------------------------------------------------
		sf::Color current_color = b.getFillColor();
		current_color.a *= kFadeRatio;
		b.setFillColor(current_color);

		if (current_color.a <= 1)
		{
			// Game Over ----------------------------------------------
			game_over_ = true;
		}

		window_.draw(b);
	}
	*/

	for (auto& b : balls_objects_)
	{
		// Fade out ----------------------------------------------------
		if (b.FadeOut() == false)
		{
			// Game Over ----------------------------------------------
			game_over_ = true;
		}

		window_.draw(b.getShape());
	}

	//std::cout << "Nb balls : " << balls.size() << std::endl;

	// Window Display
	window_.display();

}




