#pragma once
#include "Collider.h"

class Rigidbody
{
public:
	Rigidbody(GameObject &, bool useGravity = true);
	~Rigidbody();

	bool CheckCollision(Collider& other);
	void Update();

	GameObject & gameObject;

	vec3 velocity = vec3(0);

private:
	bool useGravity;
};

