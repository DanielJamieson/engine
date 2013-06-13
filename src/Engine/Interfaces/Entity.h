/*
 * Entity.h
 *
 * An entity is the base class used for all game objects.
 * Currently incomplete pending component implementation.
 */

#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include "../SceneNode.h"

namespace engine {

class Entity {
public:
	Entity(void) 			{ }
	virtual ~Entity(void)	{ }

	virtual void update(float msec) = 0;

	gfx::SceneNode*	GetNode() { return node; }
	glm::vec3	GetPosition() { return position; }
	glm::vec3	GetRotation() { return rotation; }
	
	void SetPosition(glm::vec3 position) {
		this->position = position;
	}
	void SetRotation(glm::vec3 rotation) {
		this->rotation = rotation;
	}
	void SetNode(gfx::SceneNode* n) {
		this->node = n;
	}
protected:
	std::string			shaderName;
	gfx::SceneNode*		node;
	//TODO : change it so that an entity always uses an already existing scene node in the renderer, instead of creating a new scene node/mesh!!!!

	glm::vec3			position;
	glm::vec3			rotation;
};

};
