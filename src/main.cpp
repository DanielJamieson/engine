
/*
 * main.cpp
 *
 * Holds the main function. Simply creates a new game 
 * and then starts it.
 */

#include <string>
#include <stdio.h>
#include <iostream>

#include "Games/Game.h"

// Main function
int main(int argc, char** argv)
{
	std::cout << "Starting game engine" << std::endl;

	Game* game = new Game();

	game->Start();

	delete game;
}
