#pragma once
#include "BoxCollider.h"

class Rigidbody
{
public:
	Rigidbody(GameObject &, bool useGravity = true);
	~Rigidbody();

	void Update();
	void AddForce(vec3);
	void ClampHorizontalVelocity(float max);
	void ClampVerticalVelocity(float max);

	GameObject & gameObject;

	vec3 velocity;

private:
	bool useGravity;

	vec3 perFrameForce;

	float maxHorizontalVel = INFINITY;
	float maxVerticalVel = INFINITY;
};

