// SAE921-GPR4100-SFML-03d-Events.cpp : Ce fichier contient la fonction 'main'. L'ex�cution du programme commence et se termine � cet endroit.
//

#include <iostream>

#include "SFML/Main.hpp"
#include "SFML/Graphics.hpp"


static const int JOYSTICK_ID = 0;
static const float JOYSTICK_DEAD_ZONE = 6.f;
constexpr int kTilemap_size = 24;
constexpr int kTilemap_offset = 1;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML First Window");

	// Basic Setup of the window
	// Vertical sync, framerate
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(30);

	// Setting up thh events
	window.setKeyRepeatEnabled(true);
	const auto winCenter = window.getSize();

	// Loading a file as texture
	sf::Texture up;
	sf::Texture down;
	sf::Texture left;
	sf::Texture right;
	up.loadFromFile("data/sprites/ZeldaUp.png");
	down.loadFromFile("data/sprites/ZeldaDown.png");
	left.loadFromFile("data/sprites/ZeldaLeft.png");
	right.loadFromFile("data/sprites/ZeldaRight.png");

	sf::Texture	tilemap;
	tilemap.loadFromFile("data/sprites/KenneyPlatformer_Character.png", sf::IntRect(6 * (kTilemap_size + kTilemap_offset), 1 * (kTilemap_size + kTilemap_offset), kTilemap_size, kTilemap_size));

	// Using a sprite
	// https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Sprite.php
	sf::Sprite tilemapSprite;
	tilemapSprite.setTexture(tilemap);
	tilemapSprite.setOrigin(tilemap.getSize().x / 2.0f, tilemap.getSize().y / 2.0f);
	tilemapSprite.setPosition(winCenter.x / 2.0f, winCenter.y / 2.0f);
	

	// Using a sprite
	// https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Sprite.php
	sf::Sprite sprite;
	sprite.setTexture(up);
	sprite.setOrigin(up.getSize().x / 2.0f, up.getSize().y / 2.0f);
	sprite.setPosition(winCenter.x / 2.0f, winCenter.y / 2.0f);
	sprite.setScale(1.5f, 1.5f);

	sf::Color backgroundColor(sf::Color::Black);

	float axisYPosition = 0.f;
	float axisXPosition = 0.f;

	while (window.isOpen())
	{

		sf::Event event;
		constexpr float speed = 8.0f;

		while (window.pollEvent(event))
		{

			switch (event.type)
			{

				// �v�nement "fermeture demand�e" : on ferme la fen�tre
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::JoystickMoved:
				std::cout << "Joystic moved " << event.joystickMove.joystickId << " : " << event.joystickMove.axis << " : " << event.joystickMove.position << std::endl;

				if (event.joystickMove.joystickId == JOYSTICK_ID) {
					switch (event.joystickMove.axis)
					{
					case sf::Joystick::Y:
						axisYPosition = event.joystickMove.position;
						if (std::abs(axisYPosition) <= JOYSTICK_DEAD_ZONE)
							axisYPosition = 0.f;
						break;

					case sf::Joystick::X:
						axisXPosition = event.joystickMove.position;
						if (std::abs(axisXPosition) <= JOYSTICK_DEAD_ZONE)
							axisXPosition = 0.f;
						break;

					case sf::Joystick::Z:
					case sf::Joystick::R:
					case sf::Joystick::U:
					case sf::Joystick::V:
					case sf::Joystick::PovX:
					case sf::Joystick::PovY:
					default:
						break;

					}
				}

				break;
			}

		}

		// Move the sprite
		sf::Vector2f position = sprite.getPosition();

		// Change texture
		if (std::abs(axisYPosition) > std::abs(axisXPosition))
		{
			if (axisYPosition < 0) {
				sprite.setTexture(up);
			}
			else if (axisYPosition > 0) {
				sprite.setTexture(down);
			}
			position.y += (axisYPosition / 100.f) * speed;

		}
		else {
			if (axisXPosition < 0) {
				sprite.setTexture(left);
			}
			else if (axisXPosition > 0) {
				sprite.setTexture(right);
			}
			position.x += (axisXPosition / 100.f) * speed;

		}
		sprite.setPosition(position);

		// Window Display
		window.clear(backgroundColor);
		//window.draw(sprite);
		window.draw(tilemapSprite);
		window.display();

	}

}
