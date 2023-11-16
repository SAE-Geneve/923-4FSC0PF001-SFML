#pragma once
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

const sf::Color kOrange = sf::Color(235, 152, 9);
const sf::Color kWhite = sf::Color::White;

class Ball
{

	sf::CircleShape shape_;

	
public:
	explicit Ball(sf::Vector2u size);

	void CutTheBall(sf::Vector2f mousePos);
	bool FadeOut();

	sf::Color getFillColor() const { return shape_.getFillColor(); }
	bool IsDead() const;

	sf::CircleShape getShape() { return shape_; }

};

