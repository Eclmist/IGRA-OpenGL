#pragma once
#include <glm.hpp>
using namespace glm;

class Camera
{
	void UpdateLookAt();
public:
	Camera();
	Camera(float fov, float aspectRatio, float nearClipping, float farClipping);
	~Camera();

	static Camera* Instance;

	void UpdateCamera();
	void PitchCamera(float deltaPitch);
	void YawCamera(float deltaYaw);
	mat4 ViewProjectionMatrix();

	void OnScreenResize(float newAspectRatio);

	vec3 pos;
	vec3 dir;

	vec3 up;
	vec3 right;

	mat4 view;
	mat4 proj;

	float32 pitch = 0;
	float32 yaw = 0;

	float nearClip, farClip;

	float fov;

};

