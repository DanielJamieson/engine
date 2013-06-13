#include "Window.h"

using namespace engine;

Window* Window::window;
Keyboard*Window::keyboard	= NULL;
Mouse*Window::mouse			= NULL;

bool Window::Initialise(std::string title, int sizeX, int sizeY, bool fullScreen)	{
	
	window = new Window(title, sizeX, sizeY, fullScreen);
	if(!window->HasInitialised()) {
		return false;
	}
	return true;
}

void Window::Destroy() {
	delete window;
	window = NULL;
}

Window::Window(std::string, int width, int height, bool fullScreen) {

	this->width = width;
	this->height = height;
	this->fullScreen = fullScreen;

	if (!keyboard)
		keyboard = new Keyboard();
	if (!mouse)
		mouse = new Mouse();
	
	init = true;
}

Window::~Window(void)
{
	delete keyboard;	keyboard = NULL;
	delete mouse;		mouse = NULL;
}

void Window::reshape(int width, int height) {
	window->width = width;
	window->height = height;
	//TODO : reshape renderer
}

glm::vec2 Window::GetWindowSize() {
	return glm::vec2(width, height);
}