

#include <iostream>
#include <random>

#include "SFML/Main.hpp"
#include "SFML/Graphics.hpp"

#include "Game.h"

int main()
{
	Game game;

	game.setup();

	return game.loop();

}
