// SAE921-GRP4100-03a-Events.cpp : Ce fichier contient la fonction 'main'. L'ex�cution du programme commence et se termine � cet endroit.
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

        // on inspecte tous les �v�nements de la fen�tre qui ont �t� �mis depuis la pr�c�dente it�ration
        sf::Event event;
		while (window.pollEvent(event))
        {

            sf::FloatRect visibleArea(0.0f, 0.0f, event.size.width, event.size.height);

            switch (event.type)
            {

            // �v�nement "fermeture demand�e" : on ferme la fen�tre
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

// Ex�cuter le programme�: Ctrl+F5 ou menu D�boguer�> Ex�cuter sans d�bogage
// D�boguer le programme�: F5 ou menu D�boguer�> D�marrer le d�bogage

// Astuces pour bien d�marrer�: 
//   1. Utilisez la fen�tre Explorateur de solutions pour ajouter des fichiers et les g�rer.
//   2. Utilisez la fen�tre Team Explorer pour vous connecter au contr�le de code source.
//   3. Utilisez la fen�tre Sortie pour voir la sortie de la g�n�ration et d'autres messages.
//   4. Utilisez la fen�tre Liste d'erreurs pour voir les erreurs.
//   5. Acc�dez � Projet�> Ajouter un nouvel �l�ment pour cr�er des fichiers de code, ou � Projet�> Ajouter un �l�ment existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, acc�dez � Fichier�> Ouvrir�> Projet et s�lectionnez le fichier .sln.
