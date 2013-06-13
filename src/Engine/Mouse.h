#pragma once

typedef void (*msCallbackFunc)(int x, int y);

#include <iostream>
#include <glm/glm.hpp>

namespace engine {

class Mouse {
public:
	Mouse(void);
	~Mouse(void);

	msCallbackFunc CallbackFunction();

	static int  GetDeltaX() { return Mouse::deltaX; }
	static int  GetDeltaY() { return Mouse::deltaY; }
	static void	UpdateDelta(int x, int y) { Mouse::deltaX = x; Mouse::deltaY = y; }

	static void SetPosition(int x, int y) { Mouse::mX = x; Mouse::mY = y; }
	static glm::vec2 GetPosition() { return glm::vec2(Mouse::mX, Mouse::mY); }
private:
	static int mX;
	static int mY;

	static int deltaX;
	static int deltaY;
};

};