/*
 * Game.h
 *
 * Main game class. This class is responsible for starting the engine, and
 * also for creating scenes to pass to the engine.
 */

#pragma once

#include <iostream>
#include "../Engine/Engine.h"
#include "../Scenes/GameScene.h"

using namespace engine;

class Game
{
public:
	Game(void);
	~Game(void);

	void Start();
	void Quit();

	void MoveScene(int which);

private:

	std::vector<Scene*> scenes;
};