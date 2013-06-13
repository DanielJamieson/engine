#include "Game.h"


Game::Game(void) {
	Engine::Initialise();

	// Add all the game Scenes for this game
	scenes.push_back(new scenes::GameScene());

	Engine::GetEngine().SetScene(scenes[0]);

	std::cout << "set initial Scene" << std::endl;
}

Game::~Game(void) {
	Engine::Destroy();
}

void Game::Start() {
	Engine::GetEngine().run();
}

void Game::Quit() {
	Engine::GetEngine().stop();
}

void Game::MoveScene(int which) {
	Engine::GetEngine().SetScene(scenes[which]);
}