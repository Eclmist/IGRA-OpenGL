#pragma once
#include "BoxCollider.h"

class Rigidbody
{
public:
	Rigidbody(GameObject &, bool useGravity = true);
	~Rigidbody();

	void Update();

	GameObject & gameObject;

	vec3 velocity;

private:
	bool useGravity;
};

