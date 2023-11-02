

#include <iostream>

#include "SFML/Main.hpp"
#include "SFML/Graphics.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "The Game");

	// Basic Setup of the window
	// Vertical sync, framerate
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(30);

	sf::Sprite background;
	sf::Texture bgFile;

	bgFile.loadFromFile("data/village.png");
	background.setTexture(bgFile);
	background.setOrigin(bgFile.getSize().x / 2, bgFile.getSize().y / 2);
	background.setPosition(0, 0);

	sf::View view(sf::Vector2f(0,0), sf::Vector2f(window.getSize().x, window.getSize().y));
	window.setView(view);

	sf::CircleShape center_mark;
	center_mark.setRadius(5);
	center_mark.setOrigin(5, 5);
	center_mark.setPosition(0, 0);
	center_mark.setFillColor(sf::Color::Red);

	while (window.isOpen())
	{

		// on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
		sf::Event event;

		while (window.pollEvent(event))
		{

			switch (event.type)
			{// évènement "fermeture demandée" : on ferme la fenêtre
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::Resized:
				view.setSize(event.size.width, event.size.height);
				window.setView(view);
				break;

			case sf::Event::KeyReleased:
				if(event.key.code == sf::Keyboard::Left)
				{
					auto center = view.getCenter();

					center.x -= 15;
					view.setCenter(center);
				}

				if(event.key.code == sf::Keyboard::Right)
				{
					auto center = view.getCenter();

					center.x += 15;
					view.setCenter(center);
				}

				window.setView(view);
				break;

			case sf::Event::MouseWheelScrolled:
				if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
					// Handle vertical wheel scrolling
					std::cout << "Wheel scroll delta : " << event.mouseWheelScroll.delta << std::endl;

					if (event.mouseWheelScroll.delta != 0)
					{
						if (event.mouseWheelScroll.delta > 0)
						{
							view.zoom(0.9f);
						}
						if (event.mouseWheelScroll.delta < 0)
						{
							view.zoom(1.1f);
						}
						window.setView(view);

					}

			default:
				break;
				}

			}



			// Graphical Region
			window.clear(sf::Color::White);

			window.draw(background);
			window.draw(center_mark);

			// Window Display
			window.display();

		}

	}

}
