#include "Camera.h"

using namespace engine;

Camera::Camera(glm::vec3 position, glm::vec3 target)
{
	speed = DEFAULT_CAMERA_SPEED;
    this->position = position;
    this->target = target;
	viewMatrix = glm::mat4();
	hasControl = false;
}

Camera::~Camera(void)
{

}

glm::mat4 Camera::getMatrix(){
	glm::mat4 view = glm::lookAt(	position, 					//cameraPosition - the position of your camera, in world space
									target, 					//cameraTarget - where you want to look at, in world space
									glm::vec3(0.0, 1.0, 0.0));	//upVector - probably glm::vec3(0,1,0), but (0,-1,0) would be upside-down
	return view;
}

glm::mat4* Camera::getViewMatrix()
{
	viewMatrix = glm::mat4(1.0f);
	viewMatrix = glm::rotate(glm::mat4(1.0f), -pitch, glm::vec3(1, 0, 0));
	viewMatrix = glm::rotate(viewMatrix, -yaw, glm::vec3(0, 1, 0));
	viewMatrix *= glm::translate(glm::mat4(1.0f), -position);
	
	viewMatrix._inverse();

	viewMatrix = glm::lookAt(position, position - glm::vec3(0, 0, 1), glm::vec3(0, 1, 0));

	if (hasControl) {
	viewMatrix = glm::rotate(glm::mat4(1.0f), -pitch, glm::vec3(1, 0, 0));
	viewMatrix = glm::rotate(viewMatrix, -yaw, glm::vec3(0, 1, 0));
	viewMatrix *= glm::translate(glm::mat4(1.0f), -position);
	
	}
	//viewMatrix = glm::rotate(glm::mat4(1.0f), -pitch, glm::vec3(1, 0, 0)) *
	//				glm::rotate(glm::mat4(1.0f), -yaw, glm::vec3(0, 1, 0)) *
	//				glm::translate(glm::mat4(1.0f), -position);

	return &viewMatrix;
}

void Camera::update(float msec) {
	//pitch -= (0);
	//yaw	  -= (0);

	////pitch = min (pitch, 90.0f);
	////pitch = max (pitch, -90.0f);

	//if (yaw < 0) {
	//	yaw += 360.0f;
	//}
	//if (yaw > 360.0f) {
	//	yaw -= 360.0f;
	//}

	if (hasControl) {
		pitch -= (Mouse::GetDeltaY()*0.1);
		yaw -= (Mouse::GetDeltaX()*0.1);
		if (pitch > 90.0f) pitch = 90.0f;
		if (pitch < -90.0f) pitch = -90.0f;
		
		if( yaw < 0) {
			yaw += 360.0f;
		}
		if( yaw > 360.0f) {
			yaw -= 360.0f;
		}

		if (keyboard->KeyDown('W')) {
			this->forward(msec);
		}
		if (keyboard->KeyDown('S')) {
			this->backward(msec);
		}
		if (keyboard->KeyDown('A')) {
			this->left(msec);
		}
		if (keyboard->KeyDown('D')) {
			this->right(msec);
		}
	}
}

/** Move the camera forward relative to its current rotation (yaw) **/
void Camera::forward(float delta) {
	delta /= 1000;
	position.x = (position.x - delta * (float) sin((PI/180)*(pyr.y))  * speed);
	position.z = (position.z + delta * (float) cos((PI/180)*(pyr.y)) * speed);
	std::cout << "x: " << position.x << ", z: " << position.z << std::endl;
}

/** Move the camera backward relative to its current rotation (yaw) **/
void Camera::backward(float delta) {
	delta /= 1000;
	position.x = (position.x + delta * (float) sin((PI/180)*(pyr.y)) * speed);
	position.z = (position.z - delta * (float) cos((PI/180)*(pyr.y)) * speed);
	std::cout << "x: " << position.x << ", z: " << position.z << std::endl;
}

/** Strafe the camera left relative to its current rotation (yaw) **/
void Camera::left(float delta) {
	delta /= 1000;
	position.x = (position.x - delta * (float) sin((PI/180)*(pyr.y - 90)) * speed);
	position.z = (position.z + delta * (float) cos((PI/180)*(pyr.y - 90)) * speed);
	std::cout << "x: " << position.x << ", z: " << position.z << std::endl;
}

/** Strafe the camera right relative to its current rotation (yaw) **/
void Camera::right(float delta) {
	delta /= 1000;
	position.x = (position.x - delta * (float) sin((PI/180)*(pyr.y + 90)) * speed);
	position.z = (position.z + delta * (float) cos((PI/180)*(pyr.y + 90)) * speed);
	std::cout << "x: " << position.x << ", z: " << position.z << std::endl;
}