#pragma once
#include <glm/glm.hpp>
#include <iostream>
#include "Keyboard.h"
#include "Mouse.h"

namespace engine {

class Window
{
public:
	static bool Initialise(std::string title = "Alpha Engine", int sizeX = 800, int sizeY = 600, bool fullScreen = false);
	static void Destroy();
	static Window& GetWindow() {return *window;}

	void reshape(int width, int height);
	glm::vec2 GetWindowSize();

	static Keyboard*	GetKeyboard()	{ return keyboard; }
	static Mouse*		GetMouse()		{ return mouse; }
	

	bool HasInitialised() { return init; }

protected:
	static Window*		window;
	static Keyboard*	keyboard;
	static Mouse*		mouse;

	/* Current FPS as returned by getFPS() */
    int fps;
    double last_fps;

	/* Buffer for window title */
    char title_buffer[100];

	// screen dimensions
	int	width;
	int height;

	//ol				forceQuit;
	bool				init;
	bool				fullScreen;
	//bool				lockMouse;
	//bool				showMouse;
	//float				elapsedMS;
	//bool				mouseLeftWindow;

private:
	Window(std::string, int width, int height, bool fullScreen);
	~Window(void);
};

};

