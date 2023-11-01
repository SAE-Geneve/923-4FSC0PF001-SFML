// SAE921-GRP4100-03a-Events.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <cmath>
#include <iostream>


#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"


int main()
{

    // Setup
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML First Window");
    window.setFramerateLimit(30);

    sf::CircleShape penta(50.0f, 5);
    penta.setOrigin(penta.getRadius() / 2.0f, penta.getRadius() / 2.0f);
    penta.setPosition(sf::Vector2f(window.getSize().x / 2.0f, window.getSize().y / 2.0f));

    // FOLLOW THE MOUSE
    sf::Vector2f position = penta.getPosition();

    // CHANGE THE SHAPE
    int newPointCount;

    sf::Color backgroundColor(sf::Color::Red);

    while (window.isOpen())
    {
        window.clear(backgroundColor);


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

            case sf::Event::MouseMoved:
                position.x = (float)event.mouseMove.x;
                position.y = (float)event.mouseMove.y;
                // Option A : Follow the mouse
                //penta.setPosition(position);
                break;

            case sf::Event::MouseButtonReleased:
                newPointCount = 3 + 5 * ((rand() % 100) / 100.0f);
                penta.setPointCount(newPointCount);
                break;

            default:
                break;
            }

        }
        // -------------------------------------------------------------------------------------------------
        // Option B: avec un petit décalage pour faire joli
        float smoothRatio = 0.9f;
        penta.setPosition(
            smoothRatio * penta.getPosition().x + (1.0f - smoothRatio) * position.x,
            smoothRatio * penta.getPosition().y + (1.0f - smoothRatio) * position.y);

        window.draw(penta);

        // effacement les tampons de couleur/profondeur 
        window.display();

    }

    return EXIT_SUCCESS;

}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
