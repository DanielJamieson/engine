/*
 * Scene.h
 *
 * A scene is run directly by the engine and is responsible for the creation
 * of all game objects and updating game logic.
 *
 * It is designed so that the objects and logic which is unique to each scene
 * can be seperated from the rest of the engine.
 *
 * A scene holds the entities in the scene as well as a camera to view the scene.
 *
 * To create a new scene simply extend from this scene class.
 */

#pragma once

#include <glm/glm.hpp>

//#include <glload/gl_3_2.h>
#include <vector>
#include "Entity.h"
#include "../SceneNode.h"

#include "..\Engine\Keyboard.h"
#include "..\Engine\Mouse.h"

namespace engine {

class Scene {
public:
	Scene()	{ nodeCount = 0; }
	virtual ~Scene(void)	{ }

	virtual int init()					= 0;
	virtual int UpdateGame(float delta)	= 0;
	virtual void pause()				= 0;
	virtual void resume()				= 0;
	virtual void InitialiseInput(Keyboard* keyboard, Mouse* mouse) { this->keyboard=keyboard; this->mouse=mouse; }

	unsigned int NodeCount()			{ return nodeCount; }

	void	AddEntity(Entity* entity) { 
		entities.push_back(entity); 
		nodes.push_back(entity->GetNode());
		nodeCount++;
		std::cout << "Node Count: " << nodeCount << std::endl;
	}

	std::vector<gfx::SceneNode*> GetNodes() { return nodes;}

	void SwitchControl(bool on) { hasControl = on; }

	//void	RemoveEntity(Entity* entity) { entities.pop_back(entity); }

protected:
	bool hasControl;

	Keyboard*	keyboard;
	Mouse*		mouse;

	//Camera*		camera;

	std::vector<Entity*>			entities;

	unsigned int					nodeCount;
	std::vector<gfx::SceneNode*>	nodes;
	// Matricies
	//glm::mat4* projectionMatrix;
	//glm::mat4* viewMatrix;

	//GLuint projectionUniform;
	//GLuint viewUniform;
};

};
