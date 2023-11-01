// SAE921-GRP4100-03a-Events.cpp : Ce fichier contient la fonction 'main'. L'ex�cution du programme commence et se termine � cet endroit.
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
        // Option B: avec un petit d�calage pour faire joli
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

// Ex�cuter le programme�: Ctrl+F5 ou menu D�boguer�> Ex�cuter sans d�bogage
// D�boguer le programme�: F5 ou menu D�boguer�> D�marrer le d�bogage

// Astuces pour bien d�marrer�: 
//   1. Utilisez la fen�tre Explorateur de solutions pour ajouter des fichiers et les g�rer.
//   2. Utilisez la fen�tre Team Explorer pour vous connecter au contr�le de code source.
//   3. Utilisez la fen�tre Sortie pour voir la sortie de la g�n�ration et d'autres messages.
//   4. Utilisez la fen�tre Liste d'erreurs pour voir les erreurs.
//   5. Acc�dez � Projet�> Ajouter un nouvel �l�ment pour cr�er des fichiers de code, ou � Projet�> Ajouter un �l�ment existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, acc�dez � Fichier�> Ouvrir�> Projet et s�lectionnez le fichier .sln.
