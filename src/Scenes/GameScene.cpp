#include "GameScene.h"

using namespace scenes;

GameScene::GameScene(void) {
	camera = new engine::Camera(glm::vec3(0, 0, 0), glm::vec3(0, 0, -1));

	crosshair = new game::Crosshair();
	AddEntity(crosshair);

	player = new game::Player();
	AddEntity(player);
}

GameScene::~GameScene(void) {
	delete crosshair;
	delete player;
	delete camera;
}

int GameScene::init() {
	return 0;
}

int GameScene::UpdateGame(float delta) {
	if (hasControl) {
		if (keyboard->KeyDown('W')) {
			player->MoveUp(delta);
		}
		if (keyboard->KeyDown('S')) {
			player->MoveDown(delta);
		}
		if (keyboard->KeyDown('A')) {
			player->MoveLeft(delta);
		}
		if (keyboard->KeyDown('D')) {
			player->MoveRight(delta);
		}
	}

	return 0;
}

void GameScene::pause() {
}

void GameScene::resume() {
}
