#pragma once
#include <iostream>
#include <glm.hpp>
#include <windows.h>

class Input
{
private:
	static bool lastKeys[256];
	static bool keys[256];
	static glm::vec2 deltaMousePos;
	static glm::vec2 newDeltaMousePos;

	static RAWINPUTDEVICE Rid[1];


public:
	static void initializeInput(HWND & hWnd);

	static void update(bool currentKeys[256]);

	static bool getKey(char key);
	static bool getKeyDown(char key);
	static bool getKeyUp(char key);

	static bool getMouse(char key) { std::cout << "Not Implemented Yet" << std::endl; }
	static bool getMouseDown(char key) { std::cout << "Not Implemented Yet" << std::endl; }
	static bool getMouseUp(char key) { std::cout << "Not Implemented Yet" << std::endl; }

	static void setMouseDelta(glm::vec2 pos);
	static glm::vec2 getMouseDelta();
};
