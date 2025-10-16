#include "Animation.hpp"

#include <array>
#include <iostream>
#include <string>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/System/Time.hpp>

namespace sf
{
	class Texture;
}

bool Animation::Load(std::string folder)
{
	// Controle que le repertoire contient des textures
	if (std::filesystem::is_empty(folder))
	{
		return false;
	}

	// Création de la texture par défaut
	sf::Image image({100,100}, sf::Color::Magenta);
	defaultTexture_.loadFromImage(image);

	// Load every textures--------------------------------------------------------------------------------------------------
	for (const auto& file : std::filesystem::directory_iterator(folder))
	{
		std::cout << file.path() << std::endl;

		if (file.path().extension() != ".png")
		{
			std::cout << "Wrong file extension.\n";
			textures_.clear();
			return false;
		}

		textures_.emplace_back(file.path());
	}

	return true;

}

void Animation::UpdateIdx()
{
	


	sf::Time elapsed = clock_.restart();
	totalElapsed_ = totalElapsed_ + elapsed;
	std::cout << std::endl << "Counting ..... " << totalElapsed_.asSeconds() << std::endl;

	if (totalElapsed_.asSeconds() >= floatPeriod) {
		// Picking next texture
		idxTextures_++;
		// Reset time
		totalElapsed_ = totalElapsed_.Zero;
		// Switch to first frame
		if (idxTextures_ >= textures_.size())
		{
			idxTextures_ = 0;
		}
		std::cout << "New texture index : " << idxTextures_ << std::endl;
	}
}

const sf::Texture* Animation::Get()
{

	// Every 100ms, we load a new texture
	if (isPlaying_) {
		UpdateIdx();
	}

	if (textures_.size() > 0)
	{
		return &textures_[idxTextures_];
	}

	return &defaultTexture_;
}

void Animation::Play()
{
	isPlaying_ = true;
}

void Animation::Pause()
{
	isPlaying_ = false;
}

const bool Animation::IsPlaying()
{
	return isPlaying_;
}




