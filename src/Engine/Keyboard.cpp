#include "Keyboard.h"

using namespace engine;

Keyboard::Keyboard(void) {
}

Keyboard::~Keyboard(void) {
}

bool Keyboard::KeyDown(int key) {
	if (glfwGetKey(key)) {
		return true;
	}
	return false;
}

void KeyboardCallBack(int key, int state) 
{
	std::cout << "key : " << key << ", state: " << state << std::endl;
}

kbCallbackFunc Keyboard::CallbackFunction() {
	return KeyboardCallBack;
}