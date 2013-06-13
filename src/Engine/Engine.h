/*
 * Engine.h
 *
 * Main engine class. The engine is initialised by a game class and then
 * the engine is responsible for initialising it's components: the Window
 * with the OGL context, the rendering system and the (yet to be implemented)
 * physics system.
 * 
 * A game also passes a number of scenes to the engine. An engine can run one
 * scene at a time.
 */

#pragma once

#define GLFW_INCLUDE_GL3
#define DEBUG

#include "OGLRenderer.h"

#include <cstdio>
#include <stdlib.h>
#include <stdexcept>
#include <iostream>
#include "Interfaces/Scene.h"

enum InputControl {
	CAMERA_CONTROL, STATE_CONTROL
};

namespace engine {

class Engine {
public:
	void UpdateEngine(float msec);

	void run();
	void stop();
	
	void	SetScene(Scene* scene);

	void	ToggleControl();

	static bool Initialise() {
		engine = new Engine();
		return engine->HasInitialised();
	}

	static void Destroy() {
		Window::Destroy();
		OGLRenderer::Destroy();
		delete engine;
	}

	bool HasInitialised() { return init; }
	
	//TODO : not sure if needed
	static Engine& GetEngine() { return *engine; }

private:
	static Engine* engine;

	bool init;

    bool running;

    /* State pointer */
    Scene* scene;

	InputControl control;

	Engine();
	virtual ~Engine();
};

};
