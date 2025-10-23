#include "projectile_manager.hpp"

#include <algorithm>
#include <iostream>

void ProjectileManager::SpawnProjectile(sf::Vector2f position)
{
	// Ajouter dans le vecteur
	projectiles_.emplace_back();

	// mettre à la position de spawn
	projectiles_.back().Load("data\\sprites\\laserBlue01.png", { 0, -1 }, 600);
	projectiles_.back().SetPosition(position);

}

void ProjectileManager::Update(const sf::RenderWindow& window, float dt)
{

	erase_if(projectiles_, [&window](Projectile& p)
	{
		return p.getPosition().y < 0 || p.getPosition().y > window.getSize().y;
	}
	);

	for (auto& projectile : projectiles_)
	{
		projectile.Move(dt);
	}


}

void ProjectileManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (auto& projectile : projectiles_)
	{
		target.draw(projectile);
	}

}
