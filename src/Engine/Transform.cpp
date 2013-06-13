#include "Transform.h"

Transform::Transform(void) {
	scale = glm::mat4(1.0f);
	rotation = glm::mat4(1.0f);
	translation = glm::mat4(1.0f);
}
Transform::~Transform(void) {
	delete &scale;
	delete &rotation;
	delete &translation;
}

void Transform::Scale(glm::vec3 scale_by) {
	scale = glm::scale(scale, scale_by);
}

void Transform::ResetAndScale(glm::vec3 scale_by) {
	scale = glm::mat4(1.0f);
	scale = glm::scale(scale, scale_by);
}

void Transform::Rotate(float angle, glm::vec3 axis) {
	rotation = glm::rotate(rotation, angle, axis);
}

void Transform::ResetAndRotate(float angle, glm::vec3 axis) {
	rotation = glm::mat4(1.0f);
	rotation = glm::rotate(rotation, angle, axis);
}

void Transform::Translate(glm::vec3 offset) {
	translation = glm::translate(translation, offset);
}

void Transform::ResetAndTranslate(glm::vec3 offset) {
	translation = glm::mat4(1.0f);
	translation = glm::translate(translation, offset);
}

glm::mat4 Transform::GetModelMatrix() {
	return scale * rotation * translation;
}