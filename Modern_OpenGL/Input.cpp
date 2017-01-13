#include "Input.h"

bool Input::lastKeys[] = {};
bool Input::keys[] = {};
glm::vec2 Input::lastMousePos;
glm::vec2 Input::deltaMousePos;
glm::vec2 Input::currentMousePos;


void Input::updateInput(bool currentKeys[256])
{
	for (int i = 0; i < 256; i++)
	{
		lastKeys[i] = keys[i];
	}

	for (int i = 0; i < 256; i++)
	{
		keys[i] = currentKeys[i];
	}
}

void Input::updateMousePos()
{
	deltaMousePos = currentMousePos - lastMousePos;
	lastMousePos = currentMousePos;
}

bool Input::getKey(char key)
{
	return keys[key];
}

bool Input::getKeyDown(char key)
{
	return !lastKeys[key] && keys[key];
}

bool Input::getKeyUp(char key)
{
	return lastKeys[key] && !keys[key];
}

void Input::setCurrentMousePos(glm::vec2 pos)
{
	currentMousePos = pos;
}

glm::vec2 Input::getMouseDelta()
{
	return deltaMousePos;
}
