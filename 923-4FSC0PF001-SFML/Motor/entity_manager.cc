#include "entity_manager.hpp"

#include <algorithm>
#include <iostream>

void EntityManager::Update(const sf::RenderWindow& window, float dt)
{

	erase_if(entities_, [&window](AutoEntity* p)
	{
		return p->getPosition().y < 0 || p->getPosition().y > window.getSize().y;
	}
	);

	for (auto& entity : entities_)
	{
		entity->Move(dt);
	}


}

void EntityManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (auto& projectile : entities_)
	{
		target.draw(*projectile);
	}

}
