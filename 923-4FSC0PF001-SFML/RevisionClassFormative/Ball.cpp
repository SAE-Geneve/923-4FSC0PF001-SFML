#include "Ball.h"

#include <iostream>
#include <random>
#include <SFML/Graphics/RenderWindow.hpp>

constexpr float kFadeRatio = 0.95f;

Ball::Ball(const sf::Vector2u size)
{
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_real_distribution<float> rnd_radius(0, 300);

	float gen_radius = std::floorf(rnd_radius(eng));
	std::uniform_real_distribution<float> rnd_x(gen_radius, size.x - gen_radius);
	std::uniform_real_distribution<float> rnd_y(gen_radius, size.y - gen_radius);

	float x = rnd_x(eng);
	float y = rnd_y(eng);

	shape_ = sf::CircleShape(gen_radius, 64);

	shape_.setOrigin(gen_radius, gen_radius);
	shape_.setPosition(x, y);
	shape_.setFillColor(kOrange);
	shape_.setOutlineColor(kWhite);
	shape_.setOutlineThickness(1);

	std::cout << "Shape generated : Radius=" << gen_radius << " X=" << x << " X=" << y << std::endl;

}

void Ball::CutTheBall(sf::Vector2f mousePos)
{
	sf::Vector2f dist = shape_.getPosition() - mousePos;
	float float_distance = std::sqrt(dist.x * dist.x + dist.y * dist.y);

	// Si on clique à une certaine distance, il se passe qq chose
	if (float_distance < shape_.getRadius())
	{
		shape_.setRadius(shape_.getRadius() / 2);
		shape_.setOrigin(shape_.getRadius(), shape_.getRadius());
	}

}

bool Ball::IsDead() const
{
	return shape_.getRadius() < 8;
}

bool Ball::FadeOut()
{
	sf::Color current_color = shape_.getFillColor();
	current_color.a *= kFadeRatio;
	shape_.setFillColor(current_color);

	return 	current_color.a > 1;

}
