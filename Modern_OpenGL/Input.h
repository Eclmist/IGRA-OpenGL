#pragma once
#include <iostream>
#include <glm.hpp>
#include <windows.h>

class Input
{
private:
	static bool lastKeys[256];
	static bool keys[256];
	static bool lastMouse[3];
	static bool mouse[3];

	static glm::vec2 deltaMousePos;
	static glm::vec2 newDeltaMousePos;
	static glm::vec2 currentMousePosition;
	static glm::vec2 newMousePosition;

	static RAWINPUTDEVICE Rid[1];


public:
	static void initializeInput(HWND & hWnd);

	static void update(bool currentKeys[256], bool currentMouse[3]);

	static bool getKey(char key);
	static bool getKeyDown(char key);
	static bool getKeyUp(char key);

	static bool getMouse(int btn);
	static bool getMouseDown(int btn);
	static bool getMouseUp(int btn);

	static void setMouseDelta(glm::vec2 pos);
	static void setMousePosition(glm::vec2 pos);
	static glm::vec2 getMousePosition();
	static glm::vec2 getMouseDelta();
};