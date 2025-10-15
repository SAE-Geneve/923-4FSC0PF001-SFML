

#include <iostream>
#include <SFML/System/Vector2.hpp>

#include "Animation.hpp"
#include "SFML/Main.hpp"
#include "SFML/Graphics.hpp"


constexpr sf::Vector2f kCharacterSize(100, 100);

int main()
{
    sf::RenderWindow window(sf::VideoMode({1920, 1080}), "The Game");

    sf::RectangleShape character(kCharacterSize);
    Animation anim;

    // Basic Setup of the window
    // Vertical sync, framerate
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(30);


    anim.Load("data\\sprites\\character");


    while (window.isOpen())
    {

        // on inspecte tous les �v�nements de la fen�tre qui ont �t� �mis depuis la pr�c�dente it�ration
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
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyReleased>())
            {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Space)
                {
	                if (anim.IsPlaying())
	                {
                        anim.Pause();
	                }else
	                {
                        anim.Play();
	                }
                }
            }


        }

        character.setTexture(anim.Get());

        // Graphical Region
        window.clear(sf::Color::Black);

        window.draw(character);

        // Window Display
        window.display();

    }



}
