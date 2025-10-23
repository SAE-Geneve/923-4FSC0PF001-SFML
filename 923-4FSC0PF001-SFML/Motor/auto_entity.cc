#include "auto_entity.hpp"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>

void AutoEntity::Load(std::string_view pathFile, sf::Vector2f direction, float speed)
{
	texture.loadFromFile(pathFile);

	//motor_.SetPosition({ 400, 600 });
	motor_.SetDirection(direction);
	motor_.SetSpeed(speed);

}

void AutoEntity::SetPosition(sf::Vector2f position)
{
	motor_.SetPosition(position);
}

void AutoEntity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::Sprite sprite(texture);
	states.transform *= getTransform();

	target.draw(sprite, states);
}



