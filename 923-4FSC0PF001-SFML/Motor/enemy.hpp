#pragma once
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Transformable.hpp>

#include "motor.h"

class Enemy : public sf::Drawable, public sf::Transformable
{

	sf::Texture texture;
	Motor motor_;

public:
	void Load();
	void Move(float);
	void SetPosition(sf::Vector2f);

protected:
	void draw(sf::RenderTarget&, sf::RenderStates) const override;


};

