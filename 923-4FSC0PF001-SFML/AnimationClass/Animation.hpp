#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

constexpr float floatPeriod = 1.0f / 10.0f;

class Projectile;

class Animation
{
private:
	std::vector<sf::Texture> textures_;
	int idxTextures_ = 0;

	sf::Clock clock_;
	sf::Time totalElapsed_;

	bool isPlaying_ = true;

	sf::Texture defaultTexture_;

	void UpdateIdx();

public:
	bool Load(std::string path);
	
	void Play();
	void Pause();

	const sf::Texture* Get();
	const bool IsPlaying();

};
