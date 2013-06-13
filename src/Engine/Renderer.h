#pragma once

#define WINDOW_TITLE "Alpha Engine"

#include <string>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Interfaces\Scene.h"
#include "Window.h"
#include "Camera.h"

enum Projection {
	ORTHOGRAPHIC, PERSPECTIVE
};

namespace engine {

using namespace gfx;

class Renderer
{
public:
	// pure virtual init makes Renderer abstract
	virtual void	RenderScene()			= 0;
	virtual void	UpdateScene(float msec) = 0;

	virtual void	SwitchToPerspective()	= 0;
	virtual void	SwitchToOrthographic()	= 0;
	virtual void	PollScene()				= 0;

	void			ChangeScene(engine::Scene* scene) {	currentScene = scene; nodeCount = 0; }

	//static Renderer&GetRenderer() { return *instance; }
protected:

	engine::Scene*		currentScene;

	bool				init;
	int					scr_width;
	int					scr_height;

	glm::mat4			projMatrix;
	glm::mat4			viewMatrix;
	glm::mat4			modelMatrix;

	unsigned int nodeCount;

	//SceneNode*		root;
	engine::Camera*		camera;

	//gfx::Shader* currentShader;

	//std::vector<gfx::SceneNode*>	transparentNodeList;
	//std::vector<gfx::SceneNode*>	nodeList;

	//static Renderer*	instance;
};

};