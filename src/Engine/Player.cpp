#include "Player.h"

using namespace game;

Player::Player(void) {
	gfx::Mesh *m;
	m = gfx::Mesh::GenerateSquare();
	m->LoadTexture("player.png");
	m->GetTexture()->ToggleFiltering();
	
	animState = STANDING;

	standingCoords = new glm::vec2[4];
	standingCoords[0] = glm::vec2(1.0, 1.0);
	standingCoords[1] = glm::vec2(1.0, 0.77);
	standingCoords[2] = glm::vec2(0.5, 0.77);
	standingCoords[3] = glm::vec2(0.5, 1.0);
	m->ModifyTextureCoords(standingCoords);


	node = new gfx::SceneNode(m);
	node->Scale(glm::vec3(0.3, 0.25, 1.0));
}

Player::~Player(void) {
}

void Player::update(float msec) {
	switch (animState) {
	case ARMED:
		break;
	case FORWARD1:
		break;
	case FORWARD2:
		break;
	case BACKWARD1:
		break;
	case BACKWARD2:
		break;
	default:
		//GetNode()->GetMesh()->ModifyTextureCoords(standingCoords);
		break;
	}
}

void Player::MoveUp(float delta) {
	float amount = PLAYER_SPEED * (delta / 100);
	node->Translate(glm::vec3(0, amount, 0));
}
void Player::MoveDown(float delta) {
	float amount = PLAYER_SPEED * (delta / 100);
	node->Translate(glm::vec3(0, -amount, 0));
}
void Player::MoveLeft(float delta) {
	float amount = PLAYER_SPEED * (delta / 100);
	node->Translate(glm::vec3(-amount, 0, 0));
}
void Player::MoveRight(float delta) {
	float amount = PLAYER_SPEED * (delta / 100);
	node->Translate(glm::vec3(amount, 0, 0));
}
void Player::Turn(float delta) {
}