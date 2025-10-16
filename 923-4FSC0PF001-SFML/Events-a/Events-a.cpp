// SAE921-GRP4100-03a-Events.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"


int main()
{

    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML First Window");
    bool drawShape = false;

    sf::CircleShape penta(50.0f, 5);
    penta.setOrigin({penta.getRadius(), penta.getRadius()});
    penta.setPosition(sf::Vector2f(window.getSize().x / 2.0f, window.getSize().y / 2.0f));

    sf::Color backgroundColor(sf::Color::Blue);


    while (window.isOpen())
    {
        window.clear(backgroundColor);

        // on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
        sf::Event event;
		while (window.pollEvent(event))
        {

            sf::FloatRect visibleArea(0.0f, 0.0f, event.size.width, event.size.height);

            switch (event.type)
            {

            // évènement "fermeture demandée" : on ferme la fenêtre
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::LostFocus:
                backgroundColor = sf::Color(50, 0, 0);
                break;

            case sf::Event::GainedFocus:
                backgroundColor = sf::Color(sf::Color::Blue);
                break;

            case sf::Event::Resized:
                window.setView(sf::View(visibleArea));
                penta.setPosition(visibleArea.width / 2.0f, visibleArea.height / 2.0f);
                break;

            default:
                break;
            }

        }

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
