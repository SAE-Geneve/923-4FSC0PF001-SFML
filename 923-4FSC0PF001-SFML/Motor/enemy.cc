#include "enemy.hpp"

#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>

void Enemy::Load()
{
	texture.loadFromFile("data\\sprites\\enemyBlack4.png");

	//motor_.SetPosition({ 400, 600 });
	motor_.SetDirection({ 0, 1 });
	motor_.SetSpeed(300);
}

void Enemy::Move(float dt)
{
	setPosition(motor_.Move(dt));
}

void Enemy::SetPosition(sf::Vector2f position)
{
	motor_.SetPosition(position);
}

void Enemy::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::Sprite sprite(texture);
	states.transform *= getTransform();

	target.draw(sprite, states);
}


