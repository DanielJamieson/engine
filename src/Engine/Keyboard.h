#pragma once

#include <iostream>
#include <GL/glfw.h>

typedef void (*kbCallbackFunc)(int key, int state);

namespace engine {

class Keyboard {
public:	
	Keyboard(void);
	~Keyboard(void);

	bool KeyDown(int key);

	kbCallbackFunc CallbackFunction();
};

};