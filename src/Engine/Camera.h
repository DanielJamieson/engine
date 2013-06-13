/*
 * Camera.h
 *
 * A camera is used to generate a view matrix used by the renderer
 *  
 */

#pragma once

#include "Interfaces/Entity.h"
#include "Keyboard.h"
#include "Mouse.h"

namespace engine {
#define PI 3.14159265
#define DEFAULT_CAMERA_SPEED 0.5

class Camera: public Entity {
public:
	Camera(glm::vec3 _pos, glm::vec3 _look);
	virtual ~Camera(void);

	glm::mat4* getViewMatrix();

	virtual void update(float msec);

	void forward(float delta);
	void backward(float delta);
	void left(float delta);
	void right(float delta);

	/* Changed setCamPos(glm::vec3 pos, glm::vec3 _look) to setCam, then
	* added setCamPos and setCamLook in order to seperate the functionality -DJ */
	void MoveCamera(glm::vec3 position, glm::vec3 target) {
		this->position = position;
		this->target = target;
	}

	glm::vec3 GetTarget() {
		return target;
	}
	glm::mat4 getMatrix();

	void ChangePitch(float delta) {
		pitch += delta;
	}
	void ChangeYaw(float delta) {
		yaw += delta;
	}

	void SwitchControl(bool on) { hasControl = on; }
private:
	bool hasControl;

	Keyboard*	keyboard;
	Mouse*		mouse;

	glm::mat4 viewMatrix;
	float speed;

	float pitch;
	float yaw;

	glm::vec3 target;
	glm::vec3 pyr; //pitch, yaw, roll. roll is unused
};

};
