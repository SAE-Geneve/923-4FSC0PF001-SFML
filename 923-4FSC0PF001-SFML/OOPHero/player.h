#pragma once

#include <SFML/Graphics.hpp>

class Player : public sf::Drawable, public sf::Transformable
{

	sf::Sprite sprite_;
	sf::Sprite sword_;

	sf::Texture up_;
	sf::Texture down_;
	sf::Texture left_;
	sf::Texture right_;
	sf::Texture sword_file_;

	const float speed_ = 8.0f;
	const float sprint_speed_ = 13.0f;
	const float sprint_value_ = 2.0f;

	bool sword_equiped_ = false;
	bool is_sprinting_ = false;

public:
	Player() = default;
	~Player() override = default;

	void Load()
	{
		setPosition(400, 400);

		// Loading a file as texture
		up_.loadFromFile("data/sprites/ZeldaUp.png");
		down_.loadFromFile("data/sprites/ZeldaDown.png");
		left_.loadFromFile("data/sprites/ZeldaLeft.png");
		right_.loadFromFile("data/sprites/ZeldaRight.png");

		// Using a sprite
		// https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Sprite.php
		sprite_.setTexture(up_);
		sprite_.setOrigin(up_.getSize().x / 2.0f, up_.getSize().y / 2.0f);

		// Using another sprite
		// https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Sprite.php
		sword_file_.loadFromFile("data/sprites/sword.png");
		sword_.setTexture(sword_file_);
		sword_.setOrigin(sword_file_.getSize().x / 2.0f, sword_file_.getSize().y / 2.0f);
		
	}

	void Move(sf::Vector2f direction_)
	{

		if (direction_.y < 0)
		{
			sprite_.setTexture(up_);
		}
		if(direction_.y > 0)
		{
			sprite_.setTexture(down_);
		}

		if(direction_.x < 0) {
			sprite_.setTexture(left_);
		}

		if(direction_.x > 0) {
			sprite_.setTexture(right_);
		}


		// Move the sprite
		sf::Vector2f position = this->getPosition();
		if(is_sprinting_)
		{
			position += direction_ * sprint_speed_;
			is_sprinting_ = false;
		}else
		{
			position += direction_ * speed_;
		}
		
		this->setPosition(position);
	}

	void Sprint()
	{
		is_sprinting_ = true;
	}

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override
	{

		states.transform = getTransform();

		// You can draw other high-level objects
		target.draw(sprite_, states);

		if(sword_equiped_)
		{
			target.draw(sword_, states);
		}
		
	}
};

