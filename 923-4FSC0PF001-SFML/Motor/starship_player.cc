#include "starship_player.hpp"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>

void StarshipPlayer::Load()
{
	texture.loadFromFile("data\\sprites\\playerShip3_red.png");

	motor_.SetPosition({ 400, 0 });
	motor_.SetDirection({ 0, 1 });
	motor_.SetSpeed(600);

}

void StarshipPlayer::Update(sf::RenderWindow& window, float dt)
{
	setPosition(motor_.Move(dt));

	projectiles.Update(window, dt);

}

void StarshipPlayer::HandleEvent()
{

	sf::Vector2f direction = {0,0};

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Down))
	{
		direction.y = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Up))
	{
		direction.y = -1;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Left))
	{
		direction.x = -1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Right)) {
		direction.x = 1;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Space)){
		projectiles.SpawnEntity(getPosition());
	}

	motor_.SetDirection(direction);
}

void StarshipPlayer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::Sprite sprite(texture);
	states.transform *= getTransform();

	target.draw(sprite, states);
	target.draw(projectiles);

}



