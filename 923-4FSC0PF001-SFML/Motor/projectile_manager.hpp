#pragma once
#include <vector>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "projectile.hpp"

class ProjectileManager : public sf::Drawable
{

	std::vector<Projectile> projectiles_;

public:
	void SpawnProjectile(sf::Vector2f);
	void Update(const sf::RenderWindow&, float dt);

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};

