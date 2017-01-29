#include "Input.h"

bool Input::lastKeys[] = {};
bool Input::keys[] = {};
bool Input::lastMouse[] = {};
bool Input::mouse[] = {};

glm::vec2 Input::deltaMousePos;
glm::vec2 Input::newDeltaMousePos;
glm::vec2 Input::currentMousePosition;
glm::vec2 Input::newMousePosition;

RAWINPUTDEVICE Input::Rid[] = {};

/* WM_INPUT DEFININITIONS */
#ifndef HID_USAGE_PAGE_GENERIC
#define HID_USAGE_PAGE_GENERIC         ((USHORT) 0x01)
#endif
#ifndef HID_USAGE_GENERIC_MOUSE
#define HID_USAGE_GENERIC_MOUSE        ((USHORT) 0x02)
#endif

void Input::initializeInput(HWND & hWnd)
{
	Rid[0].usUsagePage = HID_USAGE_PAGE_GENERIC;
	Rid[0].usUsage = HID_USAGE_GENERIC_MOUSE;
	Rid[0].dwFlags = RIDEV_INPUTSINK;
	Rid[0].hwndTarget = hWnd;
	RegisterRawInputDevices(Rid, 1, sizeof(Rid[0]));
}

void Input::update(bool currentKeys[256], bool currentMouse[3])
{
	//deltaMousePos = newMousePosition - currentMousePosition;
	currentMousePosition = newMousePosition;
	deltaMousePos = newDeltaMousePos;
	newDeltaMousePos.x = 0;
	newDeltaMousePos.y = 0;

	for (int i = 0; i < 256; i++)
	{
		lastKeys[i] = keys[i];
		keys[i] = currentKeys[i];
	}

	for (int i = 0; i < 3; i++)
	{
		lastMouse[i] = mouse[i];
		mouse[i] = currentMouse[i];
	}
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

bool Input::getMouse(int btn)
{
	return mouse[btn];
}

bool Input::getMouseDown(int btn)
{
	return !lastMouse[btn] && mouse[btn];
}

bool Input::getMouseUp(int btn)
{
	return lastMouse[btn] && !mouse[btn];
}

void Input::setMouseDelta(glm::vec2 pos)
{
	newDeltaMousePos = pos;
}

void Input::setMousePosition(glm::vec2 pos)
{
	newMousePosition = pos;
}

glm::vec2 Input::getMousePosition()
{
	return currentMousePosition;
}

glm::vec2 Input::getMouseDelta()
{
	return deltaMousePos;
}
