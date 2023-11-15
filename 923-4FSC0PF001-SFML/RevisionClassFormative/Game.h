#pragma once
#include <SFML/Graphics.hpp>

#include "Ball.h"

class Game
{

	sf::RenderWindow window_;

	std::vector<sf::CircleShape> balls_;

	std::vector<Ball> balls_objects_;

	sf::Clock clock_;

	bool game_over_ = false;
	float cool_down_ = 3;

	const sf::Color kOrange = sf::Color(235, 152, 9);
	const sf::Color kWhite = sf::Color::White;

public:
	void setup();
	void GraphicalFrame();
	void Events();
	void SpawnABall();
	int loop();

};

