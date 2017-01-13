#pragma once
#include <iostream>
#include <glm.hpp>

class Input
{
	static bool lastKeys[256];
	static bool keys[256];
	static glm::vec2 lastMousePos;
	static glm::vec2 deltaMousePos;
	static glm::vec2 currentMousePos;

public:
	static void updateInput(bool currentKeys[256]);
	static void updateMousePos();

	static bool getKey(char key);
	static bool getKeyDown(char key);
	static bool getKeyUp(char key);

	static bool getMouse(char key) { std::cout << "Not Implemented Yet" << std::endl; }
	static bool getMouseDown(char key) { std::cout << "Not Implemented Yet" << std::endl; }
	static bool getMouseUp(char key) { std::cout << "Not Implemented Yet" << std::endl; }

	static void setCurrentMousePos(glm::vec2 pos);
	static glm::vec2 getMouseDelta();
};
