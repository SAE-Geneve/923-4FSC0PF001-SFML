

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

	bgFile.loadFromFile("D:/5_Repos/C++/923-4FSC0PF001-SFML/923-4FSC0PF001-SFML/_Resources/sprites/village.png");
	background.setTexture(bgFile);
	background.setOrigin(bgFile.getSize().x / 2, bgFile.getSize().y / 2);
	background.setPosition(window.getSize().x / 2, window.getSize().y / 2);

	sf::View view;
	float view_size_x = 300, view_size_y = 300;
	sf::FloatRect viewFrame = sf::FloatRect(window.getSize().x / 2, window.getSize().y / 2, view_size_x, view_size_y);

	view.reset(viewFrame);
	window.setView(view);

	while (window.isOpen())
	{

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

			case sf::Event::Resized:
				window.close();
				break;

			case sf::Event::MouseWheelScrolled:
				if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
					// Handle vertical wheel scrolling
					std::cout << "Wheel scroll delta : " << event.mouseWheelScroll.delta;

					if(event.mouseWheelScroll.delta != 0)
					{
						view_size_x += 5 * event.mouseWheelScroll.delta;
						view_size_y += 5 * event.mouseWheelScroll.delta;

						viewFrame.width = view_size_x;
						viewFrame.height = view_size_y;
						view.reset(viewFrame);
						window.setView(view);
					}

			default:
				break;
				}

			}



			// Graphical Region
			window.clear(sf::Color::Black);

			window.draw(background);

			// Window Display
			window.display();

		}

	}

}
