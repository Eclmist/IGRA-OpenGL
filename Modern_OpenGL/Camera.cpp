#pragma once

#include "Camera.h"
#include <iostream>
#include <gtc/matrix_transform.inl>
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Input.h"

#define DEBUGCAMERA true

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

void Camera::UpdateCamera()
{
	view = lookAt(pos, pos + dir, up);

	if (DEBUGCAMERA)
	{
		cout << "Camera:   ";
		cout << pos.x << "," << pos.y << "," << pos.z << "   ";
		cout << dir.x << "," << dir.y << "," << dir.z << endl;
	}

	if (Input::getKey('W')) pos += dir / 100.0f;
	if (Input::getKey('S')) pos -= dir / 100.0f;
	if (Input::getKey('A')) pos += right / 100.0f;
	if (Input::getKey('D')) pos -= right / 100.0f;
	if (Input::getKey('q')) pos -= up / 100.0f;
	if (Input::getKey(' ')) pos += up / 100.0f;

	if (Input::getKey('I')) PitchCamera(1);
	if (Input::getKey('J')) YawCamera(-1);
	if (Input::getKey('K')) PitchCamera(-1);
	if (Input::getKey('L')) YawCamera(1);


	PitchCamera(-Input::getMouseDelta().y / 10);
	YawCamera(Input::getMouseDelta().x / 10);

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