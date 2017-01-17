#pragma once

#include "Camera.h"
#include <iostream>
#include <gtc/matrix_transform.inl>
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "EngineCore.h"

#define DEBUGCAMERA false

using namespace glm;
using namespace std;

Camera* Camera::Instance;

void Camera::UpdateLookAt()
{
	dir.x = cos(radians(pitch)) * cos(radians(yaw));
	dir.y = sin(radians(pitch));
	dir.z = cos(radians(pitch)) * sin(radians(yaw));

	up = vec3(0.0f, 1.0f, 0.0f);
	right = normalize(cross(up, dir));

	up = cross(dir, right);
}

Camera::Camera()
{
}

Camera::Camera(float fov, float aspectRatio, float nearClipping, float farClipping)
	: fov(fov), nearClip(nearClipping), farClip(farClipping)
{
	Instance = this;

	pos = vec3(0, 0, 1);
	dir = normalize(vec3(0, 0, -1)); //does not work
	yaw = -90;

	proj = perspective(fov, aspectRatio, nearClipping, farClipping);
	view = lookAt(pos, pos + dir, up);
}

Camera::~Camera()
{
}

#define movespeed 10.0f
#define mouseSensitivity 40.0f

void Camera::UpdateCamera()
{
	view = lookAt(pos, pos + dir, up);

	if (DEBUGCAMERA)
	{
		cout << "Camera:   ";
		cout << pos.x << "," << pos.y << "," << pos.z << "   ";
		cout << dir.x << "," << dir.y << "," << dir.z << endl;
	}

	if (Input::getKey('W')) pos += dir * Time::deltaTime() * movespeed;
	if (Input::getKey('S')) pos -= dir * Time::deltaTime() * movespeed;
	if (Input::getKey('A')) pos += right * Time::deltaTime() * movespeed;
	if (Input::getKey('D')) pos -= right * Time::deltaTime() * movespeed;


	PitchCamera(-Input::getMouseDelta().y * Time::deltaTime() * mouseSensitivity);
	YawCamera(Input::getMouseDelta().x * Time::deltaTime() * mouseSensitivity);

	gluLookAt(pos.x, pos.y, pos.z,
		pos.x + dir.x, pos.y + dir.y, pos.z + dir.z,
		up.x, up.y, up.z
	);
}

void Camera::PitchCamera(float deltaPitch)
{
	pitch += deltaPitch;
	//Clamping pitch
	pitch = clamp(pitch, -89.9999f, 89.9999f);
	UpdateLookAt();
}

void Camera::YawCamera(float deltaYaw)
{
	yaw += deltaYaw;
	UpdateLookAt();
}

mat4 Camera::ViewProjectionMatrix()
{
	return proj * view;
}

void Camera::OnScreenResize(float newAspectRatio)
{
	proj = perspective(fov, newAspectRatio, nearClip, farClip);
}