// AnimationClass.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <iostream>

#include "SFML/Main.hpp"
#include "SFML/Graphics.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "The Game");

    // Basic Setup of the window
    // Vertical sync, framerate
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(30);

    while (window.isOpen())
    {

        // on inspecte tous les �v�nements de la fen�tre qui ont �t� �mis depuis la pr�c�dente it�ration
        sf::Event event;

        while (window.pollEvent(event))
        {

            switch (event.type)
            {

                // �v�nement "fermeture demand�e" : on ferme la fen�tre
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

        //window.draw(something to draw);

        // Window Display
        window.display();

    }



}