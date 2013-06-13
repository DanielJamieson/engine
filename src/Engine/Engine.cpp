#include "Engine.h"
#include <stdio.h>

#define PI 3.14159265

using namespace engine;

Engine* Engine::engine;

/* Screen dimensions */
GLuint scr_width = 1440;
GLuint scr_height = 900;

float speed = 0.1f;

/* Pointer to our viewports array so that the mouse callback function
 * can access our viewports
 */
Camera *callbackCamera;

Engine::Engine() {
	
	//TODO : create a window when the engine starts and set fps values
	//fps = 0;
	//last_fps = 0;
	running = true;
	scene = NULL;

	Window::Initialise();
	OGLRenderer::Initialise(Window::GetWindow());
	//TODO : initialise renderer and physics system
	//camera = new Camera(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0));
	//renderer = new OGLRenderer(Window::GetWindow());
	init = true;
}

Engine::~Engine() {

	Window::Destroy();
	OGLRenderer::Destroy();
    delete scene;
}
void Engine::UpdateEngine(float msec){
	// Update game logic first
	scene->UpdateGame(msec);

	// Then update scene
	OGLRenderer::GetRenderer().UpdateScene(msec);

	// Then render scene
	OGLRenderer::GetRenderer().RenderScene();
}

void Engine::run() {

	double curr_frame = glfwGetTime();
	double last_frame = curr_frame;
	float delta = 0;

	//TODO : move to window/renderer
	//last_fps = glfwGetTime();

	//Main loop
	while(running) {
		
		curr_frame = glfwGetTime() * 1000;
		delta = curr_frame - last_frame;
		last_frame = curr_frame;

		UpdateEngine(delta);
		//updateFPS();

		if( glfwGetKey(GLFW_KEY_ESC) || !glfwGetWindowParam(GLFW_OPENED) )
			break;
		//GLenum error;
		//while((error = glGetError()) != GL_NO_ERROR) {
		//	fprintf(stderr, "GL Error: 0x%x\n", error);
		//}
	}

	glfwTerminate();
}

/*void Engine::input()
{
	if (Window::GetWindow().GetKeyboard()->KeyDown('0')) {
		ToggleControl();
	}
	//state->keyInput();
}*/

/**
 * Don't do this before init!
 */

void Engine::SetScene(Scene* newScene) {

    // store and init the new scene
    this->scene = newScene;
	this->scene->InitialiseInput(Window::GetWindow().GetKeyboard(),Window::GetWindow().GetMouse());
	this->scene->init();

	OGLRenderer::GetRenderer().ChangeScene(scene);
	control = STATE_CONTROL;
    //this->state->setProjectionMatrix(&projection);
}

void Engine::ToggleControl() {
	/*if (control == STATE_CONTROL) {
		scene->SwitchControl(false);
		camera->SwitchControl(true);
		control == CAMERA_CONTROL;
	}
	else if (control == CAMERA_CONTROL) {
		scene->SwitchControl(true);
		camera->SwitchControl(false);
		control == STATE_CONTROL;
	}*/
}

void Engine::stop() {
	running = false;
}


