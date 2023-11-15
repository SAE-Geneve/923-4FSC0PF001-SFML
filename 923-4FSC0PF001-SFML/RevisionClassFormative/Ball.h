#pragma once
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

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

