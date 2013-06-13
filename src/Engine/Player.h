#pragma once

#include "Interfaces/Entity.h"
#include "Mesh.h"

#define PLAYER_SPEED 0.4

enum AnimationState {
	STANDING, ARMED, FORWARD1, FORWARD2, BACKWARD1, BACKWARD2
};

namespace game {

class Player : public engine::Entity {
public:
	Player(void);
	~Player(void);

	virtual void update(float msec);

	void MoveUp(float msec);
	void MoveDown(float msec);
	void MoveLeft(float msec);
	void MoveRight(float msec);

	void Turn(float amount);
private:
	glm::vec2* standingCoords;

	AnimationState animState;
};

};