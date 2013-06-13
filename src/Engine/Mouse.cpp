#include "Mouse.h"

using namespace engine;

int Mouse::mX = 0;
int Mouse::mY = 0;

int Mouse::deltaX = 0;
int Mouse::deltaY = 0;

int storedX = 0;
int storedY = 0;

Mouse::Mouse(void) {

}

Mouse::~Mouse(void) {

}

void MouseCallBack(int x, int y) 
{
	Mouse::SetPosition(x, y);

	Mouse::UpdateDelta(x - storedX, y - storedY);

	storedX = x; storedY = y;

	std::cout << "x : " << Mouse::GetDeltaX() << ", y: " << Mouse::GetDeltaY() << std::endl;
}

msCallbackFunc Mouse::CallbackFunction() {
	return MouseCallBack;
}