#pragma once

#include <SFML/Graphics.hpp>
#include "motor.h"

class AutoEntity : public sf::Drawable, public sf::Transformable
{

	sf::Texture texture;
	
protected:
	Motor motor_;
	void Load(std::string_view, sf::Vector2f, float);


public:
	void SetPosition(sf::Vector2f);
	virtual void Move(float) = 0;
	virtual void Load() = 0;

protected:
	void draw(sf::RenderTarget&, sf::RenderStates) const override;

};

