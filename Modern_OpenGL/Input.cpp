#include "Input.h"

bool Input::lastKeys[] = {};
bool Input::keys[] = {};
glm::vec2 Input::deltaMousePos;
glm::vec2 Input::newDeltaMousePos;
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

void Input::update(bool currentKeys[256])
{
	deltaMousePos = newDeltaMousePos;
	newDeltaMousePos.x = 0;
	newDeltaMousePos.y = 0;
	for (int i = 0; i < 256; i++)
	{
		lastKeys[i] = keys[i];
	}

	for (int i = 0; i < 256; i++)
	{
		keys[i] = currentKeys[i];
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

void Input::setMouseDelta(glm::vec2 pos)
{
	newDeltaMousePos = pos;
}

glm::vec2 Input::getMouseDelta()
{
	return deltaMousePos;
}
