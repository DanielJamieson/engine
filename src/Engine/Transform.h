#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Transform {
public:
	Transform(void);
	~Transform(void);

	void Scale(glm::vec3 scale_by);
	void ResetAndScale(glm::vec3 scale_by);
	void Rotate(float angle, glm::vec3 axis);
	void ResetAndRotate(float angle, glm::vec3 axis);
	void Translate(glm::vec3 offset);
	void ResetAndTranslate(glm::vec3 offset);

	glm::mat4 GetModelMatrix();

private:
	glm::mat4 scale;
	glm::mat4 rotation;
	glm::mat4 translation;
};