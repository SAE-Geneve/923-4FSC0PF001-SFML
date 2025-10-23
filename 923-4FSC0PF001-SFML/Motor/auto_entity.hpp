#pragma once

#include <SFML/Graphics.hpp>
#include "motor.h"

class AutoEntity : public sf::Drawable, public sf::Transformable
{

	sf::Texture texture;

protected:
	Motor motor_;


public:
	void Load(std::string_view , sf::Vector2f , float );
	void SetPosition(sf::Vector2f);

protected:
	virtual void Move(float) = 0;
	void draw(sf::RenderTarget&, sf::RenderStates) const override;

};

