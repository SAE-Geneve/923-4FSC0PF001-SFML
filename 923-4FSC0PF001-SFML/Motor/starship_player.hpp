#pragma once
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Window/Event.hpp>

#include "entity_manager.hpp"
#include "motor.h"

class StarshipPlayer : public sf::Drawable, public sf::Transformable
{

	sf::Texture texture;
	Motor motor_;

	ProjectileManager projectiles;


public:
	void Load();
	void Update(sf::RenderWindow&, float);
	void HandleEvent();

protected:
	void draw(sf::RenderTarget&, sf::RenderStates) const override;

};

